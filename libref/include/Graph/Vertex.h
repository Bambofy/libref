#pragma once

#include "Table/Row.h"

namespace Graph
{
	class Edge;

	class Vertex : Table::Row
	{
	public:
		Vertex();
		~Vertex();

		void Add(Edge* new_edge);
		void Remove(const Edge* target_edge);

		int EdgeCount() const;
		const Edge* GetEdge(int index);
	};
}