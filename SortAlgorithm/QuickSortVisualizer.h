#pragma once

#include <vector>

#include "Node.h"

using namespace std;

namespace sort
{
	class QuickSortVisualizer
	{
	public:
		void VisualizeSorting(vector<int>& nums);

		void PrintData(vector<Node>& datas) const;

	private:
		void visualizeSortingRecursive(vector<Node>& datas, int leftIndex, int rightIndex);

		void initNodes(vector<Node>& datas, int leftIndex, int rightIndex);

		void moveLeft(vector<Node>& datas, int currLeftIndex);
		void swapInt(Node& left, Node& right);

	};
}