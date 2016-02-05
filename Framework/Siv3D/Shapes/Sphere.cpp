# include "Sphere.hpp"

# include "Capsule.hpp"
# include "Segment.hpp"
# include "Mesh.hpp"

# include "Physics/Collision.hpp"

# include <Siv3D.hpp>

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Shapes
{
	Sphere::Sphere(Transform::Pose const& origin, float radius)
		: IShape(origin)
		, radius(radius)
	{

	}

	ShapePtr Sphere::Reshape(Transform::Pose const& pose) const
	{
		return std::make_shared<Sphere>(origin * pose, radius);
	}

	void Sphere::Render(Transform::Vector4 const& color) const
	{
		s3d::Vec3 pos;
		pos.x = origin.position.x;
		pos.y = origin.position.y;
		pos.z = origin.position.z;
		double r = radius;
		s3d::Quaternion rotation;
		rotation.component.m128_f32[0] = origin.rotation.x;
		rotation.component.m128_f32[1] = origin.rotation.y;
		rotation.component.m128_f32[2] = origin.rotation.z;
		rotation.component.m128_f32[3] = origin.rotation.w;
		s3d::ColorF col { color.r, color.g, color.b, color.a };

		s3d::Sphere(pos, r, rotation).draw(col);
	}

	ShapePtr Sphere::BoundingSphere() const
	{
		Transform::Pose pose;
		pose.Move(origin.position);
		return std::make_shared<Sphere>(pose, radius * origin.scaling.x);
	}

	bool Sphere::Intersects(ShapePtr const& shape) const
	{
		return shape->Intersects(*this);
	}

	bool Sphere::Intersects(IShape const& shape) const
	{
		(void)shape;
		return false;
	}

	bool Sphere::Intersects(Sphere const& shape) const
	{
		return Physics::Collision::SphereSphere(*this, shape);

		Transform::Vector3 center1 = origin.position;
		float radius1 = radius;
		Transform::Vector3 center2 = shape.origin.position;
		float radius2 = shape.radius;
		return Physics::Collision::SphereSphere(center1, radius1, center2, radius2);
	}

	bool Sphere::Intersects(Capsule const& shape) const
	{
		return Physics::Collision::SphereCapsule(*this, shape);

		Transform::Vector3 center = origin.position;
		float radius = this->radius + shape.radius;
		Transform::Vector3 begin = shape.begin * shape.origin;
		Transform::Vector3 end = shape.end * shape.origin;
		return Physics::Collision::SphereSegment(center, radius, begin, end);
	}

	bool Sphere::Intersects(Segment const& shape) const
	{
		return Physics::Collision::SphereSegment(*this, shape);

		Transform::Vector3 center = origin.position;
		float radius = this->radius;
		Transform::Vector3 begin = shape.begin * shape.origin;
		Transform::Vector3 end = shape.end * shape.origin;
		return Physics::Collision::SphereSegment(center, radius, begin, end);
	}

	bool Sphere::Intersects(Mesh const& shape) const
	{
		return Physics::Collision::SphereMesh(*this, shape);

		if (!IShape::Intersects(shape.BoundingSphere()))
		{
			return false;
		}

		Mesh::VertexBuffer const& vertices = shape.vertices;
		Mesh::IndexBuffer const& indices = shape.indices;

		Transform::Vector3 p0 = origin.position;

		for (size_t i = 0; i < indices.size(); i += 3)
		{
			Transform::Vector3 p1 = vertices.at(i).position;
			Transform::Vector3 p2 = vertices.at(i + 1).position;
			Transform::Vector3 p3 = vertices.at(i + 2).position;

			Transform::Vector3 a = p2 - p1;
			Transform::Vector3 b = p3 - p1;
			Transform::Vector3 c = p1 - p0;
			Transform::Vector3 n = Transform::Vector3::Normalize(Transform::Vector3::Cross(a, b));
			float length = Transform::Vector3::Dot(c, n);
			Transform::Vector3 point = p0 + n * length;

			if (Physics::Collision::PolygonInside({ p1, p2, p3 }, point))
			{
				return true;
			}
		}

		return false;
	}
}

# pragma warning (pop)
