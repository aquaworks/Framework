# include "Vector3.hpp"
# include "Vector4.hpp"
# include "Point3.hpp"

# include "../Utility/Math.hpp"

namespace Aquaworks
{
	namespace Transform
	{
		using namespace Utility;

		Vector3 const& Vector3::Zero()
		{
			static Vector3 zero { 0.0f, 0.0f, 0.0f };
			return zero;
		}

		Vector3 const& Vector3::One()
		{
			static Vector3 one { 1.0f, 1.0f, 1.0f };
			return one;
		}

		Vector3 const& Vector3::Left()
		{
			static Vector3 left { -1.0f, 0.0f, 0.0f };
			return left;
		}

		Vector3 const& Vector3::Right()
		{
			static Vector3 right { 1.0f, 0.0f, 0.0f };
			return right;
		}

		Vector3 const& Vector3::Up()
		{
			static Vector3 up { 0.0f, 1.0f, 0.0f };
			return up;
		}

		Vector3 const& Vector3::Down()
		{
			static Vector3 down { 0.0f, -1.0f, 0.0f };
			return down;
		}

		Vector3 const& Vector3::Forward()
		{
			static Vector3 forward { 0.0f, 0.0f, 1.0f };
			return forward;
		}

		Vector3 const& Vector3::Backward()
		{
			static Vector3 backward { 0.0f, 0.0f, -1.0f };
			return backward;
		}

		Vector3::Vector3()
			: Vector3(0.0f, 0.0f, 0.0f)
		{

		}

		Vector3::Vector3(Vector3 const& v)
			: Vector3(v.x, v.y, v.z)
		{

		}

		Vector3::Vector3(f32 x, f32 y, f32 z)
			: x(x)
			, y(y)
			, z(z)
		{

		}

		Vector3::Vector3(Vector4 const& v)
			: Vector3(v.x, v.y, v.z)
		{

		}

		Vector3::Vector3(Point3 const& v)
			: Vector3(
				static_cast<f32>(v.x),
				static_cast<f32>(v.y),
				static_cast<f32>(v.z))
		{

		}

		Vector3& Vector3::operator = (Vector3 const& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}

		f32 Vector3::Dot(Vector3 const& v1, Vector3 const& v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}

		Vector3 Vector3::Cross(Vector3 const& v1, Vector3 const& v2)
		{
			return Vector3(
				v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x);
		}

		f32 Vector3::LengthSquared(Vector3 const& v)
		{
			return Dot(v, v);
		}

		f32 Vector3::Length(Vector3 const& v)
		{
			return static_cast<f32>(Math::Sqrt(LengthSquared(v)));
		}

		Vector3 Vector3::Normalize(Vector3 const& v)
		{
			f32 lengthSq = LengthSquared(v);
			if (lengthSq == 0.0f)
			{
				return v;
			}

			return v / static_cast<f32>(Math::Sqrt(lengthSq));
		}

		Vector3 Vector3::Rotate(Vector3 const& point, Vector3 const& axis, f32 angle)
		{
			Vector3 v = Dot(point, axis) * Normalize(axis);
			return
				v +
				Math::Cos(angle) * (point - v) +
				Math::Sin(angle) * Cross(axis, point);
		}

		Vector3 Vector3::Projection(Vector3 const& v, Vector3 const& target)
		{
			Vector3 normal = Normalize(target);
			return Dot(v, normal) * normal;
		}

		f32 Vector3::Angle(Vector3 const& v1, Vector3 const& v2)
		{
			return static_cast<f32>(Math::Acos(Dot(Normalize(v1), Normalize(v2))));
		}

		Vector3 Vector3::Slerp(Vector3 const& start, Vector3 const& end, f32 t)
		{
			return Rotate(start, Cross(end, start), Angle(start, end) * t);
		}

		bool operator == (Vector3 const& v1, Vector3 const& v2)
		{
			return
				v1.x == v2.x &&
				v1.y == v2.y &&
				v1.z == v2.z;
		}

		bool operator != (Vector3 const& v1, Vector3 const& v2)
		{
			return !(v1 == v2);
		}

		Vector3 operator + (Vector3 const& v)
		{
			return v;
		}

		Vector3 operator - (Vector3 const& v)
		{
			return Vector3(-v.x, -v.y, -v.z);
		}

		Vector3& operator += (Vector3& v1, Vector3 const& v2)
		{
			v1.x += v2.x;
			v1.y += v2.y;
			v1.z += v2.z;
			return v1;
		}

		Vector3& operator -= (Vector3& v1, Vector3 const& v2)
		{
			v1.x -= v2.x;
			v1.y -= v2.y;
			v1.z -= v2.z;
			return v1;
		}

		Vector3& operator *= (Vector3& v1, Vector3 const& v2)
		{
			v1.x *= v2.x;
			v1.y *= v2.y;
			v1.z *= v2.z;
			return v1;
		}

		Vector3& operator *= (Vector3& v, f32 s)
		{
			v.x *= s;
			v.y *= s;
			v.z *= s;
			return v;
		}

		Vector3& operator /= (Vector3& v1, Vector3 const& v2)
		{
			v1.x /= v2.x;
			v1.y /= v2.y;
			v1.z /= v2.z;
			return v1;
		}

		Vector3& operator /= (Vector3& v, f32 s)
		{
			v.x /= s;
			v.y /= s;
			v.z /= s;
			return v;
		}

		Vector3 operator + (Vector3 const& v1, Vector3 const& v2)
		{
			Vector3 result = v1;
			return result += v2;
		}

		Vector3 operator - (Vector3 const& v1, Vector3 const& v2)
		{
			Vector3 result = v1;
			return result -= v2;
		}

		Vector3 operator * (Vector3 const& v1, Vector3 const& v2)
		{
			Vector3 result = v1;
			return result *= v2;
		}

		Vector3 operator * (Vector3 const& v, f32 s)
		{
			Vector3 result = v;
			return result *= s;
		}

		Vector3 operator * (f32 s, Vector3 const& v)
		{
			return v * s;
		}

		Vector3 operator / (Vector3 const& v1, Vector3 const& v2)
		{
			Vector3 result = v1;
			return result /= v2;
		}

		Vector3 operator / (Vector3 const& v, f32 s)
		{
			Vector3 result = v;
			return result /= s;
		}
	}
}
