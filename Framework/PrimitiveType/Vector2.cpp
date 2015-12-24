# include "Vector2.hpp"

# include "Utility/Math.hpp"

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Transform
{
	template <typename Type>
	Vector2D<Type> const& Vector2D<Type>::Zero()
	{
		static Vector2D zero { 0, 0 };
		return zero;
	}

	template <typename Type>
	Vector2D<Type> const& Vector2D<Type>::One()
	{
		static Vector2D one { 1, 1 };
		return one;
	}

	template <typename Type>
	Vector2D<Type> const& Vector2D<Type>::Left()
	{
		static Vector2D left { -1, 0 };
		return left;
	}

	template <typename Type>
	Vector2D<Type> const& Vector2D<Type>::Right()
	{
		static Vector2D right { 1, 0 };
		return right;
	}

	template <typename Type>
	Vector2D<Type> const& Vector2D<Type>::Up()
	{
		static Vector2D up { 0, -1 };
		return up;
	}

	template <typename Type>
	Vector2D<Type> const& Vector2D<Type>::Down()
	{
		static Vector2D down { 0, 1 };
		return down;
	}

	template <typename Type>
	Vector2D<Type>::Vector2D()
		: x(0)
		, y(0)
	{

	}
	template <typename Type>
	Vector2D<Type>::Vector2D(Vector2D<Type> const& v)
		: x(v.x)
		, y(v.y)
	{

	}

	template <typename Type>
	template <typename Other>
	Vector2D<Type>::Vector2D(Vector2D<Other> const& v)
		: x(static_cast<Type>(v.x))
		, y(static_cast<Type>(v.y))
	{

	}

	template <typename Type>
	Vector2D<Type>::Vector2D(Type const& x, Type const& y)
		: x(x)
		, y(y)
	{

	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator = (Vector2D<Type> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		return *this;
	}

	template <typename Type>
	Type Vector2D<Type>::Dot(Vector2D<Type> const& v1, Vector2D<Type> const& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	template <typename Type>
	Type Vector2D<Type>::Cross(Vector2D<Type> const& v1, Vector2D<Type> const& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

	template <typename Type>
	Type Vector2D<Type>::LengthSquared(Vector2D<Type> const& v)
	{
		return Vector2D::Dot(v, v);
	}

	template <typename Type>
	double Vector2D<Type>::Length(Vector2D<Type> const& v)
	{
		return Utility::Math::Sqrt(LengthSquared(v));
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::Normalize(Vector2D<Type> const& v)
	{
		Type lengthSquared = LengthSquared(v);
		if (lengthSquared == static_cast<Type>(0))
		{
			return v;
		}
		Vector2D result = v;
		return result /= static_cast<Type>(Utility::Math::Sqrt(lengthSquared));
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::Rotate(Vector2D<Type> const& point, Vector2D<Type> const& origin, double angle)
	{
		return origin + (point - origin) *
			Vector2D(
				static_cast<Type>(Utility::Math::Cos(angle)),
				static_cast<Type>(Utility::Math::Sin(angle)));
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::Projection(Vector2D<Type> const& v, Vector2D<Type> const& target)
	{
		Vector2D normal = Normalize(target);
		return normal * Dot(v, normal);
	}

	template <typename Type>
	double Vector2D<Type>::Angle(Vector2D<Type> const& v1, Vector2D<Type> const& v2)
	{
		return Utility::Math::Acos(Dot(Normalize(v1), Normalize(v2)));
	}

	template <typename Type>
	bool Vector2D<Type>::operator == (Vector2D<Type> const& v) const
	{
		return
			this->x == v.x &&
			this->y == v.y;
	}

	template <typename Type>
	bool Vector2D<Type>::operator != (Vector2D<Type> const& v) const
	{
		return !(*this == v);
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator + () const
	{
		return *this;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator - () const
	{
		return *this * -1;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator + (Vector2D<Type> const& v) const
	{
		return { this->x + v.x, this->y + v.y };
	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator += (Vector2D<Type> const& v)
	{
		this->x += v.x;
		this->y += v.y;
		return *this;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator - (Vector2D<Type> const& v) const
	{
		return { this->x - v.x, this->y - v.y };
	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator -= (Vector2D<Type> const& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		return *this;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator * (Vector2D<Type> const& v) const
	{
		return { this->x * v.x, this->y * v.y };
	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator *= (Vector2D<Type> const& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		return *this;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator * (Type const& x) const
	{
		return { this->x * x, this->y * x };
	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator *= (Type const& x)
	{
		this->x *= x;
		this->y *= x;
		return *this;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator / (Vector2D<Type> const& v) const
	{
		return { this->x / v.x, this->y / v.y };
	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator /= (Vector2D<Type> const& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		return *this;
	}

	template <typename Type>
	Vector2D<Type> Vector2D<Type>::operator / (Type const& x) const
	{
		return { this->x / x, this->y / x };
	}

	template <typename Type>
	Vector2D<Type>& Vector2D<Type>::operator /= (Type const& x)
	{
		this->x /= x;
		this->y /= x;
		return *this;
	}

	template Point2::Vector2D(Float2 const& v);
	template Point2::Vector2D(Vector2 const& v);
	template Float2::Vector2D(Point2 const& v);
	template Float2::Vector2D(Vector2 const& v);
	template Vector2::Vector2D(Point2 const& v);
	template Vector2::Vector2D(Float2 const& v);

	template class Vector2D<int>;
	template class Vector2D<float>;
	template class Vector2D<double>;
}

# pragma warning (pop)
