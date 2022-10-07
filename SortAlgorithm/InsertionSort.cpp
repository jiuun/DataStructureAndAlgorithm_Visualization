#include "InsertionSort.h"

namespace sort
{
	void InsertionSort::Sort(std::vector<int>& nums)
	{
		for (int i = 1; i < nums.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[j] < nums[j - 1])
				{
					std::swap(nums[j], nums[j - 1]);
				}
				else
				{
					break;
				}
			}
		}
	}
}