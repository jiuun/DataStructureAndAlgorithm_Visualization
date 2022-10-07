#include "SelectionSortVisualizer.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

namespace sort
{
	void SelectionSortVisualizer::VisualizeSorting(std::vector<int>& nums, eViewMode viewMode, eDebug onOff)
	{
		sViewMode = viewMode;
		sDebug = onOff;

		vector<Node> datas;
		datas.reserve(nums.size());

		for (size_t i = 0; i < nums.size(); ++i)
		{
			datas.push_back(Node(nums[i], eColorType::SELECTSORT_DEFAULT));
		}
		printData(datas);

		for (size_t i = 0; i < datas.size(); ++i)
		{
			datas[i].OnCurrnetIndex();

			size_t minIndex = i;
			datas[minIndex].SetColorType(eColorType::SELECTSORT_MIN);

			printData(datas);

			for (size_t j = i + 1; j < datas.size(); ++j)
			{
				datas[j].SetColorType(eColorType::SELECTSORT_SEARCH);

				printData(datas);

				if (datas[minIndex].GetData() > datas[j].GetData())
				{
					datas[minIndex].SetColorType(eColorType::SELECTSORT_DEFAULT);

					minIndex = j;

					datas[minIndex].SetColorType(eColorType::SELECTSORT_MIN);

					printData(datas);
				}

				if (minIndex != j)
				{
					datas[j].SetColorType(eColorType::SELECTSORT_DEFAULT);
				}
			}

			swapInt(datas[minIndex], datas[i]);
			datas[minIndex].SetColorType(eColorType::SELECTSORT_DEFAULT);
			datas[i].Complete();
			datas[i].OffCurrnetIndex();
		}

		for (size_t i = 0; i < datas.size(); ++i)
		{
			nums[i] = datas[i].GetData();
		}
	}

	void SelectionSortVisualizer::printData(vector<Node>& datas)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
		for (size_t i = 0; i < datas.size(); ++i)
		{
			cout << "----";
		}
		cout << endl;

		for (size_t i = 0; i < datas.size(); ++i)
		{
			if (datas[i].IsComplete())
			{
				SetConsoleTextAttribute(handle, eConsoleColor::DARK_GRAY << 0x4 | eConsoleColor::WHITE);
			}
			else if (datas[i].GetColorType() == eColorType::SELECTSORT_DEFAULT)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			}
			else if (datas[i].GetColorType() == eColorType::SELECTSORT_MIN)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::RED << 0x4 | eConsoleColor::WHITE);
			}
			else if (datas[i].GetColorType() == eColorType::SELECTSORT_SEARCH)
			{
				SetConsoleTextAttribute(handle, eConsoleColor::BLUE << 0x4 | eConsoleColor::WHITE);
			}
			cout << "[" << datas[i].GetData() << "]";

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

		if (sDebug == eDebug::OFF)
		{
			cout << "  Press the Enter to Continue ";
			string trash;
			getline(cin, trash);
		}
		else
		{
			cout << endl;
		}

		if (sViewMode == eViewMode::ONE_BY_ONE)
		{
			system("cls");
		}
	}
}