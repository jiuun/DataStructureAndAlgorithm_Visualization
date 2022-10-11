#include "Queue.h"

#include <cassert>

namespace linear
{
	Queue::Queue()
		: Queue(0)
	{
	}

	Queue::Queue(size_t capacity)
		: DynamicArray(capacity)
		, mFront(0)
		, mBack(0)
	{
	}

	Queue::Queue(Queue& other)
		: DynamicArray(other)
		, mFront(other.mFront)
		, mBack(other.mBack)
	{
		for (size_t i = mCount; i < mCapacity; ++i)
		{
			mDatas[i] = other.mDatas[i];
		}
	}

	Queue& Queue::operator=(Queue& rhs)
	{
		delete[] mDatas;

		mCount = rhs.mCount;
		mCapacity = rhs.mCapacity;
		mDatas = new int[mCapacity];

		for (size_t i = 0; i < mCapacity; ++i)
		{
			mDatas[i] = rhs.mDatas[i];
		}

		mFront = rhs.mFront;
		mBack = rhs.mBack;

		return *this;
	}

	bool Queue::IsEmpty() const
	{
		return (mCount == 0);
	}

	void Queue::Enqueue(int data)
	{
		if (mCount == mCapacity)
		{
			int* temp = new int[mCapacity * 2];

			size_t i = 0;
			while (i < mCount)
			{
				temp[i] = mDatas[(mFront + i++) % mCapacity];
			}
			mBack = mCount;
			mCapacity *= 2;
			assert(i % mCapacity == mBack % mCapacity);

			delete[] mDatas;
			mDatas = temp;
		}

		mDatas[mBack] = data;

		mBack = (mBack + 1) % mCapacity;

		++mCount;
	}

	int Queue::Dequeue()
	{
		if (mCount == 0)
		{
			return -1;
		}

		int result = mDatas[mFront];

		mFront = (mFront + 1) % mCapacity;

		--mCount;

		return result;
	}

	int Queue::Front() const
	{
		return mDatas[mFront];
	}

	int Queue::Back() const
	{
		return mDatas[mBack - 1];
	}

	int Queue::RemoveAll()
	{
		mFront = 0;
		mBack = 0;

		return DynamicArray::RemoveAll();;
	}


#ifdef _DEBUG
	void Queue::Test()
	{
		const size_t TEST_COUNT = 17;


		// constructor test
		{
			Queue* q;
			
			q = new Queue();
			assert(q->GetCount() == 0);
			assert(q->GetCapacity() == DEFAULT_CAP);
			delete q;

			q = new Queue(DEFAULT_CAP * 2);
			assert(q->GetCount() == 0);
			assert(q->GetCapacity() == DEFAULT_CAP * 2);
			delete q;

			Queue other;
			other.Enqueue(1);
			q = new Queue(other);
			assert(q->GetCount() == other.GetCount());
			assert(q->GetCapacity() == other.GetCapacity());
			assert(q->Dequeue() == other.Dequeue());

			Queue rhs;
			rhs.Enqueue(2);
			*q = rhs;
			assert(q->GetCount() == rhs.GetCount());
			assert(q->GetCapacity() == rhs.GetCapacity());
			assert(q->Dequeue() == rhs.Dequeue());

			delete q;
		}


		{
			Queue q;

			assert(q.IsEmpty() == true);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				q.Enqueue(i);
			}

			assert(q.GetCount() == TEST_COUNT);
			assert(q.GetCapacity() == DEFAULT_CAP * 2);
			assert(q.Front() == 0);
			assert(q.Back() == TEST_COUNT - 1);


			for (int i = 0; i < TEST_COUNT; ++i)
			{
				assert(q.Dequeue() == i);
			}
			assert(q.Dequeue() == -1);

			assert(q.IsEmpty() == true);
			assert(q.GetCount() == 0);
			assert(q.GetCapacity() == DEFAULT_CAP * 2);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				q.Enqueue(i);
			}

			assert(q.RemoveAll() == TEST_COUNT);

			assert(q.IsEmpty() == true);
			assert(q.GetCount() == 0);
			assert(q.GetCapacity() == DEFAULT_CAP * 2);
		}

		// additional copy constructor test
		{
			Queue q;

			q.Enqueue(1);
			assert(q.Dequeue() == 1);

			for (int i = 0; i < TEST_COUNT; ++i)
			{
				q.Enqueue(i);
			}

			q.Dequeue();
			q.Dequeue();
			q.Enqueue(18);
			q.Enqueue(19);
			q.Enqueue(20);
			q.Enqueue(21);

			Queue copy(q);

			int qCount = q.GetCount();
			for (int i = 0; i < qCount; ++i)
			{
				assert(q.Dequeue() == copy.Dequeue());
			}
		}
	}
#endif

}
