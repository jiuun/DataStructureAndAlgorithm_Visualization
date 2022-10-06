#pragma once

#include <vector>

#include "IVisualizer.h"

using namespace std;

namespace sort
{
	class QuickSortVisualizer : public IVisualizer
	{
	public:
		void VisualizeSorting(vector<int>& nums);

		void PrintData(vector<Node>& datas) const final;
		void SetTextColor(Node& data, eBitSet bitSet, eColorType colorSet) final;

	private:
		void visualizeSortingRecursive(vector<Node>& datas, int leftIndex, int rightIndex);

		void setSleep(vector<Node>& datas, int leftIndex, int rightIndex);

		enum
		{
			Q_DEFAULT = 0b00000000,
			Q_CURRENT = 0b00000001,
			Q_LEFT = 0b00000010,
			Q_RIGHT = 0b00000100,
			Q_SLEEP = 0b00001000,
			Q_COMPLETE = 0b00010000,
			Q_INVISIBLE = 0b00100000
		};
	};
}