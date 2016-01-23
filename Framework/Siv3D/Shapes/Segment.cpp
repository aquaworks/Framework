# include "Segment.hpp"

# include "Capsule.hpp"

# include <Siv3D.hpp>

namespace Shapes
{
	Segment::Segment(Transform::Pose const& origin, Transform::Vector3 const& begin, Transform::Vector3 const& end)
		: IShape(origin)
		, begin(begin)
		, end(end)
	{

	}
	bool Segment::Intersects(IShape const& shape) const
	{
		(void)shape;
		return false;
	}

	ShapePtr Segment::Reshape(Transform::Pose const& pose) const
	{
		return std::make_shared<Segment>(origin * pose, begin, end);
	}

	void Segment::Render(Transform::Vector4 const& color) const
	{
		Capsule(origin, begin, end, 0.01f).Render(color);
	}

	ShapePtr Segment::BoundingSphere() const
	{
		return Capsule(origin, begin, end, 0.01f).BoundingSphere();
	}
}
