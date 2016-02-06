# pragma once

# include "../IBehavior.hpp"

# include <list>

namespace Aquaworks
{
	namespace Behavior
	{
		class IComposite : public IBehavior
		{
		public:

			virtual ~IComposite()
			{
				for (auto&& child : m_children)
				{
					delete child;
					child = nullptr;
				}
			}

		public:

			virtual void Add(IBehavior* behavior) override
			{
				m_children.push_back(behavior);
			}

		protected:

			std::list<IBehavior*> m_children;
		};
	}
}
