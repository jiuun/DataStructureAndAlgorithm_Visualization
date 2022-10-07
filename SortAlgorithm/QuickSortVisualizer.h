#pragma once

#include <vector>

#include "Visualizer.h"

using namespace std;

enum ePivotPos
{
	LEFT,
	RIGHT
};

namespace sort
{
	class QuickSortVisualizer : public Visualizer
	{
	public:
		static void VisualizeSorting(vector<int>& nums, ePivotPos pivotPos, eViewMode viewMode, eDebug onOff);


	private:
		static void printData(vector<Node>& datas);
		static void visualizeSortingRecursive(vector<Node>& datas, int leftIndex, int rightIndex);
		static void visualizeSortingRecursiveLeftPivot(vector<Node>& datas, int leftIndex, int rightIndex);

		static void initNodes(vector<Node>& datas, int leftIndex, int rightIndex);

		static void moveColorLeft(vector<Node>& datas, int currLeftIndex);
		static void moveColorRight(vector<Node>& datas, int currRightIndex);
	};
}