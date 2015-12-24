# include "Vector3.hpp"

# include "Vector4.hpp"

# include "Utility/Math.hpp"

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Transform
{
	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Zero()
	{
		static Vector3D zero { 0, 0, 0 };
		return zero;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::One()
	{
		static Vector3D one { 1, 1, 1 };
		return one;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Left()
	{
		static Vector3D left { -1, 0, 0 };
		return left;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Right()
	{
		static Vector3D right { 1, 0, 0 };
		return right;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Up()
	{
		static Vector3D up { 0, 1, 0 };
		return up;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Down()
	{
		static Vector3D down { 0, -1, 0 };
		return down;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Forward()
	{
		static Vector3D forward { 0, 0, 1 };
		return forward;
	}

	template <typename Type>
	Vector3D<Type> const& Vector3D<Type>::Backward()
	{
		static Vector3D backward { 0, 0, -1 };
		return backward;
	}

	template <typename Type>
	Vector3D<Type>::Vector3D()
		: x(0)
		, y(0)
		, z(0)
	{

	}
	template <typename Type>
	Vector3D<Type>::Vector3D(Vector3D<Type> const& v)
		: x(v.x)
		, y(v.y)
		, z(v.z)
	{

	}

	template <typename Type>
	template <typename Other>
	Vector3D<Type>::Vector3D(Vector3D<Other> const& v)
		: x(static_cast<Type>(v.x))
		, y(static_cast<Type>(v.y))
		, z(static_cast<Type>(v.z))
	{

	}

	template <typename Type>
	Vector3D<Type>::Vector3D(Vector4D<Type> const& v)
		: x(v.x)
		, y(v.y)
		, z(v.z)
	{

	}

	template <typename Type>
	Vector3D<Type>::Vector3D(Type const& x, Type const& y, Type const& z)
		: x(x)
		, y(y)
		, z(z)
	{

	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator = (Vector3D<Type> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}

	template <typename Type>
	Type Vector3D<Type>::Dot(Vector3D<Type> const& v1, Vector3D<Type> const& v2)
	{
		return v1.x * v2.x + v1.y * v2.y * v1.z * v2.z;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::Cross(Vector3D<Type> const& v1, Vector3D<Type> const& v2)
	{
		return
		{
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		};
	}

	template <typename Type>
	Type Vector3D<Type>::LengthSquared(Vector3D<Type> const& v)
	{
		return Vector3D::Dot(v, v);
	}

	template <typename Type>
	double Vector3D<Type>::Length(Vector3D<Type> const& v)
	{
		return Utility::Math::Sqrt(LengthSquared(v));
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::Normalize(Vector3D<Type> const& v)
	{
		Type lengthSquared = LengthSquared(v);
		if (lengthSquared == static_cast<Type>(0))
		{
			return v;
		}
		Vector3D result = v;
		return result /= static_cast<Type>(Utility::Math::Sqrt(lengthSquared));
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::Rotate(Vector3D<Type> const& point, Vector3D<Type> const& axis, double angle)
	{
		Vector3D v = Normalize(axis) * Dot(point, axis);
		return
			v +
			(point - v) * static_cast<Type>(Utility::Math::Cos(angle)) +
			Cross(point, axis) * static_cast<Type>(Utility::Math::Sin(angle));
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::Projection(Vector3D<Type> const& v, Vector3D<Type> const& target)
	{
		Vector3D normal = Normalize(target);
		return normal * Dot(v, normal);
	}

	template <typename Type>
	double Vector3D<Type>::Angle(Vector3D<Type> const& v1, Vector3D<Type> const& v2)
	{
		return Utility::Math::Acos(Dot(Normalize(v1), Normalize(v2)));
	}

	template <typename Type>
	bool Vector3D<Type>::operator == (Vector3D<Type> const& v) const
	{
		return
			this->x == v.x &&
			this->y == v.y &&
			this->z == v.z;
	}

	template <typename Type>
	bool Vector3D<Type>::operator != (Vector3D<Type> const& v) const
	{
		return !(*this == v);
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator + () const
	{
		return *this;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator - () const
	{
		return *this * -1;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator + (Vector3D<Type> const& v) const
	{
		return { this->x + v.x, this->y + v.y, this->z + v.z };
	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator += (Vector3D<Type> const& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return *this;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator - (Vector3D<Type> const& v) const
	{
		return { this->x - v.x, this->y - v.y, this->z - v.z };
	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator -= (Vector3D<Type> const& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		return *this;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator * (Vector3D<Type> const& v) const
	{
		return { this->x * v.x, this->y * v.y, this->z * v.z };
	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator *= (Vector3D<Type> const& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		return *this;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator * (Type const& x) const
	{
		return { this->x * x, this->y * x, this->z * x };
	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator *= (Type const& x)
	{
		this->x *= x;
		this->y *= x;
		this->z *= x;
		return *this;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator / (Vector3D<Type> const& v) const
	{
		return { this->x / v.x, this->y / v.y, this->z / v.z };
	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator /= (Vector3D<Type> const& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		return *this;
	}

	template <typename Type>
	Vector3D<Type> Vector3D<Type>::operator / (Type const& x) const
	{
		return { this->x / x, this->y / x, this->z / x };
	}

	template <typename Type>
	Vector3D<Type>& Vector3D<Type>::operator /= (Type const& x)
	{
		this->x /= x;
		this->y /= x;
		this->z /= x;
		return *this;
	}

	template Point3::Vector3D(Float3 const& v);
	template Point3::Vector3D(Vector3 const& v);
	template Float3::Vector3D(Point3 const& v);
	template Float3::Vector3D(Vector3 const& v);
	template Vector3::Vector3D(Point3 const& v);
	template Vector3::Vector3D(Float3 const& v);

	template class Vector3D<int>;
	template class Vector3D<float>;
	template class Vector3D<double>;
}

# pragma warning (pop)
