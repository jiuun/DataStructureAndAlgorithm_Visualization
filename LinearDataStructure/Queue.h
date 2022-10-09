#pragma once

#include "DynamicArray.h"

namespace linear
{
	class Queue : public DynamicArray
	{
	public:
		Queue();
		Queue(size_t capacity);
		Queue(Queue& other);
		Queue& operator=(Queue& rhs);

		bool IsEmpty() const;
		void Enqueue(int data);
		int Dequeue();
		int Front() const;
		int Back() const;
		int RemoveAll() final;

	private:
		size_t mFront;
		size_t mBack;

#ifdef _DEBUG
	public:
		static void Test();
#endif

	};
}
