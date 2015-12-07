# pragma once

# include "Shape/Box.hpp"

namespace Graphics
{
	class Renderer
	{
	public:

		void Render(Shape::Box const& shape, Transform::Pose const& pose) const;
	};
}
