# include "Point4.hpp"
# include "Point3.hpp"
# include "Vector4.hpp"

# include "Utility/Math.hpp"
# include "Utility/String.hpp"

namespace Transform
{
	using namespace Utility;

	Point4 const& Point4::zero()
	{
		static Point4 zero { 0, 0, 0, 0 };
		return zero;
	}

	Point4 const& Point4::one()
	{
		static Point4 one { 1, 1, 1, 1 };
		return one;
	}

	Point4::Point4()
		: Point4(0, 0, 0, 0)
	{

	}

	Point4::Point4(Point4 const& v)
		: Point4(v.x, v.y, v.z, v.w)
	{

	}

	Point4::Point4(int x, int y, int z, int w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{

	}

	Point4::Point4(Point3 const& v, int w)
		: Point4(v.x, v.y, v.z, w)
	{

	}

	Point4::Point4(Vector4 const& v)
		: Point4(
			static_cast<int>(v.x),
			static_cast<int>(v.y),
			static_cast<int>(v.z),
			static_cast<int>(v.w))
	{
	}

	Point4& Point4::operator = (Point4 const& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}

	Point4::operator int* ()
	{
		return elm;
	}

	Point4::operator int const* () const
	{
		return elm;
	}

	int Point4::Dot(Point4 const& v1, Point4 const& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	int Point4::LengthSquared(Point4 const& v)
	{
		return Dot(v, v);
	}

	float Point4::Length(Point4 const& v)
	{
		return Math::Sqrt((float)LengthSquared(v));
	}

	bool operator == (Point4 const& v1, Point4 const& v2)
	{
		return
			v1.x == v2.x &&
			v1.y == v2.y &&
			v1.z == v2.z &&
			v1.w == v2.w;
	}

	bool operator != (Point4 const& v1, Point4 const& v2)
	{
		return !(v1 == v2);
	}

	Point4 operator + (Point4 const& v)
	{
		return v;
	}

	Point4 operator - (Point4 const& v)
	{
		return Point4(-v.x, -v.y, -v.z, -v.w);
	}

	Point4& operator += (Point4& v1, Point4 const& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		v1.z += v2.z;
		v1.w += v2.w;
		return v1;
	}

	Point4& operator -= (Point4& v1, Point4 const& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
		v1.w -= v2.w;
		return v1;
	}

	Point4& operator *= (Point4& v1, Point4 const& v2)
	{
		v1.x *= v2.x;
		v1.y *= v2.y;
		v1.z *= v2.z;
		v1.w *= v2.w;
		return v1;
	}

	Point4& operator *= (Point4& v, int s)
	{
		v.x *= s;
		v.y *= s;
		v.z *= s;
		v.w *= s;
		return v;
	}

	Point4& operator /= (Point4& v1, Point4 const& v2)
	{
		v1.x /= v2.x;
		v1.y /= v2.y;
		v1.z /= v2.z;
		v1.w /= v2.w;
		return v1;
	}

	Point4& operator /= (Point4& v, int s)
	{
		v.x /= s;
		v.y /= s;
		v.z /= s;
		v.w /= s;
		return v;
	}

	Point4 operator + (Point4 const& v1, Point4 const& v2)
	{
		Point4 result = v1;
		return result += v2;
	}

	Point4 operator - (Point4 const& v1, Point4 const& v2)
	{
		Point4 result = v1;
		return result -= v2;
	}

	Point4 operator * (Point4 const& v1, Point4 const& v2)
	{
		Point4 result = v1;
		return result *= v2;
	}

	Point4 operator * (Point4 const& v, int s)
	{
		Point4 result = v;
		return result *= s;
	}

	Point4 operator * (int s, Point4 const& v)
	{
		return v * s;
	}

	Point4 operator / (Point4 const& v1, Point4 const& v2)
	{
		Point4 result = v1;
		return result /= v2;
	}

	Point4 operator / (Point4 const& v, int s)
	{
		Point4 result = v;
		return result /= s;
	}
}
