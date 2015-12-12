# include "IShape.hpp"

namespace Shape
{
	ShapePtr IShape::Empty()
	{
		return std::make_shared<IShape>(Transform::Pose::Identity());
	}

	IShape::IShape(Transform::Pose const& origin)
		: origin(origin)
	{

	}

	bool IShape::Intersects(IShape const& shape) const
	{
		(void)shape;
		return false;
	}

	ShapePtr IShape::Reshape(Transform::Pose const& pose) const
	{
		return std::make_shared<IShape>(origin * pose);
	}

	void IShape::Render() const
	{
		
	}
}
