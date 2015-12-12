# pragma once

# include "IShape.hpp"

namespace Shape
{
	class Segment : public IShape
	{
	public:

		Segment(Transform::Pose const& origin, Transform::Vector3 const& begin, Transform::Vector3 const& end);

	public:

		virtual bool Intersects(IShape const& shape) const override;
		virtual ShapePtr Reshape(Transform::Pose const& pose) const override;
		virtual void Render(Transform::Vector4 const& color) const override;
		virtual ShapePtr BoundingSphere() const override;

	public:

		Transform::Vector3 begin;
		Transform::Vector3 end;
	};
}
