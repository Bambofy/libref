#pragma once

namespace Table
{
	class Table;
	class Result;

	class Query
	{
	public:
		Query();
		virtual ~Query();

		virtual const Result* Execute(const Table* target);
	};
}