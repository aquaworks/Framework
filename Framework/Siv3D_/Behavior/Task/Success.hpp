# pragma once

# include "ITask.hpp"

# include "Utility/String.hpp"

namespace Behavior
{
	class Succsess : public ITask
	{
	public:

		Succsess()
		{

		}

	public:

		virtual void Initialize() override
		{

		}

		virtual void Update(float deltaTime) override
		{
			(void)deltaTime;
		}

		virtual bool IsEnd() const override
		{
			return true;
		}

		virtual bool IsSuccess() const override
		{
			return true;
		}

		virtual std::wstring Name() const override
		{
			return L"Succsess";
		}
	};
}
