# include "Vector4.hpp"
# include "Vector3.hpp"
# include "Point4.hpp"

# include "Utility/Math.hpp"

namespace Transform
{
	using namespace Utility;

	Vector4 const& Vector4::Zero()
	{
		static Vector4 zero { 0.0f, 0.0f, 0.0f, 0.0f };
		return zero;
	}

	Vector4 const& Vector4::One()
	{
		static Vector4 one { 1.0f, 1.0f, 1.0f, 1.0f };
		return one;
	}

	Vector4::Vector4()
		: Vector4(0.0f, 0.0f, 0.0f, 0.0f)
	{

	}

	Vector4::Vector4(Vector4 const& v)
		: Vector4(v.x, v.y, v.z, v.w)
	{

	}

	Vector4::Vector4(float x, float y, float z, float w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{

	}

	Vector4::Vector4(Vector3 const& v, float w)
		: Vector4(v.x, v.y, v.z, w)
	{

	}

	Vector4::Vector4(Point4 const& v)
		: Vector4(
			static_cast<float>(v.x),
			static_cast<float>(v.y),
			static_cast<float>(v.z),
			static_cast<float>(v.w))
	{

	}

	Vector4& Vector4::operator = (Vector4 const& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}

	float Vector4::Dot(Vector4 const& v1, Vector4 const& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	float Vector4::LengthSquared(Vector4 const& v)
	{
		return Dot(v, v);
	}

	float Vector4::Length(Vector4 const& v)
	{
		return static_cast<float>(Math::Sqrt(LengthSquared(v)));
	}

	Vector4 Vector4::Normalize(Vector4 const& v)
	{
		float lengthSq = LengthSquared(v);
		if (lengthSq == 0.0f)
		{
			return v;
		}

		return v / static_cast<float>(Math::Sqrt(lengthSq));
	}

	Vector4 Vector4::Projection(Vector4 const& v, Vector4 const& target)
	{
		Vector4 normal = Normalize(target);
		return Dot(v, normal) * normal;
	}

	bool operator == (Vector4 const& v1, Vector4 const& v2)
	{
		return
			v1.x == v2.x &&
			v1.y == v2.y &&
			v1.z == v2.z &&
			v1.w == v2.w;
	}

	bool operator != (Vector4 const& v1, Vector4 const& v2)
	{
		return !(v1 == v2);
	}

	Vector4 operator + (Vector4 const& v)
	{
		return v;
	}

	Vector4 operator - (Vector4 const& v)
	{
		return Vector4(-v.x, -v.y, -v.z, -v.w);
	}

	Vector4& operator += (Vector4& v1, Vector4 const& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		v1.z += v2.z;
		v1.w += v2.w;
		return v1;
	}

	Vector4& operator -= (Vector4& v1, Vector4 const& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
		v1.w -= v2.w;
		return v1;
	}

	Vector4& operator *= (Vector4& v1, Vector4 const& v2)
	{
		v1.x *= v2.x;
		v1.y *= v2.y;
		v1.z *= v2.z;
		v1.w *= v2.w;
		return v1;
	}

	Vector4& operator *= (Vector4& v, float s)
	{
		v.x *= s;
		v.y *= s;
		v.z *= s;
		v.w *= s;
		return v;
	}

	Vector4& operator /= (Vector4& v1, Vector4 const& v2)
	{
		v1.x /= v2.x;
		v1.y /= v2.y;
		v1.z /= v2.z;
		v1.w /= v2.w;
		return v1;
	}

	Vector4& operator /= (Vector4& v, float s)
	{
		v.x /= s;
		v.y /= s;
		v.z /= s;
		v.w /= s;
		return v;
	}

	Vector4 operator + (Vector4 const& v1, Vector4 const& v2)
	{
		Vector4 result = v1;
		return result += v2;
	}

	Vector4 operator - (Vector4 const& v1, Vector4 const& v2)
	{
		Vector4 result = v1;
		return result -= v2;
	}

	Vector4 operator * (Vector4 const& v1, Vector4 const& v2)
	{
		Vector4 result = v1;
		return result *= v2;
	}

	Vector4 operator * (Vector4 const& v, float s)
	{
		Vector4 result = v;
		return result *= s;
	}

	Vector4 operator * (float s, Vector4 const& v)
	{
		return v * s;
	}

	Vector4 operator / (Vector4 const& v1, Vector4 const& v2)
	{
		Vector4 result = v1;
		return result /= v2;
	}

	Vector4 operator / (Vector4 const& v, float s)
	{
		Vector4 result = v;
		return result /= s;
	}
}
