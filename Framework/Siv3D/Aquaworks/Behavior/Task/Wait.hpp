# pragma once

# include "ITask.hpp"

# include "../../Utility/String.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class Wait : public ITask
		{
		public:

			Wait(float waitTime)
				: m_waitTime(waitTime)
				, m_remainTime(waitTime)
			{

			}

		public:

			virtual void Initialize() override
			{
				m_remainTime = m_waitTime;
			}

			virtual void Update(float deltaTime) override
			{
				m_remainTime -= deltaTime;
			}

			virtual bool IsEnd() const override
			{
				return m_remainTime <= 0.0f;
			}

			virtual bool IsSuccess() const override
			{
				return m_remainTime <= 0.0f;
			}

			virtual std::wstring Name() const override
			{
				return L"Wait" + Utility::String::Create(m_remainTime);
			}

		private:

			float m_waitTime;
			float m_remainTime;
		};
	}
}
