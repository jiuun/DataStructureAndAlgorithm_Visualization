#include "Visualizer.h"

namespace sort
{
	eViewMode Visualizer::sViewMode = eViewMode::SEQUENCE;
	eDebug Visualizer::sDebug = eDebug::OFF;

	void Visualizer::swapInt(Node& a, Node& b)
	{
		int temp = a.GetData();
		a.SetData(b.GetData());
		b.SetData(temp);
	}
}