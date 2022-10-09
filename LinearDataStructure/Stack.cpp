#include "Stack.h"

#include <cassert>

namespace linear
{
	Stack::Stack()
		: Stack(0)
	{
	}

	Stack::Stack(size_t capacity)
		: DynamicArray(capacity)
	{
	}

	Stack::Stack(Stack& other)
		: DynamicArray(other)
	{
	}

	Stack& Stack::operator=(Stack& rhs)
	{
		DynamicArray::operator=(rhs);

		return *this;
	}

	bool Stack::IsEmpty() const
	{
		return (mCount == 0);
	}
	void Stack::Push(int data)
	{
		if (mCount == mCapacity)
		{
			EnsureCapacity(mCapacity * 2);
		}

		mDatas[mCount++] = data;
	}

	int Stack::Pop()
	{
		if (IsEmpty())
		{
			return -1;
		}

		return mDatas[--mCount];
	}

	int Stack::Top() const
	{
		if (IsEmpty())
		{
			return -1;
		}

		return mDatas[mCount - 1];
	}

	void Stack::Test()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		//_CrtSetBreakAlloc();

		const size_t TEST_COUNT = 17;

		// test constructor
		{
			Stack* st;

			st = new Stack();
			assert(st->GetCount() == 0);
			assert(st->GetCapacity() == DEFAULT_CAP);
			delete st;

			st = new Stack(DEFAULT_CAP * 2);
			assert(st->GetCount() == 0);

			assert(st->GetCapacity() == DEFAULT_CAP * 2);
			delete st;

			Stack other;
			other.Push(1);
			st = new Stack(other);
			assert(st->GetCount() == other.GetCount());
			assert(st->GetCapacity() == other.GetCapacity());
			assert(st->Pop() == other.Pop());

			Stack rhs;
			rhs.Push(2);
			*st = rhs;
			assert(st->GetCount() == rhs.GetCount());
			assert(st->GetCapacity() == rhs.GetCapacity());
			assert(st->Pop() == rhs.Pop());

			delete st;
		}

		{
			Stack st;

			assert(st.IsEmpty() == true);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				st.Push(i);
			}

			assert(st.GetCount() == TEST_COUNT);
			assert(st.GetCapacity() == DEFAULT_CAP * 2);
			assert(st.Top() == TEST_COUNT - 1);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				assert(st.Pop() == (TEST_COUNT - 1 - i));
			}
			assert(st.Pop() == -1);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				st.Push(i);
			}

			assert(st.RemoveAll() == TEST_COUNT);

			assert(st.IsEmpty() == true);
			assert(st.GetCount() == 0);
			assert(st.GetCapacity() == DEFAULT_CAP * 2);
		}
	}
}