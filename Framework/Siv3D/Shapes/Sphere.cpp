# include "Sphere.hpp"

# include <Siv3D.hpp>

namespace Shapes
{
	Sphere::Sphere(Transform::Pose const& origin, float radius)
		: IShape(origin)
		, radius(radius)
	{

	}

	bool Sphere::Intersects(IShape const& shape) const
	{
		(void)shape;
		return true;
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
}
