# pragma once

# include "Shapes/IShape.hpp"

namespace Graphics
{
	class Renderer
	{
	public:

		void Render(Shapes::ShapePtr const& shape, Transform::Pose const& pose) const;
	};
}
