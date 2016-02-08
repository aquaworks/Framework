# include "Point3.hpp"
# include "Point4.hpp"
# include "Vector3.hpp"

# include "../Utility/Math.hpp"

namespace Aquaworks
{
	namespace Transform
	{
		using namespace Utility;

		Point3 const& Point3::Zero()
		{
			static Point3 zero { 0, 0, 0 };
			return zero;
		}

		Point3 const& Point3::One()
		{
			static Point3 one { 1, 1, 1 };
			return one;
		}

		Point3 const& Point3::Left()
		{
			static Point3 left { -1, 0, 0 };
			return left;
		}

		Point3 const& Point3::Right()
		{
			static Point3 right { 1, 0, 0 };
			return right;
		}

		Point3 const& Point3::Up()
		{
			static Point3 up { 0, 1, 0 };
			return up;
		}

		Point3 const& Point3::Down()
		{
			static Point3 down { 0, -1, 0 };
			return down;
		}

		Point3 const& Point3::Forward()
		{
			static Point3 forward { 0, 0, 1 };
			return forward;
		}

		Point3 const& Point3::Backward()
		{
			static Point3 Backward { 0, 0, -1 };
			return Backward;
		}

		Point3::Point3()
			: Point3(0, 0, 0)
		{

		}

		Point3::Point3(Point3 const& v)
			: Point3(v.x, v.y, v.z)
		{

		}

		Point3::Point3(int x, int y, int z)
			: x(x)
			, y(y)
			, z(z)
		{

		}

		Point3::Point3(Point4 const& v)
			: Point3(v.x, v.y, v.z)
		{

		}

		Point3::Point3(Vector3 const& v)
			: Point3(
				static_cast<int>(v.x),
				static_cast<int>(v.y),
				static_cast<int>(v.z))
		{
		}

		Point3& Point3::operator = (Point3 const& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}

		Point3::operator int* ()
		{
			return elm;
		}

		Point3::operator int const* () const
		{
			return elm;
		}

		int Point3::Dot(Point3 const& v1, Point3 const& v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}

		Point3 Point3::Cross(Point3 const& v1, Point3 const& v2)
		{
			return Point3(
				v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x);
		}

		int Point3::LengthSquared(Point3 const& v)
		{
			return Dot(v, v);
		}

		f32 Point3::Length(Point3 const& v)
		{
			return Math::Sqrt((f32)LengthSquared(v));
		}

		bool operator == (Point3 const& v1, Point3 const& v2)
		{
			return
				v1.x == v2.x &&
				v1.y == v2.y &&
				v1.z == v2.z;
		}

		bool operator != (Point3 const& v1, Point3 const& v2)
		{
			return !(v1 == v2);
		}

		Point3 operator + (Point3 const& v)
		{
			return v;
		}

		Point3 operator - (Point3 const& v)
		{
			return Point3(-v.x, -v.y, -v.z);
		}

		Point3& operator += (Point3& v1, Point3 const& v2)
		{
			v1.x += v2.x;
			v1.y += v2.y;
			v1.z += v2.z;
			return v1;
		}

		Point3& operator -= (Point3& v1, Point3 const& v2)
		{
			v1.x -= v2.x;
			v1.y -= v2.y;
			v1.z -= v2.z;
			return v1;
		}

		Point3& operator *= (Point3& v1, Point3 const& v2)
		{
			v1.x *= v2.x;
			v1.y *= v2.y;
			v1.z *= v2.z;
			return v1;
		}

		Point3& operator *= (Point3& v, int s)
		{
			v.x *= s;
			v.y *= s;
			v.z *= s;
			return v;
		}

		Point3& operator /= (Point3& v1, Point3 const& v2)
		{
			v1.x /= v2.x;
			v1.y /= v2.y;
			v1.z /= v2.z;
			return v1;
		}

		Point3& operator /= (Point3& v, int s)
		{
			v.x /= s;
			v.y /= s;
			v.z /= s;
			return v;
		}

		Point3 operator + (Point3 const& v1, Point3 const& v2)
		{
			Point3 result = v1;
			return result += v2;
		}

		Point3 operator - (Point3 const& v1, Point3 const& v2)
		{
			Point3 result = v1;
			return result -= v2;
		}

		Point3 operator * (Point3 const& v1, Point3 const& v2)
		{
			Point3 result = v1;
			return result *= v2;
		}

		Point3 operator * (Point3 const& v, int s)
		{
			Point3 result = v;
			return result *= s;
		}

		Point3 operator * (int s, Point3 const& v)
		{
			return v * s;
		}

		Point3 operator / (Point3 const& v1, Point3 const& v2)
		{
			Point3 result = v1;
			return result /= v2;
		}

		Point3 operator / (Point3 const& v, int s)
		{
			Point3 result = v;
			return result /= s;
		}
	}
}
