# pragma once

# include "IShape.hpp"

namespace Shape
{
	class Sphere : public IShape
	{
	public:

		Sphere(Transform::Pose const& origin, float radius);

	public:

		virtual bool Intersects(IShape const& shape) const override;
		virtual ShapePtr Reshape(Transform::Pose const& pose) const override;
		virtual void Render(Transform::Vector4 const& color) const override;
		virtual ShapePtr BoundingSphere() const override;

	public:

		float radius;
	};
}
