#include "InsertionSortVisualizer.h"


#include <cassert>
#include <iostream>
#include <string>

using namespace std;

namespace sort
{
	void InsertionSortVisualizer::VisualizeSorting(std::vector<int>& nums, eViewMode viewMode, eDebug onOff)
	{
		sViewMode = viewMode;
		sDebug = onOff;

		vector<Node> datas;
		datas.reserve(nums.size());

		for (size_t i = 0; i < nums.size(); ++i)
		{
			datas.push_back(Node(nums[i], eColorType::INSERTSORT_DEFAULT));
		}
		printData(datas);

		datas[0].SetColorType(eColorType::INSERTSORT_SORTED);
		printData(datas);

		for (int i = 1; i < datas.size(); ++i)
		{
			datas[i].SetColorType(eColorType::INSERTSORT_CURRENT);
			printData(datas);

			int curr = i - 1;
			for (; curr >= 0; --curr)
			{
				if (datas[curr].GetData() > datas[curr + 1].GetData())
				{
					swapInt(datas[curr], datas[curr + 1]);

					datas[curr + 1].SetColorType(eColorType::INSERTSORT_SORTED);
					datas[curr].SetColorType(eColorType::INSERTSORT_CURRENT);
					printData(datas);
				}
				else
				{
					break;
				}
			}
			datas[curr + 1].SetColorType(eColorType::INSERTSORT_SORTED);
		}

		for (size_t i = 0; i < datas.size(); ++i)
		{
			nums[i] = datas[i].GetData();
		}
	}

	void InsertionSortVisualizer::printData(vector<Node>& datas)
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
			switch (datas[i].GetColorType())
			{
			case INSERTSORT_DEFAULT:
				SetConsoleTextAttribute(handle, eConsoleColor::BLACK << 0x4 | eConsoleColor::WHITE);
				break;
			case INSERTSORT_SORTED:
				SetConsoleTextAttribute(handle, eConsoleColor::DARK_GRAY << 0x4 | eConsoleColor::WHITE);
				break;
			case INSERTSORT_CURRENT:
				SetConsoleTextAttribute(handle, eConsoleColor::RED << 0x4 | eConsoleColor::WHITE);
				break;
			default:
				assert(false);
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