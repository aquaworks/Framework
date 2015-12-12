# pragma once

# include "Transform/Pose.hpp"

# include "SharePtr.hpp"

namespace Shape
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
		virtual void Render() const;
		
	public:

		Transform::Pose origin;
	};
}
