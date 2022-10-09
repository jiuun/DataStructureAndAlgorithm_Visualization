#pragma once

#include "DynamicArray.h"

namespace linear
{
	class Stack : public DynamicArray
	{
	public:
		Stack();
		Stack(size_t capacity);
		Stack(Stack& other);
		Stack& operator=(Stack& rhs);

		bool IsEmpty() const;
		void Push(int data);
		int Pop();
		int Top() const;
		

#ifdef _DEBUG
	public:
		static void Test();
#endif
	};
}

