# include "Mesh.hpp"

# include "../Utility/Math.hpp"

# include "Sphere.hpp"

# include "../Physics/Collision.hpp"

# include <Siv3D.hpp>

namespace Aquaworks
{
	namespace Shapes
	{
		Vertex::Vertex(Transform::Vector3 const& position, Transform::Vector3 const& normal, Transform::Vector2 const& texcoord)
			: position(position)
			, normal(normal)
			, texcoord(texcoord)
		{

		}

		ShapePtr Mesh::Box(Transform::Vector3 const& size)
		{
			PositionBuffer vertices
			{
				{ -size.x, -size.y, -size.z },
				{ -size.x, size.y, -size.z },
				{ size.x, size.y, -size.z },
				{ size.x, -size.y, -size.z },
				{ size.x, -size.y, size.z },
				{ size.x, size.y, size.z },
				{ -size.x, size.y, size.z },
				{ -size.x, -size.y, size.z },
			};
			IndexBuffer indices
			{
				// 前面
				0, 1, 2,
				3, 0, 2,
				// 背面
				4, 5, 6,
				7, 4, 6,
				// 左面
				7, 6, 1,
				0, 7, 1,
				// 右面
				3, 2, 5,
				4, 3, 5,
				// 上面
				1, 6, 5,
				2, 1, 5,
				// 下面
				7, 0, 3,
				4, 7, 3,
			};

			return std::make_shared<Mesh>(Transform::Pose::Identity(), vertices, indices);
		}

		ShapePtr Mesh::BoxNormal(Transform::Vector3 const& size)
		{
			Transform::Vector3 const normal = Transform::Vector3::Zero();
			PositionBuffer position
			{
				{ -size.x, -size.y, -size.z },
				{ -size.x, +size.y, -size.z },
				{ +size.x, +size.y, -size.z },
				{ +size.x, -size.y, -size.z },
				{ +size.x, -size.y, +size.z },
				{ +size.x, +size.y, +size.z },
				{ -size.x, +size.y, +size.z },
				{ -size.x, -size.y, +size.z },
			};
			std::vector<Transform::Vector2> texcoord
			{
				{ 0.0f, 1.0f },
				{ 0.0f, 0.0f },
				{ 1.0f, 1.0f },
				{ -.0f, 1.0f },
			};

			VertexBuffer vertices
			{
				// 前面
				{ position[0], normal, texcoord[0] },
				{ position[1], normal, texcoord[1] },
				{ position[2], normal, texcoord[2] },
				{ position[3], normal, texcoord[3] },

				// 背面
				{ position[4], normal, texcoord[0] },
				{ position[5], normal, texcoord[1] },
				{ position[6], normal, texcoord[2] },
				{ position[7], normal, texcoord[3] },

				// 左面
				{ position[7], normal, texcoord[0] },
				{ position[6], normal, texcoord[1] },
				{ position[1], normal, texcoord[2] },
				{ position[0], normal, texcoord[3] },

				// 右面
				{ position[3], normal, texcoord[0] },
				{ position[2], normal, texcoord[1] },
				{ position[5], normal, texcoord[2] },
				{ position[4], normal, texcoord[3] },

				// 上面
				{ position[1], normal, texcoord[0] },
				{ position[6], normal, texcoord[1] },
				{ position[5], normal, texcoord[2] },
				{ position[2], normal, texcoord[3] },

				// 下面
				{ position[7], normal, texcoord[0] },
				{ position[0], normal, texcoord[1] },
				{ position[3], normal, texcoord[2] },
				{ position[4], normal, texcoord[3] },
			};

			IndexBuffer indices
			{
				// 前面
				0, 1, 2,
				3, 0, 2,
				// 背面
				4, 5, 6,
				7, 4, 6,
				// 左面
				8, 9, 10,
				11, 8, 10,
				// 右面
				12, 13, 14,
				15, 12, 14,
				// 上面
				16, 17, 18,
				19, 16, 18,
				// 下面
				20, 21, 22,
				23, 20, 22,
			};

			auto&& shape = std::make_shared<Mesh>(Transform::Pose::Identity(), vertices, indices);

			shape->ComputeNormal();

			return shape;
		}

