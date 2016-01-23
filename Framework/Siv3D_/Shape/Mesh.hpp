# pragma once

# include "IShape.hpp"

# include "Transform/Vector2.hpp"

# include <vector>

namespace Shape
{
	struct Vertex
	{
		Transform::Vector3 position;
		Transform::Vector3 normal;
		Transform::Vector2 texcoord;
		Vertex(Transform::Vector3 const& position, Transform::Vector3 const& normal, Transform::Vector2 const& texcoord);
	};

	class Mesh : public IShape
	{
	public:

		static ShapePtr Box(Transform::Vector3 const& size);
		static ShapePtr BoxNormal(Transform::Vector3 const& size);
		static ShapePtr BoxCompositeNormal(Transform::Vector3 const& size);
		static ShapePtr Plane(Transform::Vector2 const& size);

	public:

		Mesh(Transform::Pose const& origin, std::vector<Vertex> const& vertices, std::vector<size_t> const& indices);
		Mesh(Transform::Pose const& origin, std::vector<Transform::Vector3> const& vertices, std::vector<size_t> const& indices);

	public:

		virtual bool Intersects(IShape const& shape) const override;
		virtual ShapePtr Reshape(Transform::Pose const& pose) const override;
		virtual void Render(Transform::Vector4 const& color) const override;
		virtual ShapePtr BoundingSphere() const override;

	private:

		void ComputeNormal();

	public:

		std::vector<Vertex> vertices;
		std::vector<size_t> indices;
	};
}
