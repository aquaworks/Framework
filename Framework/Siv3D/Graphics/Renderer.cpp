# include "Renderer.hpp"

# include <Siv3D.hpp>

namespace Graphics
{
	void Renderer::Render(Shape::Box const& shape, Transform::Pose const& pose) const
	{
		auto&& reshape = shape.Reshape(pose);

		Transform::Vector3 translation = reshape.origin.position;
		Transform::Vector3 scaling = reshape.size * reshape.origin.scaling;
		Transform::Quaternion rotation = reshape.origin.rotation;

		s3d::Vec3 pos { translation.x, translation.y, translation.z };
		s3d::Vec3 size { scaling.x, scaling.y, scaling.z };
		s3d::Quaternion rotate { rotation.x, rotation.y, rotation.z, rotation.w };

		s3d::Box(pos, size, rotate).draw();
	}
}
