# pragma once

# include "IShape.hpp"

namespace Shape
{
	class Box : public IShape<Box>
	{
	public:

		Box(Transform::Pose const& origin, Transform::Vector3 const& size)
			: IShape(origin)
			, size(size)
		{

		}

	public:

		virtual bool Intersects(IShape const& shape) const override
		{
			return true;
		}

		virtual Box Reshape(Transform::Pose const& transform) const override
		{
			return { transform, size };
		}

	public:

		Transform::Vector3 size;
	};
}
