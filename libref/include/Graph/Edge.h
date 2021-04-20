#pragma once

#include "Table/Row.h"

namespace Graph
{
	class Vertex;

	class Edge : Table::Row
	{
	public:
		Edge(Vertex* sv, Vertex* ev);
		~Edge();

		const Vertex* Start();
		const Vertex* End();
	};
}