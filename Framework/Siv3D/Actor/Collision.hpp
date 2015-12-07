# pragma once

# include <Siv3D.hpp>

namespace Collision
{
	// 頂点データ
	struct Vertex
	{
	public:
		Vertex(Vec3 const& posiiton, Vec3 const& normal)
			: position(position)
			, normal(normal)
		{

		}
	public:
		Vec3 position;
		Vec3 normal;
	};

	// 衝突情報
	struct HitInfo
	{
	public:
		HitInfo()
			: contact()
		{

		}
		HitInfo(std::initializer_list<Vertex>&& list)
			: contact(std::move(list))
		{

		}
		HitInfo(HitInfo&& info)
			: contact(std::move(info.contact))
		{

		}
		operator bool() const
		{
			return contact.empty();
		}
	public:
		std::vector<Vertex> contact;
	};

	bool Penetration(Ray const& ray, Polygon const& polygon)
	{
		
	}

	// 点がポリゴン内に存在するか
	bool Contains(Vec3 const& point, std::vector<Vec3> const& polygon)
	{
		size_t size = polygon.size();
		std::vector<float> f(size);
		for (size_t i = 0; i < size; ++i)
		{
			Vec3 p1 = polygon.at(i);
			Vec3 p2 = polygon.at((i + 1) % size);
			Vec3 v1 = p2 - p1;
			Vec3 v2 = point - p2;
			f[i] = v1.dot(v2);
		}

		for (size_t i = 0; i < size; ++i)
		{
			if (f[i] * f[i] < 0.0f)
			{
				return false;
			}
		}

		return true;
	}
}
