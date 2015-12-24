# include "Vector4.hpp"

# include "Vector3.hpp"

# include "Utility/Math.hpp"

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Transform
{
	template <typename Type>
	Vector4D<Type> const& Vector4D<Type>::Zero()
	{
		static Vector4D zero { 0, 0, 0, 0 };
		return zero;
	}

	template <typename Type>
	Vector4D<Type> const& Vector4D<Type>::One()
	{
		static Vector4D one { 1, 1, 1, 1 };
		return one;
	}

	template <typename Type>
	Vector4D<Type>::Vector4D()
		: x(0)
		, y(0)
		, z(0)
		, w(0)
	{

	}
	template <typename Type>
	Vector4D<Type>::Vector4D(Vector4D<Type> const& v)
		: x(v.x)
		, y(v.y)
		, z(v.z)
		, w(v.w)
	{

	}

	template <typename Type>
	template <typename Other>
	Vector4D<Type>::Vector4D(Vector4D<Other> const& v)
		: x(static_cast<Type>(v.x))
		, y(static_cast<Type>(v.y))
		, z(static_cast<Type>(v.z))
		, w(static_cast<Type>(v.w))
	{

	}

	template <typename Type>
	Vector4D<Type>::Vector4D(Type const& x, Type const& y, Type const& z, Type const& w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{

	}

	template <typename Type>
	Vector4D<Type>::Vector4D(Vector3D<Type> const& v, Type const& w)
		: x(v.x)
		, y(v.y)
		, z(v.z)
		, w(w)
	{

	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator = (Vector4D<Type> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z, this->w = v.w;
		this->z = v.w;
		return *this;
	}

	template <typename Type>
	Type Vector4D<Type>::Dot(Vector4D<Type> const& v1, Vector4D<Type> const& v2)
	{
		return v1.x * v2.x + v1.y * v2.y * v1.z * v2.z + v1.w * v2.w;
	}

	template <typename Type>
	Type Vector4D<Type>::LengthSquared(Vector4D<Type> const& v)
	{
		return Vector4D::Dot(v, v);
	}

	template <typename Type>
	double Vector4D<Type>::Length(Vector4D<Type> const& v)
	{
		return Utility::Math::Sqrt(LengthSquared(v));
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::Normalize(Vector4D<Type> const& v)
	{
		Type lengthSquared = LengthSquared(v);
		if (lengthSquared == static_cast<Type>(0))
		{
			return v;
		}
		Vector4D result = v;
		return result /= static_cast<Type>(Utility::Math::Sqrt(lengthSquared));
	}

	template <typename Type>
	bool Vector4D<Type>::operator == (Vector4D<Type> const& v) const
	{
		return
			this->x == v.x &&
			this->y == v.y &&
			this->z == v.z &&
			this->w == v.w;
	}

	template <typename Type>
	bool Vector4D<Type>::operator != (Vector4D<Type> const& v) const
	{
		return !(*this == v);
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator + () const
	{
		return *this;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator - () const
	{
		return *this * -1;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator + (Vector4D<Type> const& v) const
	{
		return { this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w };
	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator += (Vector4D<Type> const& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;
		return *this;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator - (Vector4D<Type> const& v) const
	{
		return { this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w };
	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator -= (Vector4D<Type> const& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;
		return *this;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator * (Vector4D<Type> const& v) const
	{
		return { this->x * v.x, this->y * v.y, this->z * v.z, this->w * v.w };
	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator *= (Vector4D<Type> const& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		this->w *= v.w;
		return *this;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator * (Type const& x) const
	{
		return { this->x * x, this->y * x, this->z * x, this->w * x };
	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator *= (Type const& x)
	{
		this->x *= x;
		this->y *= x;
		this->z *= x;
		this->w *= x;
		return *this;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator / (Vector4D<Type> const& v) const
	{
		return { this->x / v.x, this->y / v.y, this->z / v.z, this->w / v.w };
	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator /= (Vector4D<Type> const& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		this->w /= v.w;
		return *this;
	}

	template <typename Type>
	Vector4D<Type> Vector4D<Type>::operator / (Type const& x) const
	{
		return { this->x / x, this->y / x, this->z / x, this->w / x };
	}

	template <typename Type>
	Vector4D<Type>& Vector4D<Type>::operator /= (Type const& x)
	{
		this->x /= x;
		this->y /= x;
		this->z /= x;
		this->w /= x;
		return *this;
	}

	template Point4::Vector4D(Float4 const& v);
	template Point4::Vector4D(Vector4 const& v);
	template Float4::Vector4D(Point4 const& v);
	template Float4::Vector4D(Vector4 const& v);
	template Vector4::Vector4D(Point4 const& v);
	template Vector4::Vector4D(Float4 const& v);

	template class Vector4D<int>;
	template class Vector4D<float>;
	template class Vector4D<double>;
}

# pragma warning (pop)
