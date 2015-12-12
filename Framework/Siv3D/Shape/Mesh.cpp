# include "Mesh.hpp"

# include <Siv3D.hpp>

namespace Shape
{
	Vertex::Vertex(Transform::Vector3 const& position, Transform::Vector3 const& normal, Transform::Vector2 const& texcoord)
		: position(position)
		, normal(normal)
		, texcoord(texcoord)
	{

	}

	ShapePtr Mesh::Box(Transform::Vector3 const& size)
	{
		Transform::Vector3 const normal = Transform::Vector3::Zero();
		std::vector<Transform::Vector3> position
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

		std::vector<Vertex> vertices
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

		std::vector<size_t> indices
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

		auto&& shape = std::make_shared<Mesh>(Transform::Pose::Empty(), vertices, indices);

		shape->ComputeNormal();

		return shape;
		/*
		std::vector<Transform::Vector3> vertices
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
		std::vector<size_t> indices
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

		return std::make_shared<Mesh>(Transform::Pose::Empty(), vertices, indices);*/
	}

	ShapePtr Mesh::Plane(Transform::Vector2 const& size)
	{
		std::vector<Transform::Vector3> vertices
		{
			{ -size.x, 0.0f, -size.y },
			{ -size.x, 0.0f, size.y },
			{ size.x, 0.0f, size.y },
			{ size.x, 0.0f, -size.y },
		};
		std::vector<size_t> indices
		{
			// 前面
			0, 1, 2,
			3, 0, 2,
		};

		return std::make_shared<Mesh>(Transform::Pose::Empty(), vertices, indices);
	}

	Mesh::Mesh(Transform::Pose const& origin, std::vector<Vertex> const& vertices, std::vector<size_t> const& indices)
		: IShape(origin)
		, vertices(vertices)
		, indices(indices)
	{

	}

	Mesh::Mesh(Transform::Pose const& origin, std::vector<Transform::Vector3> const& vertices, std::vector<size_t> const& indices)
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
	bool Mesh::Intersects(IShape const& shape) const
	{
		(void)shape;
		return true;
	}

	ShapePtr Mesh::Reshape(Transform::Pose const& pose) const
	{
		return std::make_shared<Mesh>(origin * pose, vertices, indices);
	}

	void Mesh::Render() const
	{
		s3d::MeshData data;
		data.vertices.resize(vertices.size());
		int i = 0;
		for (auto&& vertex : vertices)
		{
			s3d::Vec3 position;
			position.x = vertex.position.x;
			position.y = vertex.position.y;
			position.z = vertex.position.z;
			s3d::Vec3 normal;
			normal.x = vertex.normal.x;
			normal.y = vertex.normal.y;
			normal.z = vertex.normal.z;
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

		s3d::DynamicMesh(data).draw();
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
