#pragma once

#include <windows.h>

#include "eBitSet.h"
#include "eColorSet.h"

class Node
{
public:
	Node(int data, eColorType colorType)
		: mData(data)
		, mColorType(colorType)
	{}

	int GetData() const { return mData; }
	eColorType GetColorSet() const { return mColorType; }
	void ToggleColorSet(eColorType colorType)
	{ 
		int color = static_cast<int>(mColorType) ^ static_cast<int>(colorType);
		mColorType = static_cast<eColorType>(color);
	}
	void OnColorSet(eColorType colorType)
	{
		int color = static_cast<int>(mColorType) | static_cast<int>(colorType);
		mColorType = static_cast<eColorType>(color);
	}
	void OffColorSet(eColorType colorType)
	{
		int color = static_cast<int>(mColorType) & ~static_cast<int>(colorType);
		mColorType = static_cast<eColorType>(color);
	}

private:
	int mData;
	eColorType mColorType;
};

