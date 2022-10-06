#pragma once

#include <vector>

using namespace std;

namespace sort
{
	class QuickSort
	{
	public:
		static void Sort(vector<int>& nums);

	private:
		static void quickSortRecursive(vector<int>& nums, int leftIndex, int rightIndex);
	};
}

