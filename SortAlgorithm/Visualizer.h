#pragma once

#include <vector>

#include "Node.h"
#include "eViewMode.h"
#include "eDebug.h"

namespace sort
{
	class Visualizer
	{
	public:

	protected:
		static void swapInt(Node& a, Node& b);

	protected:
		static eViewMode sViewMode;
		static eDebug sDebug;
	};
}