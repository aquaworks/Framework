# pragma once

namespace Aquaworks
{
	namespace Behavior
	{
		class IDecorator
		{
		public:

			virtual void Initialize() = 0;
			virtual void Update(f32 deltaTime) = 0;
			virtual void Finalize() = 0;
			virtual bool IsSuccess() const = 0;
		};
	}
}
