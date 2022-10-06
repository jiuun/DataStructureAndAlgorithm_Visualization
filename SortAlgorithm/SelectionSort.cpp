#include "SelectionSort.h"

namespace sort
{
	void SelectionSort::Sort(std::vector<int>& nums)
	{
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			int minIndex = i;

			for (int j = i; j < nums.size(); ++j)
			{
				if (nums[minIndex] > nums[j])
				{
					minIndex = j;
				}
			}

			std::swap(nums[i], nums[minIndex]);
		}
	}
}