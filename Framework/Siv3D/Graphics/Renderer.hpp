# pragma once

# include "Shape/IShape.hpp"

namespace Graphics
{
	class Renderer
	{
	public:

		void Render(Shape::ShapePtr const& shape, Transform::Pose const& pose) const;
	};
}
