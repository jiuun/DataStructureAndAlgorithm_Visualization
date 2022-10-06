#include "QuickSort.h"

namespace sort
{
	void QuickSort::Sort(vector<int>& nums)
	{
		quickSortRecursive(nums, 0, static_cast<int>(nums.size() - 1));
	}

	void QuickSort::quickSortRecursive(vector<int>& nums, int leftIndex, int rightIndex)
	{
		if (leftIndex >= rightIndex)
		{
			return;
		}

		int pivotIndex = rightIndex;
		int currLeftIndex = leftIndex - 1;

		for (int i = leftIndex; i < rightIndex; ++i)
		{
			if (nums[i] < nums[pivotIndex])
			{
				++currLeftIndex;
				std::swap(nums[currLeftIndex], nums[i]);
			}
		}

		pivotIndex = currLeftIndex + 1;
		std::swap(nums[pivotIndex], nums[rightIndex]);

		quickSortRecursive(nums, leftIndex, pivotIndex - 1);
		quickSortRecursive(nums, pivotIndex + 1, rightIndex);
	}
}
