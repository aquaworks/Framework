# pragma once

# include "IDecorator.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class TimeLimit : public IDecorator
		{
		public:

			TimeLimit(float timeLimit)
				: m_timeLimit(timeLimit)
				, m_elapsedTime(timeLimit)
			{

			}

			virtual void Initialize() override
			{
				m_elapsedTime = m_timeLimit;
			}

			virtual void Update(float deltaTime) override
			{
				m_elapsedTime -= deltaTime;
			}

			virtual void Finalize() override
			{

			}

			virtual bool IsSuccess() const override
			{
				return m_elapsedTime > 0.0f;
			}

		private:

			float const m_timeLimit;
			float m_elapsedTime;
		};
	}
}
