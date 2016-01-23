# include "Vector2.hpp"
# include "Vector3.hpp"
# include "Point2.hpp"

# include "Utility/Math.hpp"

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Transform
{
	using namespace Utility;

	Vector2 const& Vector2::Zero()
	{
		static Vector2 zero { 0.0f, 0.0f };
		return zero;
	}

	Vector2 const& Vector2::One()
	{
		static Vector2 one { 1.0f, 1.0f };
		return one;
	}

	Vector2 const& Vector2::Left()
	{
		static Vector2 left { -1.0f, 0.0f };
		return left;
	}

	Vector2 const& Vector2::Right()
	{
		static Vector2 right { 1.0f, 0.0f };
		return right;
	}

	Vector2 const& Vector2::Up()
	{
		static Vector2 up { 0.0f, -1.0f };
		return up;
	}

	Vector2 const& Vector2::Down()
	{
		static Vector2 down { 0.0f, 1.0f };
		return down;
	}

	Vector2::Vector2()
		: Vector2(0.0f, 0.0f)
	{

	}

	Vector2::Vector2(Vector2 const& v)
		: Vector2(v.x, v.y)
	{

	}

	Vector2::Vector2(float x, float y)
		: x(x)
		, y(y)
	{

	}

	Vector2::Vector2(Vector3 const& v)
		: Vector2(v.x, v.y)
	{

	}

	Vector2::Vector2(Point2 const& v)
		: Vector2(
			static_cast<float>(v.x),
			static_cast<float>(v.y))
	{

	}

	Vector2& Vector2::operator = (Vector2 const& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	Vector2::operator float* ()
	{
		return elm;
	}

	Vector2::operator const float* () const
	{
		return elm;
	}

	float Vector2::Dot(Vector2 const& v1, Vector2 const& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Vector2::Cross(Vector2 const& v1, Vector2 const& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

	float Vector2::LengthSquared(Vector2 const& v)
	{
		return Dot(v, v);
	}

	float Vector2::Length(Vector2 const& v)
	{
		return static_cast<float>(Math::Sqrt(LengthSquared(v)));
	}

	Vector2 Vector2::Nornalize(Vector2 const& v)
	{
		float lengthSq = LengthSquared(v);
		if (lengthSq == 0.0f)
		{
			return v;
		}

		return v / static_cast<float>(Math::Sqrt(lengthSq));
	}

	Vector2 Vector2::Rotate(Vector2 const& point, Vector2 const& origin, float angle)
	{
		return origin + (point - origin) * Vector2(
			Math::Cos(angle),
			Math::Sin(angle));
	}

	Vector2 Vector2::Projection(Vector2 const& v, Vector2 const& target)
	{
		Vector2 normal = Nornalize(target);
		return Dot(v, normal) * normal;
	}

	float Vector2::Angle(Vector2 const& v1, Vector2 const& v2)
	{
		return static_cast<float>(Math::Acos(Dot(Nornalize(v1), Nornalize(v2))));
	}

	bool operator == (Vector2 const& v1, Vector2 const& v2)
	{
		return
			v1.x == v2.x &&
			v1.y == v2.y;
	}

	bool operator != (Vector2 const& v1, Vector2 const& v2)
	{
		return !(v1 == v2);
	}

	Vector2 operator + (Vector2 const& v)
	{
		return v;
	}

	Vector2 operator - (Vector2 const& v)
	{
		return Vector2(-v.x, -v.y);
	}

	Vector2& operator += (Vector2& v1, Vector2 const& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	Vector2& operator -= (Vector2& v1, Vector2 const& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}

	Vector2& operator *= (Vector2& v1, Vector2 const& v2)
	{
		v1.x *= v2.x;
		v1.y *= v2.y;
		return v1;
	}

	Vector2& operator *= (Vector2& v, float s)
	{
		v.x *= s;
		v.y *= s;
		return v;
	}

	Vector2& operator /= (Vector2& v1, Vector2 const& v2)
	{
		v1.x /= v2.x;
		v1.y /= v2.y;
		return v1;
	}

	Vector2& operator /= (Vector2& v, float s)
	{
		v.x /= s;
		v.y /= s;
		return v;
	}

	Vector2 operator + (Vector2 const& v1, Vector2 const& v2)
	{
		Vector2 result = v1;
		return result += v2;
	}

	Vector2 operator - (Vector2 const& v1, Vector2 const& v2)
	{
		Vector2 result = v1;
		return result -= v2;
	}

	Vector2 operator * (Vector2 const& v1, Vector2 const& v2)
	{
		Vector2 result = v1;
		return result *= v2;
	}

	Vector2 operator * (Vector2 const& v, float s)
	{
		Vector2 result = v;
		return result *= s;
	}

	Vector2 operator * (float s, Vector2 const& v)
	{
		return v * s;
	}

	Vector2 operator / (Vector2 const& v1, Vector2 const& v2)
	{
		Vector2 result = v1;
		return result /= v2;
	}

	Vector2 operator / (Vector2 const& v, float s)
	{
		Vector2 result = v;
		return result /= s;
	}
}

# pragma warning (pop)
