#pragma once

#include <vector>

#include "Visualizer.h"

namespace sort
{
	class BubbleSortVisualizer : public Visualizer
	{
	public:
		static void VisualizeSorting(std::vector<int>& datas, eViewMode viewMode, eDebug onOff);

	private:
		static void printData(std::vector<Node>& datas);

	};
}

