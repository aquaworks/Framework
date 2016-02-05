# include "Segment.hpp"

# include "Sphere.hpp"

# include "Physics/Collision.hpp"

# include <Siv3D.hpp>

namespace Shapes
{
	Segment::Segment(Transform::Pose const& origin, Transform::Vector3 const& begin, Transform::Vector3 const& end)
		: IShape(origin)
		, begin(begin)
		, end(end)
	{

	}

	ShapePtr Segment::Reshape(Transform::Pose const& pose) const
	{
		return std::make_shared<Segment>(origin * pose, begin, end);
	}

	void Segment::Render(Transform::Vector4 const& color) const
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
		s3d::ColorF col { color.r, color.g, color.b, color.a };

		s3d::Line3D(from, to).drawForward(col);
	}

	ShapePtr Segment::BoundingSphere() const
	{
		Transform::Pose pose;

		Transform::Matrix rotate = Transform::Quaternion::ToMatrix(origin.rotation);

		Transform::Vector3 center = origin.position + (begin + end) / 2.0f;
		pose.Move(center * rotate);

		float r = Transform::Vector3::Length(end - begin) / 2.0f;

		return std::make_shared<Sphere>(pose, r);
	}

	bool Segment::Intersects(ShapePtr const& shape) const
	{
		return shape->Intersects(*this);
	}

	bool Segment::Intersects(IShape const& shape) const
	{
		(void)shape;
		return false;
	}

	bool Segment::Intersects(Sphere const& shape) const
	{
		return Physics::Collision::SphereSegment(shape, *this);
	}

	bool Segment::Intersects(Capsule const& shape) const
	{
		return Physics::Collision::CapsuleSegment(shape, *this);
	}

	bool Segment::Intersects(Segment const& shape) const
	{
		return Physics::Collision::SegmentSegment(*this, shape);
	}

	bool Segment::Intersects(Mesh const& shape) const
	{
		return Physics::Collision::SegmentMesh(*this, shape);
	}
}
