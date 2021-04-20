#pragma once

#include "Column.h"

namespace Table
{
	class Row
	{
	public:
		Row(int primary_key);
		~Row();

		int PrimaryKey() const;
		
		void AddColumn(Column* column);
		int ColumCount() const;
		const Column* GetColumn(int index);
		void RemoveColumn(int index);

	private:
		int primary_key;
		std::vector<Column*> columns;
	};
}