# pragma once

# include "ITask.hpp"

namespace Aquaworks
{
	namespace Behavior
	{
		class Fail : public ITask
		{
		public:

			Fail()
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
				return false;
			}

			virtual std::wstring Name() const override
			{
				return L"Fail";
			}
		};
	}
}
