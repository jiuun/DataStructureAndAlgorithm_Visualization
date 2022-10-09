#pragma once

#include <iostream>

namespace linear
{
	class DynamicArray
	{
	public:
		void EnsureCapacity(size_t newCapacity);
		size_t GetCount() const;
		size_t GetCapacity() const;
		virtual int RemoveAll();

	protected:
		DynamicArray();
		DynamicArray(size_t capacity);
		DynamicArray(DynamicArray& other);
		DynamicArray& operator=(DynamicArray& rhs);
		virtual ~DynamicArray();


	protected:
		enum
		{
			DEFAULT_CAP = 16
		};

		int* mDatas;
		size_t mCount;
		size_t mCapacity;
	};
}

