# pragma once

# include <string>

namespace Aquaworks
{
	namespace Behavior
	{
		class IBehavior
		{
		public:

			virtual void Initialize() = 0;
			virtual void Update(float deltaTime) = 0;
			virtual bool IsEnd() const = 0;
			virtual bool IsSuccess() const = 0;
			virtual void Add(IBehavior* behavior) = 0;
			virtual std::wstring Name() const = 0;
		};
	}
}
