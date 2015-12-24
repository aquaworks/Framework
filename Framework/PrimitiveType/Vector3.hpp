# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

namespace Transform
{
	template <typename Type>
	class Vector4D;

	template <typename Type>
	class Vector3D
	{
	public:

		union
		{
			Type elm[3];

			Type mat[1][3];

			struct
			{
				Type x, y, z;
			};

			struct
			{
				Type r, g, b;
			};
		};

	public:

		static Vector3D const& Zero();
		static Vector3D const& One();
		static Vector3D const& Left();
		static Vector3D const& Right();
		static Vector3D const& Up();
		static Vector3D const& Down();
		static Vector3D const& Forward();
		static Vector3D const& Backward();

	public:

		Vector3D();
		Vector3D(Vector3D const& v);
		Vector3D(Type const& x, Type const& y, Type const& z);
		template <typename Other>
		Vector3D(Vector3D<Other> const& v);
		Vector3D(Vector4D<Type> const& v);
		Vector3D& operator = (Vector3D const& v);

	public:

		static Type Dot(Vector3D const& v1, Vector3D const& v2);
		static Vector3D Cross(Vector3D const& v1, Vector3D const& v2);
		static Type LengthSquared(Vector3D const& v);
		static double Length(Vector3D const& v);
		static Vector3D Normalize(Vector3D const& v);
		static Vector3D Rotate(Vector3D const& point, Vector3D const& axis, double angle);
		static Vector3D Projection(Vector3D const& v, Vector3D const& target);
		static double Angle(Vector3D const& v1, Vector3D const& v2);

	public:

		bool operator == (Vector3D const& v) const;
		bool operator != (Vector3D const& v) const;

	public:

		Vector3D operator + () const;
		Vector3D operator - () const;

	public:

		Vector3D operator + (Vector3D const& v) const;
		Vector3D& operator += (Vector3D const& v);
		Vector3D operator - (Vector3D const& v) const;
		Vector3D& operator -= (Vector3D const& v);
		Vector3D operator * (Vector3D const& v) const;
		Vector3D& operator *= (Vector3D const& v);
		Vector3D operator * (Type const& x) const;
		Vector3D& operator *= (Type const& x);
		Vector3D operator / (Vector3D const& v) const;
		Vector3D& operator /= (Vector3D const& v);
		Vector3D operator / (Type const& x) const;
		Vector3D& operator /= (Type const& x);
	};

	using Point3 = Vector3D<int>;
	using Float3 = Vector3D<float>;
	using Vector3 = Vector3D<double>;
}

# pragma warning (pop)
