#include "DynamicArray.h"

#include <cassert>

namespace linear
{
	DynamicArray::DynamicArray()
		: DynamicArray(0)
	{
	}

	DynamicArray::DynamicArray(size_t capacity)
		: mCount(0)
		, mCapacity(capacity > DEFAULT_CAP ? capacity : DEFAULT_CAP)
	{
		mDatas = new int[mCapacity];
	}

	DynamicArray::DynamicArray(DynamicArray& other)
		: mCount(other.mCount)
		, mCapacity(other.mCapacity)
	{
		mDatas = new int[mCapacity];
		for (size_t i = 0; i < mCount; ++i)
		{
			mDatas[i] = other.mDatas[i];
		}
	}

	DynamicArray& DynamicArray::operator=(DynamicArray& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		delete[] mDatas;

		mCount = rhs.mCount;
		mCapacity = rhs.mCapacity;
		mDatas = new int[rhs.mCapacity];
		
		for (size_t i = 0; i < mCount; ++i)
		{
			mDatas[i] = rhs.mDatas[i];
		}

		return *this;
	}

	DynamicArray::~DynamicArray()
	{
		delete[] mDatas;
	}


	void DynamicArray::EnsureCapacity(size_t newCapacity)
	{
		if (mCapacity >= newCapacity)
		{
			return;
		}

		int* temp = new int[newCapacity];

		for (size_t i = 0; i < mCount; ++i)
		{
			temp[i] = mDatas[i];
		}

		delete[] mDatas;

		mDatas = temp;
		mCapacity = newCapacity;
	}
	size_t DynamicArray::GetCount() const
	{
		return mCount;
	}
	size_t DynamicArray::GetCapacity() const
	{
		return mCapacity;
	}

	int DynamicArray::RemoveAll()
	{
		int removedCount = static_cast<int>(mCount);

		mCount = 0;

		return removedCount;
	}
}