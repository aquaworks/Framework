# pragma once

# include "IBehavior.hpp"

namespace Behavior
{
	class BehaviorTree
	{
	public:

		~BehaviorTree()
		{
			delete m_entry;
		}

	public:

		void Entry(Behavior::IBehavior* behavior)
		{
			m_entry = behavior;
		}

		void Initialize()
		{
			m_entry->Initialize();
		}

		void Update(float deltaTime)
		{
			m_entry->Update(deltaTime);

			if (m_entry->IsEnd())
			{
				m_entry->Initialize();
			}
		}

		std::wstring Name() const
		{
			return L"BehaviorTree : " + m_entry->Name();
		}

	private:

		Behavior::IBehavior* m_entry;
	};
}
