# pragma once

# include <array>

namespace Transform
{
	template <typename Type>
	class Matrix
	{
	public:

		using value_type = Type;

	public:

		static Matrix const Identity();
		static Matrix const Zero();

	public:

		Matrix();
		Matrix(
			Type const& m11, Type const& m12, Type const& m13, Type const& m14,
			Type const& m21, Type const& m22, Type const& m23, Type const& m24,
			Type const& m31, Type const& m32, Type const& m33, Type const& m34,
			Type const& m41, Type const& m42, Type const& m43, Type const& m44);

	public:

		static Matrix Transposed(Matrix const& matrix);
		static Type Determinant(Matrix const& matrix);
		static Matrix Inversed(Matrix const& matrix);

	public:

		Matrix<Type> operator * (Matrix const& m);
		Matrix operator * (Type const& s);

	public:

		union
		{
			Type elm[16];

			Type mat[4][4];

			struct
			{
				Type m11, m12, m13, m14;
				Type m21, m22, m23, m24;
				Type m31, m32, m33, m34;
				Type m41, m42, m43, m44;
			};
		};
	};

	using Float4x4 = Matrix<float>;
	using Matrix4x4 = Matrix<double>;
}
