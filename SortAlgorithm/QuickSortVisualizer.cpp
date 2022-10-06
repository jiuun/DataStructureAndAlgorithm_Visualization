#include "QuickSortVisualizer.h"

#include <cassert>
#include <iostream>

using namespace std;

namespace sort
{
	void QuickSortVisualizer::VisualizeSorting(vector<int>& nums)
	{
		vector<Node> datas;
		datas.reserve(nums.size());


		for (size_t i = 0; i < nums.size(); ++i)
		{
			datas.push_back(Node(nums[i], eColorType::QUICKSORT_DEFAULT));
		}
		PrintData(datas);

		visualizeSortingRecursive(datas, 0, static_cast<int>(datas.size() - 1));
	}

	void QuickSortVisualizer::visualizeSortingRecursive(vector<Node>& datas, int leftIndex, int rightIndex)
	{
		if (leftIndex >= rightIndex)
		{
			return;
		}

		initNodes(datas, leftIndex, rightIndex);
		
		int pivotIndex = rightIndex;
		int currLeftIndex = leftIndex - 1;

		datas[pivotIndex].SetColorType(eColorType::QUICKSORT_RIGHT);
		datas[currLeftIndex + 1].SetColorType(eColorType::QUICKSORT_LEFT);


		for (int i = leftIndex; i < rightIndex; ++i)
		{
			datas[i].OnCurrnetIndex();
			PrintData(datas);

			if (datas[i].GetData() < datas[pivotIndex].GetData())
			{
				++currLeftIndex;
				moveLeft(datas, currLeftIndex);

				PrintData(datas);

				swapInt(datas[currLeftIndex], datas[i]);

				if (currLeftIndex != i)
				{
					PrintData(datas);
				}
			}
			else
			{
				PrintData(datas);
			}

			datas[i].OffCurrnetIndex();
		}


		
		pivotIndex = currLeftIndex + 1;

		swapInt(datas[pivotIndex], datas[rightIndex]);
		datas[pivotIndex].Complete();

		PrintData(datas);

		visualizeSortingRecursive(datas, leftIndex, pivotIndex - 1);
		visualizeSortingRecursive(datas, pivotIndex + 1, rightIndex);
	}

	void QuickSortVisualizer::PrintData(vector<Node>& datas) const
	{
		for (size_t i = 0; i < datas.size(); ++i)
		{
			cout << "----";
		}
		cout << endl;

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

		for (size_t i = 0; i < datas.size(); ++i)
		{
			eColorType color = datas[i].GetColorType();

			switch (color)
			{
			case QUICKSORT_DEFAULT:
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::BLACK);
				break;
			case QUICKSORT_LEFT:
				SetConsoleTextAttribute(handle, eConsoleColor::RED << 0x4 | eConsoleColor::WHITE);
				break;
			case QUICKSORT_RIGHT:
				SetConsoleTextAttribute(handle, eConsoleColor::BLUE << 0x4 | eConsoleColor::WHITE);
				break;
			default:
				assert(false);
			}

			cout << "   ";
			SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			cout << " ";
		}
		cout << endl;

		for (size_t i = 0; i < datas.size(); ++i)
		{
			int data = datas[i].GetData();


			if (datas[i].IsComplete())
			{
				SetConsoleTextAttribute(handle, eConsoleColor::GRAY << 0x4 | eConsoleColor::WHITE);
			}
			else if (datas[i].IsSleep())
			{
				SetConsoleTextAttribute(handle, eConsoleColor::DARK_GRAY << 0x4 | eConsoleColor::GRAY);
			}
			else
			{
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			}

			cout << "[" << data << "]";

			SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			cout << " ";
		}
		cout << endl;

		for (size_t i = 0; i < datas.size(); ++i)
		{
			if (datas[i].IsCurrentIndex())
			{
				cout << " ^  ";
			}
			else
			{
				cout << "    ";
			}
		}
		cout << endl;
	}

	void QuickSortVisualizer::initNodes(vector<Node>& datas, int leftIndex, int rightIndex)
	{
		for (size_t i = 0; i < datas.size(); ++i)
		{
			datas[i].SetColorType(eColorType::QUICKSORT_DEFAULT);

			if (i >= leftIndex && i <= rightIndex)
			{
				datas[i].Awake();
			}
			else
			{
				datas[i].Sleep();
			}
		}
	}

	void QuickSortVisualizer::moveLeft(vector<Node>& datas, int currLeftIndex)
	{
		datas[currLeftIndex].SetColorType(eColorType::QUICKSORT_DEFAULT);
		datas[currLeftIndex + 1].SetColorType(eColorType::QUICKSORT_LEFT);
	}

	void QuickSortVisualizer::swapInt(Node& left, Node& right)
	{
		int temp = left.GetData();
		left.SetData(right.GetData());
		right.SetData(temp);
	}
}
