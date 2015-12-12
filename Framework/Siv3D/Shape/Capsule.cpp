# include "Capsule.hpp"

# include <Siv3D.hpp>

namespace Shape
{
	Capsule::Capsule(Transform::Pose const& origin, Transform::Vector3 const& begin, Transform::Vector3 const& end, float radius)
		: IShape(origin)
		, begin(begin)
		, end(end)
		, radius(radius)
	{

	}
	bool Capsule::Intersects(IShape const& shape) const
	{
		(void)shape;
		return true;
	}

	ShapePtr Capsule::Reshape(Transform::Pose const& pose) const
	{
		return std::make_shared<Capsule>(origin * pose, begin, end, radius);
	}

	void Capsule::Render() const
	{
		s3d::Vec3 from;
		from.x = begin.x;
		from.y = begin.y;
		from.z = begin.z;
		s3d::Vec3 to;
		to.x = end.x;
		to.y = end.y;
		to.z = end.z;
		double r = radius;

		s3d::Cylinder(from, to, r).draw();
		s3d::Sphere(from, r).draw();
		s3d::Sphere(to, r).draw();
	}
}
