# pragma once

# include "IShape.hpp"

# include "../Transform/Vector2.hpp"

# include <vector>

namespace Aquaworks
{
	namespace Shapes
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

			using VertexBuffer = std::vector<Vertex>;
			using PositionBuffer = std::vector<Transform::Vector3>;
			using IndexBuffer = std::vector<std::uint32_t>;

		public:

			static ShapePtr Box(Transform::Vector3 const& size);
			static ShapePtr BoxNormal(Transform::Vector3 const& size);
			static ShapePtr BoxCompositeNormal(Transform::Vector3 const& size);
			static ShapePtr Plane(Transform::Vector2 const& size);

		public:

			Mesh(Transform::Pose const& origin, VertexBuffer const& vertices, IndexBuffer const& indices);
			Mesh(Transform::Pose const& origin, PositionBuffer const& vertices, IndexBuffer const& indices);

		public:

			virtual ShapePtr Reshape(Transform::Pose const& pose) const override;
			virtual void Render(Transform::Vector4 const& color) const override;
			virtual ShapePtr BoundingSphere() const override;

		public:

			virtual bool Intersects(ShapePtr const& shape) const override;
			virtual bool Intersects(IShape const& shape) const override;
			virtual bool Intersects(Sphere const& shape) const override;
			virtual bool Intersects(Capsule const& shape) const override;
			virtual bool Intersects(Segment const& shape) const override;
			virtual bool Intersects(Mesh const& shape) const override;

		private:

			void ComputeNormal();

		public:

			VertexBuffer vertices;
			IndexBuffer indices;
		};
	}
}
