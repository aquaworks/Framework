# pragma once

# include "../Shapes/IShape.hpp"

namespace Aquaworks
{
	namespace Graphics
	{
		class Renderer
		{
		public:

			void Render(Shapes::ShapePtr const& shape, Transform::Pose const& pose) const;
		};
	}
}