		ShapePtr Mesh::BoxCompositeNormal(Transform::Vector3 const& size)
		{
			// 座標と法線のみを持つ頂点
			struct SimpleVertex
			{
				Transform::Vector3 position;
				Transform::Vector3 normal;
				SimpleVertex(Transform::Vector3 const& position, Transform::Vector3 const& normal)
					: position(position)
					, normal(normal)
				{

				}
			};

			// デフォルト法線
			Transform::Vector3 const Normal = Transform::Vector3::Zero();

			// 頂点座標
			PositionBuffer positions
			{
				{ -size.x, -size.y, -size.z },
				{ -size.x, +size.y, -size.z },
				{ +size.x, +size.y, -size.z },
				{ +size.x, -size.y, -size.z },
				{ +size.x, -size.y, +size.z },
				{ +size.x, +size.y, +size.z },
				{ -size.x, +size.y, +size.z },
				{ -size.x, -size.y, +size.z },
			};

			// 頂点を構築
			std::vector<SimpleVertex> simpleVertices;
			simpleVertices.reserve(positions.size());
			for (auto&& position : positions)
			{
				simpleVertices.emplace_back(position, Normal);
			}

			// 頂点のみを考慮した添字
			IndexBuffer indices
			{
				0, 1, 2,
				3, 0, 2,
				4, 5, 6,
				7, 4, 6,
				7, 6, 1,
				0, 7, 1,
				3, 2, 5,
				4, 3, 5,
				1, 6, 5,
				2, 1, 5,
				7, 0, 3,
				4, 7, 3,
			};

			// 法線の構築
			for (size_t i = 0; i < indices.size();)
			{
				SimpleVertex& v1 = simpleVertices.at(indices.at(i++));
				SimpleVertex& v2 = simpleVertices.at(indices.at(i++));
				SimpleVertex& v3 = simpleVertices.at(indices.at(i++));
				Transform::Vector3 normal = Transform::Vector3::Normalize(
					Transform::Vector3::Cross(v2.position - v1.position, v3.position - v1.position));
				v1.normal = Transform::Vector3::Normalize(v1.normal + normal);
				v2.normal = Transform::Vector3::Normalize(v2.normal + normal);
				v3.normal = Transform::Vector3::Normalize(v3.normal + normal);
			}

			// テクスチャ座標
			std::vector<Transform::Vector2> texcoord
			{
				{ 0.0f, 1.0f },
				{ 0.0f, 0.0f },
				{ 1.0f, 1.0f },
				{ -.0f, 1.0f },
			};

			// テクスチャ座標を加える
			VertexBuffer vertices;
			vertices.reserve(indices.size());
			for (size_t i = 0; i < indices.size();)
			{
				SimpleVertex& v1 = simpleVertices.at(indices.at(i++));
				SimpleVertex& v2 = simpleVertices.at(indices.at(i++));
				SimpleVertex& v3 = simpleVertices.at(indices.at(i++));
				SimpleVertex& v4 = simpleVertices.at(indices.at(i++));
				i += 2;
				vertices.emplace_back(v1.position, v1.normal, texcoord[0]);
				vertices.emplace_back(v2.position, v2.normal, texcoord[1]);
				vertices.emplace_back(v3.position, v3.normal, texcoord[2]);
				vertices.emplace_back(v4.position, v4.normal, texcoord[3]);
			}

			return std::make_shared<Mesh>(Transform::Pose::Identity(), vertices, indices);
		}

		ShapePtr Mesh::Plane(Transform::Vector2 const& size)
		{
			PositionBuffer vertices
			{
				{ -size.x, 0.0f, -size.y },
				{ -size.x, 0.0f, size.y },
				{ size.x, 0.0f, size.y },
				{ size.x, 0.0f, -size.y },
			};
			IndexBuffer indices
			{
				// 前面
				0, 1, 2,
				3, 0, 2,
			};

			return std::make_shared<Mesh>(Transform::Pose::Identity(), vertices, indices);
		}

