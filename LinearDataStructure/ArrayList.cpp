#include "ArrayList.h"

#include <cassert>

namespace linear
{
	ArrayList::ArrayList()
		: ArrayList(0)
	{
	}

	ArrayList::ArrayList(size_t capacity)
		: DynamicArray(capacity)
	{
	}
	ArrayList::ArrayList(ArrayList& other)
		: DynamicArray(other)
	{
	}

	ArrayList& ArrayList::operator=(ArrayList& rhs)
	{
		DynamicArray::operator=(rhs);

		return *this;
	}


	void ArrayList::Add(int data)
	{
		if (mCount == mCapacity)
		{
			EnsureCapacity(mCapacity * 2);
		}

		mDatas[mCount++] = data;
	}

	int& ArrayList::operator[](size_t index) const
	{
		assert(index < mCount);

		return mDatas[index];
	}

	bool ArrayList::Insert(size_t index, int data)
	{
		if (index > mCount)
		{
			return false;
		}

		if (mCount == mCapacity)
		{
			EnsureCapacity(mCapacity * 2);
		}

		for (size_t i = mCount; i > index; --i)
		{
			mDatas[i] = mDatas[i - 1];
		}

		mDatas[index] = data;

		++mCount;

		return true;
	}

	bool ArrayList::RemoveAt(size_t index)
	{
		if (index >= mCount)
		{
			return false;
		}

		--mCount;

		for (size_t i = index; i < mCount; ++i)
		{
			mDatas[i] = mDatas[i + 1];
		}

		return true;
	}

	bool ArrayList::Contains(int data) const
	{
		for (size_t i = 0; i < mCount; ++i)
		{
			if (mDatas[i] == data)
			{
				return true;
			}
		}

		return false;
	}

	int ArrayList::IndexOf(int data)
	{
		if (mCount == 0)
		{
			return -1;
		}

		for (size_t i = 0; i < mCount; ++i)
		{
			if (mDatas[i] == data)
			{
				return static_cast<int>(i);
			}
		}

		return -1;
	}

	int ArrayList::LastIndexOf(int data)
	{
		if (mCount == 0)
		{
			return -1;
		}

		for (int i = static_cast<int>(mCount) - 1; i >= 0; --i)
		{
			if (mDatas[i] == data)
			{
				return i;
			}
		}

		return -1;
	}

	void ArrayList::Reverse()
	{
		if (mCount == 0)
		{
			return;
		}

		size_t lastIndex = mCount - 1;

		for (size_t i = 0; i < mCount / 2; ++i)
		{
			int temp = mDatas[i];
			mDatas[i] = mDatas[lastIndex - i];
			mDatas[lastIndex - i] = mDatas[i];
		}
	}

#ifdef _DEBUG
	void ArrayList::Test()
	{
		// constructor, destructor test
		{
			ArrayList* arr;

			arr = new ArrayList();
			assert(arr->GetCount() == 0);
			assert(arr->GetCapacity() == DEFAULT_CAP);
			delete arr;

			arr = new ArrayList(DEFAULT_CAP * 2);
			assert(arr->GetCount() == 0);
			assert(arr->GetCapacity() == DEFAULT_CAP * 2);
			delete arr;

			ArrayList other;
			other.Add(1);
			arr = new ArrayList(other);
			assert(arr->GetCount() == other.GetCount());
			assert(arr->GetCapacity() == other.GetCapacity());

			ArrayList rhs;
			rhs.Add(2);
			*arr = rhs;

			delete arr;
		}


		{
			ArrayList arr;
			const int TEST_COUNT = 17;
			for (int i = 0; i < TEST_COUNT; ++i)
			{
				arr.Add(i);
			}

			assert(arr.GetCount() == TEST_COUNT);
			assert(arr.GetCapacity() == DEFAULT_CAP * 2);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				assert(arr.Contains(i) == true);
			}

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				assert(arr[0] == i);
				assert(arr.RemoveAt(0));
			}

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				assert(arr.Insert(0, TEST_COUNT - 1 - i) == true);
			}

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				assert(arr.IndexOf(i) == i);
				assert(arr.LastIndexOf(i) == i);
			}

			assert(arr.RemoveAll() == TEST_COUNT);
			assert(arr.GetCount() == 0);
			assert(arr.GetCapacity() == DEFAULT_CAP * 2);
		}


	}
#endif
}
