# pragma once

namespace Behavior
{
	class IDecorator
	{
	public:

		virtual void Initialize() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Finalize() = 0;
		virtual bool IsSuccess() const = 0;
	};
}
