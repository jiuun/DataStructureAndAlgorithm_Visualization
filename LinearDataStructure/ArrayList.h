#pragma once

#include "DynamicArray.h"

namespace linear
{
	class ArrayList : public DynamicArray
	{
	public:
		ArrayList();
		ArrayList(size_t capacity);
		ArrayList(ArrayList& other);
		ArrayList& operator=(ArrayList& rhs);

		void Add(int data);
		int& operator[](size_t index) const;
		bool RemoveAt(size_t index);
		bool Insert(size_t index, int data);
		bool Contains(int data) const;
		int IndexOf(int data);
		int LastIndexOf(int data);
		void Reverse();

	private:


#ifdef _DEBUG
	public:
		static void Test();
#endif
	};
}

