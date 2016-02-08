# pragma once

# include "IComposite.hpp"

# include <list>

namespace Aquaworks
{
	namespace Behavior
	{
		class Selector : public IComposite
		{
		public:

			virtual void Initialize() override
			{
				m_iterator = m_children.begin();
				(*m_iterator)->Initialize();
				m_isEnd = false;
				m_isSuccess = false;
			}

			virtual void Update(f32 deltaTime) override
			{
				(*m_iterator)->Update(deltaTime);
				if ((*m_iterator)->IsEnd())
				{
					if ((*m_iterator)->IsSuccess())
					{
						m_isEnd = true;
						m_isSuccess = true;
						return;
					}

					++m_iterator;

					if (m_iterator == m_children.end())
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
				return m_isSuccess;
			}

			virtual std::wstring Name() const override
			{
				return L"Selector : " + (*m_iterator)->Name();
			}

		private:

			std::list<IBehavior*>::iterator m_iterator;

			bool m_isEnd;
			bool m_isSuccess;
		};
	}
}
