# pragma once

# include "IShape.hpp"

namespace Aquaworks
{
	namespace Shapes
	{
		class Capsule : public IShape
		{
		public:

			Capsule(Transform::Pose const& origin, Transform::Vector3 const& begin, Transform::Vector3 const& end, f32 radius);

		public:

			virtual ShapePtr Reshape(Transform::Pose const& pose) const override;
			virtual void Render(Transform::Vector4 const& color) const override;
			virtual ShapePtr BoundingSphere() const override;

		public:

			virtual bool Intersects(ShapePtr const& shape) const override;
			virtual bool Intersects(IShape const& shape) const override;
			virtual bool Intersects(Sphere const& shape) const override;
			virtual bool Intersects(Capsule const& shape) const override;
			virtual bool Intersects(Segment const& shape) const override;
			virtual bool Intersects(Mesh const& shape) const override;

		public:

			Transform::Vector3 begin;
			Transform::Vector3 end;
			f32 radius;
		};
	}
}
