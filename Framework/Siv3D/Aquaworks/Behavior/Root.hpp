# pragma once

# include "IBehavior.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class Root : public IBehavior
		{
		public:

			Root()
				: m_entry(nullptr)
			{

			}

			virtual ~Root()
			{
				delete m_entry;
				m_entry = nullptr;
			}

		public:

			virtual void Initialize() override
			{
				m_entry->Initialize();
			}

			virtual void Update(float deltaTime) override
			{
				m_entry->Update(deltaTime);
			}

			virtual bool IsEnd() const override
			{
				return m_entry->IsEnd();
			}

			virtual bool IsSuccess() const override
			{
				return m_entry->IsSuccess();
			}

			virtual void Add(IBehavior* behavior) override
			{
				m_entry = behavior;
			}

			virtual std::wstring Name() const override
			{
				return L"Root : " + m_entry->Name();
			}

		private:

			IBehavior* m_entry;
		};
	}
}
