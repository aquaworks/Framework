# pragma once

# include "IComposite.hpp"

# include <list>

namespace Aquaworks
{
	namespace Behavior
	{
		class Sequence : public IComposite
		{
		public:

			virtual void Initialize() override
			{
				m_iterator = m_children.begin();
				(*m_iterator)->Initialize();
				m_isEnd = false;
			}

			virtual void Update(f32 deltaTime) override
			{
				(*m_iterator)->Update(deltaTime);
				if ((*m_iterator)->IsEnd())
				{
					if (!(*m_iterator)->IsSuccess())
					{
						m_isEnd = true;
						return;
					}
					++m_iterator;
					if (IsSuccess())
					{
						m_isEnd = true;
						return;
					}
					(*m_iterator)->Initialize();
				}
			}

			virtual bool IsEnd() const override
			{
				return m_isEnd;
			}

			virtual bool IsSuccess() const override
			{
				return m_iterator == m_children.end();
			}

			virtual std::wstring Name() const override
			{
				return L"Sequence : " + (*m_iterator)->Name();
			}

		private:

			std::list<IBehavior*>::iterator m_iterator;

			bool m_isEnd;
		};
	}
}
