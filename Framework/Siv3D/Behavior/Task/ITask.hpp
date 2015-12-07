# pragma once

# include "Behavior/IBehavior.hpp"

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
