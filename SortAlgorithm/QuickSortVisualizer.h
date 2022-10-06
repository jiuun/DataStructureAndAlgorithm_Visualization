#pragma once

#include <vector>

#include "Node.h"

using namespace std;

enum ePivotPos
{
	LEFT,
	RIGHT
};

enum eViewMode
{
	SEQUENCE,
	ONE_BY_ONE
};

namespace sort
{
	class QuickSortVisualizer
	{
	public:
		static void VisualizeSorting(vector<int>& nums, ePivotPos pivotPos, eViewMode viewMode);

		static void PrintData(vector<Node>& datas);

	private:
		static void visualizeSortingRecursive(vector<Node>& datas, int leftIndex, int rightIndex);
		static void visualizeSortingRecursiveLeftPivot(vector<Node>& datas, int leftIndex, int rightIndex);

		static void initNodes(vector<Node>& datas, int leftIndex, int rightIndex);

		static void moveColorLeft(vector<Node>& datas, int currLeftIndex);
		static void moveColorRight(vector<Node>& datas, int currRightIndex);
		static void swapInt(Node& left, Node& right);

		static eViewMode sViewMode;
	};
}