#pragma once

#include "Table/Table.h"

namespace Graph
{
	class Edge;
	class Vertex;

	typedef bool (*Callback)(Vertex* vertex);

	class Graph : Table::Table
	{
	public:
		Graph();
		~Graph();

		void Add(Vertex* vertex);
		void Remove(Vertex* vertex);

		void Add(Edge* edge);
		void Remove(Edge* edge);

		void DFS(Callback callback);
		void Iterate(Callback callback);
	};
}