# include "Renderer.hpp"

# include <Siv3D.hpp>

namespace Graphics
{
	void Renderer::Render(Shape::ShapePtr const& shape, Transform::Pose const& pose) const
	{
		shape->Reshape(pose)->Render();
	}
}
