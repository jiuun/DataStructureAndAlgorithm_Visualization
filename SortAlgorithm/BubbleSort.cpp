#include "BubbleSort.h"

namespace sort
{
	void BubbleSort::Sort(vector<int>& nums)
	{
		for (size_t i = 0; i < nums.size() - 1; ++i)
		{
			for (size_t j = 0; j < nums.size() - 1 - i; ++j)
			{
				if (nums[j] > nums[j + 1])
				{
					std::swap(nums[j], nums[j + 1]);
				}
			}
		}
	}
}