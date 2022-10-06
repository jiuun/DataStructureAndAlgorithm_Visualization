#pragma once

#include <vector>

#include "Node.h"
#include "eViewMode.h"
#include "eDebug.h"

namespace sort
{
	class BubbleSortVisualizer
	{
	public:
		static void VisualizeSorting(std::vector<int>& datas, eViewMode viewMode, eDebug onOff);

	private:
		static void printData(std::vector<Node>& datas);
		static void swapInt(Node& a, Node& b);

	private:
		static eViewMode sViewMode;
		static eDebug sDebug;
	};
}

