# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

namespace Transform
{
	template <typename Type>
	class Vector3D;

	template <typename Type>
	class Vector4D
	{
	public:

		union
		{
			Type elm[4];

			Type mat[1][4];

			struct
			{
				Type x, y, z, w;
			};

			struct
			{
				Type r, g, b, a;
			};
		};

	public:

		static Vector4D const& Zero();
		static Vector4D const& One();

	public:

		Vector4D();
		Vector4D(Vector4D const& v);
		Vector4D(Type const& x, Type const& y, Type const& z, Type const& w);
		template <typename Other>
		Vector4D(Vector4D<Other> const& v);
		Vector4D(Vector3D<Type> const& v, Type const& w);
		Vector4D& operator = (Vector4D const& v);

	public:

		static Type Dot(Vector4D const& v1, Vector4D const& v2);
		static Type LengthSquared(Vector4D const& v);
		static double Length(Vector4D const& v);
		static Vector4D Normalize(Vector4D const& v);

	public:

		bool operator == (Vector4D const& v) const;
		bool operator != (Vector4D const& v) const;

	public:

		Vector4D operator + () const;
		Vector4D operator - () const;

	public:

		Vector4D operator + (Vector4D const& v) const;
		Vector4D& operator += (Vector4D const& v);
		Vector4D operator - (Vector4D const& v) const;
		Vector4D& operator -= (Vector4D const& v);
		Vector4D operator * (Vector4D const& v) const;
		Vector4D& operator *= (Vector4D const& v);
		Vector4D operator * (Type const& x) const;
		Vector4D& operator *= (Type const& x);
		Vector4D operator / (Vector4D const& v) const;
		Vector4D& operator /= (Vector4D const& v);
		Vector4D operator / (Type const& x) const;
		Vector4D& operator /= (Type const& x);
	};

	using Point4 = Vector4D<int>;
	using Float4 = Vector4D<float>;
	using Vector4 = Vector4D<double>;
}

# pragma warning (pop)
