# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

namespace Transform
{
	template <typename Type>
	class Vector2D
	{
	public:

		union
		{
			Type elm[2];

			Type mat[1][2];

			struct
			{
				Type x, y;
			};

			struct
			{
				Type u, v;
			};
		};

	public:

		static Vector2D const& Zero();
		static Vector2D const& One();
		static Vector2D const& Left();
		static Vector2D const& Right();
		static Vector2D const& Up();
		static Vector2D const& Down();

	public:

		Vector2D();
		Vector2D(Vector2D const& v);
		Vector2D(Type const& x, Type const& y);
		template <typename Other>
		Vector2D(Vector2D<Other> const& v);
		Vector2D& operator = (Vector2D const& v);

	public:

		static Type Dot(Vector2D const& v1, Vector2D const& v2);
		static Type Cross(Vector2D const& v1, Vector2D const& v2);
		static Type LengthSquared(Vector2D const& v);
		static double Length(Vector2D const& v);
		static Vector2D Normalize(Vector2D const& v);
		static Vector2D Rotate(Vector2D const& point, Vector2D const& origin, double angle);
		static Vector2D Projection(Vector2D const& v, Vector2D const& target);
		static double Angle(Vector2D const& v1, Vector2D const& v2);

	public:

		bool operator == (Vector2D const& v) const;
		bool operator != (Vector2D const& v) const;

	public:

		Vector2D operator + () const;
		Vector2D operator - () const;

	public:

		Vector2D operator + (Vector2D const& v) const;
		Vector2D& operator += (Vector2D const& v);
		Vector2D operator - (Vector2D const& v) const;
		Vector2D& operator -= (Vector2D const& v);
		Vector2D operator * (Vector2D const& v) const;
		Vector2D& operator *= (Vector2D const& v);
		Vector2D operator * (Type const& x) const;
		Vector2D& operator *= (Type const& x);
		Vector2D operator / (Vector2D const& v) const;
		Vector2D& operator /= (Vector2D const& v);
		Vector2D operator / (Type const& x) const;
		Vector2D& operator /= (Type const& x);
	};

	using Point2 = Vector2D<int>;
	using Float2 = Vector2D<float>;
	using Vector2 = Vector2D<double>;
}

# pragma warning (pop)
