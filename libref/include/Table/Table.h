#pragma once

#include <vector>

namespace Table
{
	class Row;

	class Table
	{
	public:
		Table();
		~Table();

	private:
		std::vector<Row*> rows;
	};
}