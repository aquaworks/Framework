# include "Sphere.hpp"

# include <Siv3D.hpp>

namespace Shape
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

	void Sphere::Render() const
	{
		s3d::Vec3 pos;
		pos.x = origin.position.x;
		pos.y = origin.position.y;
		pos.z = origin.position.z;
		double r = radius;
		s3d::Quaternion rotation;
		rotation.component.fv.x = origin.rotation.x;
		rotation.component.fv.y = origin.rotation.y;
		rotation.component.fv.z = origin.rotation.z;
		rotation.component.fv.w = origin.rotation.w;

		s3d::Sphere(pos, r, rotation).draw();
	}
}
