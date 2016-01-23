# pragma once

# include "Transform/Pose.hpp"

# include "ShapePtr.hpp"

namespace Shapes
{
	class IShape
	{
	public:

		static ShapePtr Empty();

	public:

		IShape(Transform::Pose const& origin);

	public:

		virtual bool Intersects(IShape const& shape) const;
		virtual ShapePtr Reshape(Transform::Pose const& pose) const;
		virtual void Render(Transform::Vector4 const& color = Transform::Vector4::One()) const;
		virtual ShapePtr BoundingSphere() const;
		
	public:

		Transform::Pose origin;
	};
}
