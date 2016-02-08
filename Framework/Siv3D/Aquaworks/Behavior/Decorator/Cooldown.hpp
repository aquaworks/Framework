# pragma once

# include "IDecorator.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class Cooldown : public IDecorator
		{
		public:

			Cooldown(f32 cooldown)
				: m_cooldown(cooldown)
				, m_elapsedTime(0.0f)
			{

			}

			virtual void Initialize() override
			{
				m_elapsedTime = 0.0f;
			}

			virtual void Update(f32 deltaTime) override
			{
				m_elapsedTime -= deltaTime;
			}

			virtual void Finalize() override
			{
				m_elapsedTime = m_cooldown;
			}

			virtual bool IsSuccess() const override
			{
				return m_elapsedTime <= 0.0f;
			}

		private:

			f32 const m_cooldown;
			f32 m_elapsedTime;
		};
	}
}
