# include "Capsule.hpp"

# include "Sphere.hpp"

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

	void Capsule::Render(Transform::Vector4 const& color) const
	{
		s3d::Quaternion rotate { origin.rotation.x, origin.rotation.y, origin.rotation.z, origin.rotation.w };
		s3d::Vec3 pos { origin.position.x, origin.position.y, origin.position.z };
		s3d::Vec3 from;
		from.x = begin.x;
		from.y = begin.y;
		from.z = begin.z;
		from = rotate * from + pos;
		s3d::Vec3 to;
		to.x = end.x;
		to.y = end.y;
		to.z = end.z;
		to = rotate * to + pos;
		double r = radius;
		s3d::ColorF col { color.r, color.g, color.b, color.a };

		s3d::Cylinder(from, to, r).draw(s3d::Palette::Red);
		s3d::Sphere(from, r, rotate).draw(s3d::Palette::Green);
		s3d::Sphere(to, r, rotate).draw(s3d::Palette::Blue);
	}

	ShapePtr Capsule::BoundingSphere() const
	{
		Transform::Pose pose;

		Transform::Matrix rotate = Transform::Quaternion::ToMatrix(origin.rotation);

		Transform::Vector3 center = origin.position + (begin + end) / 2.0f;
		pose.Move(center * rotate);

		float r = Transform::Vector3::Length(end - begin) / 2.0f + radius;

		return std::make_shared<Sphere>(pose, r);
	}
}
