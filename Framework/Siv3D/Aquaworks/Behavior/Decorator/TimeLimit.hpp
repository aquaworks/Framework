# pragma once

# include "IDecorator.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class TimeLimit : public IDecorator
		{
		public:

			TimeLimit(f32 timeLimit)
				: m_timeLimit(timeLimit)
				, m_elapsedTime(timeLimit)
			{

			}

			virtual void Initialize() override
			{
				m_elapsedTime = m_timeLimit;
			}

			virtual void Update(f32 deltaTime) override
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

			f32 const m_timeLimit;
			f32 m_elapsedTime;
		};
	}
}
