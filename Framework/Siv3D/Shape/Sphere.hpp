# pragma once

# include "IShape.hpp"

namespace Collision
{
	class Sphere : public IShape
	{
	public:

		virtual bool Intersects(IShape const& shape) const override;
	};
}
