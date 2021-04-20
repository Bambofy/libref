#pragma once

#include "Graph/Vertex.h"
#include "Graph/Graph.h"
#include "Table/Row.h"

namespace LibRef
{
	class Object : Graph::Vertex
	{
	public:
		Object();
		~Object();

	private:
		static Graph::Graph ObjectGraph;
	};
}