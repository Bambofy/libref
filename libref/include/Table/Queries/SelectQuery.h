#pragma once

#include "../Query.h"

namespace Table
{
	namespace Queries
	{
		class SelectQuery : public Query
		{
		public:
			SelectQuery();
			~SelectQuery();
		};
	}
}