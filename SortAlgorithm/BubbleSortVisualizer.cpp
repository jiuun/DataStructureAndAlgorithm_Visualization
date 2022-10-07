#include "BubbleSortVisualizer.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

namespace sort
{
	void BubbleSortVisualizer::VisualizeSorting(std::vector<int>& nums, eViewMode viewMode, eDebug onOff)
	{
		vector<Node> datas;
		datas.reserve(nums.size());

		sViewMode = viewMode;
		sDebug = onOff;

		for (size_t i = 0; i < nums.size(); ++i)
		{
			datas.push_back(Node(nums[i], eColorType::BUBBLESORT_DEFAULT));
		}
		printData(datas);

		size_t lastIndex = nums.size() - 1;
		for (size_t i = 0; i < lastIndex; ++i)
		{
			for (size_t j = 0; j < lastIndex - i; ++j)
			{
				datas[j].SetColorType(eColorType::BUBBLESORT_LEFT);
				datas[j + 1].SetColorType(eColorType::BUBBLESORT_RIGHT);
				printData(datas);

				if (datas[j].GetData() > datas[j + 1].GetData())
				{
					swapInt(datas[j], datas[j + 1]);
					
					printData(datas);
				}

				datas[j].SetColorType(eColorType::BUBBLESORT_DEFAULT);
				datas[j + 1].SetColorType(eColorType::BUBBLESORT_DEFAULT);
			}

			datas[lastIndex - i].Complete();
			printData(datas);
		}

		for (size_t i = 0; i < nums.size(); ++i)
		{
			nums[i] = datas[i].GetData();
		}
	}

	void BubbleSortVisualizer::printData(std::vector<Node>& datas)
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
			int data = datas[i].GetData();
			eColorType color = datas[i].GetColorType();

			switch (color)
			{
			case BUBBLESORT_DEFAULT:
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
				break;
			case BUBBLESORT_LEFT:
				SetConsoleTextAttribute(handle, eConsoleColor::RED << 0x4 | eConsoleColor::WHITE);
				break;
			case BUBBLESORT_RIGHT:
				SetConsoleTextAttribute(handle, eConsoleColor::BLUE << 0x4 | eConsoleColor::WHITE);
				break;
			default:
				assert(false);
			}

			if (datas[i].IsComplete())
			{
				SetConsoleTextAttribute(handle, eConsoleColor::DARK_GRAY << 0x4 | eConsoleColor::WHITE);
			}

			cout << "[" << data << "]";

			SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
			cout << " ";
		}
		cout << endl;

		if (sDebug == eDebug::OFF)
		{
			cout << "  Press the Enter to Continue ";
			string trash;
			getline(cin, trash);
		}

		if (sViewMode == eViewMode::ONE_BY_ONE)
		{
			system("cls");
		}
	}
}