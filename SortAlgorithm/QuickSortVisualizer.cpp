#include "QuickSortVisualizer.h"

#include <cassert>

namespace sort
{
	void QuickSortVisualizer::VisualizeSorting(vector<int>& nums)
	{
		vector<Node> datas;
		datas.reserve(nums.size());

		datas.push_back(Node(-1, eColorType::QSORT_DEFAULT));
		SetTextColor(datas[0], eBitSet::ON, eColorType::QSORT_INVISIBLE);

		for (size_t i = 0; i < nums.size(); ++i)
		{
			datas.push_back(Node(nums[i], eColorType::QSORT_DEFAULT));
		}
		PrintData(datas);
		SetTextColor(datas[0], eBitSet::OFF, eColorType::QSORT_INVISIBLE);
		visualizeSortingRecursive(datas, 1, static_cast<int>(datas.size() - 1));
	}

	void QuickSortVisualizer::visualizeSortingRecursive(vector<Node>& datas, int leftIndex, int rightIndex)
	{
		if (leftIndex >= rightIndex)
		{
			return;
		}

		setSleep(datas, leftIndex, rightIndex);

		int pivotIndex = rightIndex;
		int currLeftIndex = leftIndex - 1;

		SetTextColor(datas[pivotIndex], eBitSet::ON, eColorType::QSORT_RIGHT);
		SetTextColor(datas[currLeftIndex], eBitSet::ON, eColorType::QSORT_LEFT);

		PrintData(datas);
		SetTextColor(datas[0], eBitSet::ON, eColorType::QSORT_INVISIBLE);

		for (int i = leftIndex; i < rightIndex; ++i)
		{
			SetTextColor(datas[i], eBitSet::ON, eColorType::QSORT_CURRENT);

			if (datas[i].GetData() < datas[pivotIndex].GetData())
			{
				SetTextColor(datas[currLeftIndex], eBitSet::OFF, eColorType::QSORT_LEFT);
				++currLeftIndex;
				SetTextColor(datas[currLeftIndex], eBitSet::ON, eColorType::QSORT_LEFT);
				PrintData(datas);
				std::swap(datas[currLeftIndex], datas[i]);
				if (currLeftIndex != i) { PrintData(datas); }
			}
			PrintData(datas);
			SetTextColor(datas[i], eBitSet::OFF, eColorType::QSORT_CURRENT);
		}

		pivotIndex = currLeftIndex + 1;
		std::swap(datas[pivotIndex], datas[rightIndex]);
		
		SetTextColor(datas[pivotIndex], eBitSet::ON, eColorType::QSORT_COMPLETE);
		PrintData(datas);

		visualizeSortingRecursive(datas, leftIndex, pivotIndex - 1);
		visualizeSortingRecursive(datas, pivotIndex + 1, rightIndex);
	}

	void QuickSortVisualizer::PrintData(vector<Node>& datas) const
	{
		for (size_t i = 0; i < datas.size(); ++i)
		{
			int data = datas[i].GetData();
			int colorSet = static_cast<int>(datas[i].GetColorSet());

			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			
			if ((colorSet & Q_INVISIBLE) == Q_INVISIBLE)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::BLACK);
			}
			else if ((colorSet & Q_COMPLETE) == Q_COMPLETE)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::GRAY << 0x4 | eConsoleColor::WHITE);
			}
			else if ((colorSet & Q_SLEEP) == Q_SLEEP)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::DARK_GRAY << 0x4 | eConsoleColor::GRAY);
			}
			else if (colorSet == Q_DEFAULT)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			}
			else if ((colorSet & Q_LEFT) == Q_LEFT)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::RED << 0x4 | eConsoleColor::WHITE);
			}
			else if ((colorSet & Q_RIGHT) == Q_RIGHT)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::BLUE << 0x4 | eConsoleColor::WHITE);
			}

			if ((colorSet & Q_CURRENT) == Q_CURRENT)
			{
				cout << ">" << data << "<";
			}
			else
			{
				cout << "[" << data << "]";
			}
			SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			cout << " ";
		}

		cout << endl;
	}

	void QuickSortVisualizer::setSleep(vector<Node>& datas, int leftIndex, int rightIndex)
	{
		for (size_t i = 0; i < datas.size(); ++i)
		{
			if (i < leftIndex || i > rightIndex + 1)
			{
				SetTextColor(datas[i], eBitSet::ON, eColorType::QSORT_SLEEP);
			}
			else
			{
				SetTextColor(datas[i], eBitSet::OFF, eColorType::QSORT_SLEEP);
			}
		}
	}

	void QuickSortVisualizer::SetTextColor(Node& data, eBitSet bitSet, eColorType colorSet)
	{
		switch (bitSet)
		{
		case OFF:
			data.OffColorSet(colorSet);
			break;
		case ON:
			data.OnColorSet(colorSet);
			break;
		case TOGGLE:
			data.ToggleColorSet(colorSet);
			break;
		default:
			assert(false);
		}
	}
}
