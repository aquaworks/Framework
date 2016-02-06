# include "Point2.hpp"
# include "Point3.hpp"
# include "Vector2.hpp"

# include "../Utility/Math.hpp"

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Aquaworks
{
	namespace Transform
	{
		using namespace Utility;

		Point2 const& Point2::Zero()
		{
			static Point2 zero { 0, 0 };
			return zero;
		}

		Point2 const& Point2::One()
		{
			static Point2 one { 1, 1 };
			return one;
		}

		Point2 const& Point2::Left()
		{
			static Point2 left { -1, 0 };
			return left;
		}

		Point2 const& Point2::Right()
		{
			static Point2 right { 1, 0 };
			return right;
		}

		Point2 const& Point2::Up()
		{
			static Point2 up { 0, -1 };
			return up;
		}

		Point2 const& Point2::Down()
		{
			static Point2 down { 0, 1 };
			return down;
		}

		Point2::Point2()
			: Point2(0, 0)
		{

		}

		Point2::Point2(Point2 const& v)
			: Point2(v.x, v.y)
		{

		}

		Point2::Point2(int x, int y)
			: x(x)
			, y(y)
		{

		}

		Point2::Point2(Point3 const& v)
			: Point2(v.x, v.y)
		{

		}

		Point2::Point2(Vector2 const& v)
			: Point2(
				static_cast<int>(v.x),
				static_cast<int>(v.y))
		{

		}

		Point2& Point2::operator = (Point2 const& v)
		{
			x = v.x;
			y = v.y;
			return *this;
		}

		Point2::operator int* ()
		{
			return elm;
		}

		Point2::operator int const* () const
		{
			return elm;
		}

		int Point2::Dot(Point2 const& v1, Point2 const& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		int Point2::Cross(Point2 const& v1, Point2 const& v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
		}

		int Point2::LengthSquared(Point2 const& v)
		{
			return Dot(v, v);
		}

		float Point2::Length(Point2 const& v)
		{
			return Math::Sqrt((float)LengthSquared(v));
		}

		bool operator == (Point2 const& v1, Point2 const& v2)
		{
			return
				v1.x == v2.x &&
				v1.y == v2.y;
		}

		bool operator != (Point2 const& v1, Point2 const& v2)
		{
			return !(v1 == v2);
		}

		Point2 operator + (Point2 const& v)
		{
			return v;
		}

		Point2 operator - (Point2 const& v)
		{
			return Point2(-v.x, -v.y);
		}

		Point2& operator += (Point2& v1, Point2 const& v2)
		{
			v1.x += v2.x;
			v1.y += v2.y;
			return v1;
		}

		Point2& operator -= (Point2& v1, Point2 const& v2)
		{
			v1.x -= v2.x;
			v1.y -= v2.y;
			return v1;
		}

		Point2& operator *= (Point2& v1, Point2 const& v2)
		{
			v1.x *= v2.x;
			v1.y *= v2.y;
			return v1;
		}

		Point2& operator *= (Point2& v, int s)
		{
			v.x *= s;
			v.y *= s;
			return v;
		}

		Point2& operator /= (Point2& v1, Point2 const& v2)
		{
			v1.x /= v2.x;
			v1.y /= v2.y;
			return v1;
		}

		Point2& operator /= (Point2& v, int s)
		{
			v.x /= s;
			v.y /= s;
			return v;
		}

		Point2 operator + (Point2 const& v1, Point2 const& v2)
		{
			Point2 result = v1;
			return result += v2;
		}

		Point2 operator - (Point2 const& v1, Point2 const& v2)
		{
			Point2 result = v1;
			return result -= v2;
		}

		Point2 operator * (Point2 const& v1, Point2 const& v2)
		{
			Point2 result = v1;
			return result *= v2;
		}

		Point2 operator * (Point2 const& v, int s)
		{
			Point2 result = v;
			return result *= s;
		}

		Point2 operator * (int s, Point2 const& v)
		{
			return v * s;
		}

		Point2 operator / (Point2 const& v1, Point2 const& v2)
		{
			Point2 result = v1;
			return result /= v2;
		}

		Point2 operator / (Point2 const& v, int s)
		{
			Point2 result = v;
			return result /= s;
		}
	}
}

# pragma warning (pop)
