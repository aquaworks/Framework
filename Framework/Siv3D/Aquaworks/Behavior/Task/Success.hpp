# pragma once

# include "ITask.hpp"

namespace Aquaworks
{
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

			virtual void Update(f32 deltaTime) override
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
}
