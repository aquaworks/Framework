# pragma once

# include "IDecorator.hpp"

namespace Behavior
{
	class Cooldown : public IDecorator
	{
	public:

		Cooldown(float cooldown)
			: m_cooldown(cooldown)
			, m_elapsedTime(0.0f)
		{

		}

		virtual void Initialize() override
		{
			m_elapsedTime = 0.0f;
		}

		virtual void Update(float deltaTime) override
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

		float const m_cooldown;
		float m_elapsedTime;
	};
}
