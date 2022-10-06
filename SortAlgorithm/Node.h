#pragma once

#include <windows.h>

#include "eColorType.h"
#include "eConsoleColor.h"

class Node
{
public:
	Node(int data, eColorType colorType)
		: mData(data)
		, mColorType(colorType)
		, mbCurrIndex(false)
		, mbComplete(false)
		, mbSleep(false)
	{}

	int GetData() const { return mData; }
	void SetData(int data) { mData = data; }

	eColorType GetColorType() const { return mColorType; }
	bool IsCurrentIndex() const { return mbCurrIndex; }

	void SetColorType(eColorType colorType)
	{
		mColorType = colorType;
	}

	bool IsCurrentIndex()
	{
		return mbCurrIndex;
	}
	void OnCurrnetIndex()
	{
		mbCurrIndex = true;
	}
	void OffCurrnetIndex()
	{
		mbCurrIndex = false;
	}

	bool IsComplete()
	{
		return mbComplete;
	}
	void Complete()
	{
		mbComplete = true;
	}

	bool IsSleep()
	{
		return mbSleep;
	}
	void Sleep()
	{
		mbSleep = true;
	}
	void Awake()
	{
		mbSleep = false;
	}

private:
	int mData;
	eColorType mColorType;
	bool mbCurrIndex;
	bool mbComplete;
	bool mbSleep;
};