		Mesh::Mesh(Transform::Pose const& origin, VertexBuffer const& vertices, IndexBuffer const& indices)
			: IShape(origin)
			, vertices(vertices)
			, indices(indices)
		{

		}

		Mesh::Mesh(Transform::Pose const& origin, PositionBuffer const& vertices, IndexBuffer const& indices)
			: IShape(origin)
			, vertices()
			, indices(indices)
		{
			this->vertices.reserve(vertices.size());
			for (auto&& vertex : vertices)
			{
				this->vertices.emplace_back(vertex, Transform::Vector3::Zero(), Transform::Vector2::Zero());
			}
		}

		ShapePtr Mesh::Reshape(Transform::Pose const& pose) const
		{
			return std::make_shared<Mesh>(origin * pose, vertices, indices);
		}

		void Mesh::Render(Transform::Vector4 const& color) const
		{
			s3d::MeshData data;
			data.vertices.resize(vertices.size());
			int i = 0;
			s3d::Quaternion rotate { origin.rotation.x, origin.rotation.y, origin.rotation.z, origin.rotation.w };
			s3d::Vec3 pos { origin.position.x, origin.position.y, origin.position.z };
			for (auto&& vertex : vertices)
			{
				s3d::Vec3 position;
				position.x = vertex.position.x;
				position.y = vertex.position.y;
				position.z = vertex.position.z;
				position = rotate * position + pos;
				s3d::Vec3 normal;
				normal.x = vertex.normal.x;
				normal.y = vertex.normal.y;
				normal.z = vertex.normal.z;
				normal = rotate * normal;
				s3d::Vec2 texcoord;
				texcoord.x = vertex.texcoord.x;
				texcoord.y = vertex.texcoord.y;
				s3d::MeshVertex& v = data.vertices.at(i);
				v.position = position;
				v.normal = normal;
				v.texcoord = texcoord;
				++i;
			}
			data.indices = indices;
			s3d::ColorF col { color.r, color.g, color.b, color.a };

			s3d::DynamicMesh(data).draw(col);
		}

		ShapePtr Mesh::BoundingSphere() const
		{
			auto value = std::minmax_element(vertices.begin(), vertices.end(), [] (Vertex const& v1, Vertex const& v2)
			{
				return (v1.position.x + v1.position.y + v1.position.z) < (v2.position.x + v2.position.y + v2.position.z);
			});
			Transform::Vector3 const& min = value.first->position;
			Transform::Vector3 const& max = value.second->position;

			Transform::Vector3 center = max + min;

			Transform::Pose pose;
			pose.Move(origin.position + center);

			float r = Transform::Vector3::Length(max - center);

			return std::make_shared<Sphere>(pose, r);
		}

		bool Mesh::Intersects(ShapePtr const& shape) const
		{
			return shape->Intersects(*this);
		}

		bool Mesh::Intersects(IShape const& shape) const
		{
			(void)shape;
			return false;
		}

		bool Mesh::Intersects(Sphere const& shape) const
		{
			return Physics::Collision::SphereMesh(shape, *this);
		}

		bool Mesh::Intersects(Capsule const& shape) const
		{
			return Physics::Collision::CapsuleMesh(shape, *this);
		}

		bool Mesh::Intersects(Segment const& shape) const
		{
			return Physics::Collision::SegmentMesh(shape, *this);
		}

		bool Mesh::Intersects(Mesh const& shape) const
		{
			return Physics::Collision::MeshMesh(shape, *this);
		}

		void Mesh::ComputeNormal()
		{
			for (size_t i = 0; i < indices.size();)
			{
				Vertex& v1 = vertices.at(indices.at(i++));
				Vertex& v2 = vertices.at(indices.at(i++));
				Vertex& v3 = vertices.at(indices.at(i++));

				Transform::Vector3 normal = Transform::Vector3::Normalize(
					Transform::Vector3::Cross(v2.position - v1.position, v3.position - v1.position));

				v1.normal = Transform::Vector3::Normalize(v1.normal + normal);
				v2.normal = Transform::Vector3::Normalize(v2.normal + normal);
				v3.normal = Transform::Vector3::Normalize(v3.normal + normal);
			}
		}
	}
}
