#pragma once

#include <iostream>
#include <vector>

#include "Node.h"

using namespace std;

class IVisualizer
{
public:
	virtual void PrintData(vector<Node>& datas) const = 0;
	virtual void SetTextColor(Node& data, eBitSet bitSet, eColorType colorSet) = 0;

};

