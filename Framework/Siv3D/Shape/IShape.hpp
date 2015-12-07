# pragma once

# include "Transform/Pose.hpp"

namespace Shape
{
	template <typename ShapeType>
	class IShape
	{
	public:

		IShape(Transform::Pose const& origin)
			: origin(origin)
		{

		}

	public:

		virtual bool Intersects(IShape const& shape) const = 0;

		virtual ShapeType Reshape(Transform::Pose const& transform) const = 0;

	public:

		Transform::Pose origin;
	};
}
