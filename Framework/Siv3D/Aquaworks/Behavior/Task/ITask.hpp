# pragma once

# include "../IBehavior.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class ITask : public IBehavior
		{
		public:

			virtual void Add(IBehavior* behavior) override
			{
				(void)behavior;
			}
		};
	}
}
