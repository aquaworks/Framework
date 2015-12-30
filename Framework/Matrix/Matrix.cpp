# include "Matrix.hpp"

namespace Transform
{
	template <typename Type>
	Matrix<Type>::Matrix()
		: Matrix(Identity())
	{

	}

	template <typename Type>
	Matrix<Type>::Matrix(
		Type const& m11, Type const& m12, Type const& m13, Type const& m14,
		Type const& m21, Type const& m22, Type const& m23, Type const& m24,
		Type const& m31, Type const& m32, Type const& m33, Type const& m34,
		Type const& m41, Type const& m42, Type const& m43, Type const& m44)
		: m11(m11), m12(m12), m13(m13), m14(m14)
		, m21(m21), m22(m22), m23(m23), m24(m24)
		, m31(m31), m32(m32), m33(m33), m34(m34)
		, m41(m41), m42(m42), m43(m43), m44(m44)
	{

	}

	template <typename Type>
	Matrix<Type> const Matrix<Type>::Identity()
	{
		static Matrix const identity { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
		return identity;
	}

	template <typename Type>
	Matrix<Type> const Matrix<Type>::Zero()
	{
		static Matrix const zero { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		return zero;
	}

	template <typename Type>
	Matrix<Type> Matrix<Type>::Transposed(Matrix const& matrix)
	{
		return Matrix {
			matrix.m11, matrix.m21, matrix.m31, matrix.m41,
			matrix.m12, matrix.m22, matrix.m32, matrix.m42,
			matrix.m13, matrix.m23, matrix.m33, matrix.m43,
			matrix.m14, matrix.m24, matrix.m34, matrix.m44 };
	}

	template <typename Type>
	Type Matrix<Type>::Determinant(Matrix const& matrix)
	{
		return
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[2][2] * matrix.mat[3][3] +
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[2][3] * matrix.mat[3][1] +
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[2][1] * matrix.mat[3][2] +
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[2][3] * matrix.mat[3][2] +
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[2][0] * matrix.mat[3][3] +
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[2][2] * matrix.mat[3][0] +
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[2][1] * matrix.mat[3][3] +
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[2][3] * matrix.mat[3][0] +
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[2][0] * matrix.mat[3][1] +
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[2][2] * matrix.mat[3][1] +
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[2][0] * matrix.mat[3][2] +
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[2][1] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[2][3] * matrix.mat[3][2] -
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[2][1] * matrix.mat[3][3] -
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[2][2] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[2][2] * matrix.mat[3][3] -
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[2][3] * matrix.mat[3][0] -
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[2][0] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[2][3] * matrix.mat[3][1] -
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[2][0] * matrix.mat[3][3] -
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[2][1] * matrix.mat[3][0] -
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[2][1] * matrix.mat[3][2] -
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[2][2] * matrix.mat[3][0] -
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[2][0] * matrix.mat[3][1];
	}

	template <typename Type>
	Matrix<Type> Matrix<Type>::Inversed(Matrix const& matrix)
	{
		Type det = Determinant(matrix);

		if (det == static_cast<Type>(0))
		{
			return Zero();
		}

		Type m11 = (
			matrix.mat[1][1] * matrix.mat[2][2] * matrix.mat[3][3] +
			matrix.mat[1][2] * matrix.mat[2][3] * matrix.mat[3][1] +
			matrix.mat[1][3] * matrix.mat[2][1] * matrix.mat[3][2] -
			matrix.mat[1][1] * matrix.mat[2][3] * matrix.mat[3][2] -
			matrix.mat[1][2] * matrix.mat[2][1] * matrix.mat[3][3] -
			matrix.mat[1][3] * matrix.mat[2][2] * matrix.mat[3][1]) / det;

		Type m12 = (
			matrix.mat[0][1] * matrix.mat[2][3] * matrix.mat[3][2] +
			matrix.mat[0][2] * matrix.mat[2][1] * matrix.mat[3][3] +
			matrix.mat[0][3] * matrix.mat[2][2] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[2][2] * matrix.mat[3][3] -
			matrix.mat[0][2] * matrix.mat[2][3] * matrix.mat[3][1] -
			matrix.mat[0][3] * matrix.mat[2][1] * matrix.mat[3][2]) / det;

		Type m13 = (
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[3][3] +
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[3][1] +
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[3][2] -
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[3][3] -
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[3][1]) / det;

		Type m14 = (
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[2][2] +
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[2][3] +
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[2][1] -
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[2][3] -
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[2][1] -
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[2][2]) / det;

		Type m21 = (
			matrix.mat[1][0] * matrix.mat[2][3] * matrix.mat[3][2] +
			matrix.mat[1][2] * matrix.mat[2][0] * matrix.mat[3][3] +
			matrix.mat[1][3] * matrix.mat[2][2] * matrix.mat[3][0] -
			matrix.mat[1][0] * matrix.mat[2][2] * matrix.mat[3][3] -
			matrix.mat[1][2] * matrix.mat[2][3] * matrix.mat[3][0] -
			matrix.mat[1][3] * matrix.mat[2][0] * matrix.mat[3][2]) / det;

		Type m22 = (
			matrix.mat[0][0] * matrix.mat[2][2] * matrix.mat[3][3] +
			matrix.mat[0][2] * matrix.mat[2][3] * matrix.mat[3][0] +
			matrix.mat[0][3] * matrix.mat[2][0] * matrix.mat[3][2] -
			matrix.mat[0][0] * matrix.mat[2][3] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[2][0] * matrix.mat[3][3] -
			matrix.mat[0][3] * matrix.mat[2][2] * matrix.mat[3][0]) / det;

		Type m23 = (
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[3][2] +
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[3][3] +
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[3][3] -
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[3][0] -
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[3][2]) / det;

		Type m24 = (
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[2][3] +
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[2][0] +
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[2][2] -
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[2][2] -
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[2][3] -
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[2][0]) / det;

		Type m31 = (
			matrix.mat[1][0] * matrix.mat[2][1] * matrix.mat[3][3] +
			matrix.mat[1][1] * matrix.mat[2][3] * matrix.mat[3][0] +
			matrix.mat[1][3] * matrix.mat[2][0] * matrix.mat[3][1] -
			matrix.mat[1][0] * matrix.mat[2][3] * matrix.mat[3][1] -
			matrix.mat[1][1] * matrix.mat[2][0] * matrix.mat[3][3] -
			matrix.mat[1][3] * matrix.mat[2][1] * matrix.mat[3][0]) / det;

		Type m32 = (
			matrix.mat[0][0] * matrix.mat[2][3] * matrix.mat[3][1] +
			matrix.mat[0][1] * matrix.mat[2][0] * matrix.mat[3][3] +
			matrix.mat[0][3] * matrix.mat[2][1] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[2][1] * matrix.mat[3][3] -
			matrix.mat[0][1] * matrix.mat[2][3] * matrix.mat[3][0] -
			matrix.mat[0][3] * matrix.mat[2][0] * matrix.mat[3][1]) / det;

		Type m33 = (
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[3][3] +
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[3][0] +
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[3][1] -
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[3][3] -
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[3][0]) / det;

		Type m34 = (
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[2][1] +
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[2][3] +
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[2][0] -
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[2][3] -
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[2][0] -
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[2][1]) / det;

		Type m41 = (
			matrix.mat[1][0] * matrix.mat[2][2] * matrix.mat[3][1] +
			matrix.mat[1][1] * matrix.mat[2][0] * matrix.mat[3][2] +
			matrix.mat[1][2] * matrix.mat[2][1] * matrix.mat[3][0] -
			matrix.mat[1][0] * matrix.mat[2][1] * matrix.mat[3][2] -
			matrix.mat[1][1] * matrix.mat[2][2] * matrix.mat[3][0] -
			matrix.mat[1][2] * matrix.mat[2][0] * matrix.mat[3][1]) / det;

		Type m42 = (
			matrix.mat[0][0] * matrix.mat[2][1] * matrix.mat[3][2] +
			matrix.mat[0][1] * matrix.mat[2][2] * matrix.mat[3][0] +
			matrix.mat[0][2] * matrix.mat[2][0] * matrix.mat[3][1] -
			matrix.mat[0][0] * matrix.mat[2][2] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[2][0] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[2][1] * matrix.mat[3][0]) / det;

		Type m43 = (
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[3][1] +
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[3][2] +
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[3][2] -
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[3][0] -
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[3][1]) / det;

		Type m44 = (
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[2][2] +
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[2][0] +
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[2][1] -
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[2][1] -
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[2][2] -
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[2][0]) / det;

		return Matrix(
			m11, m12, m13, m14,
			m21, m22, m23, m24,
			m31, m32, m33, m34,
			m41, m42, m43, m44);
	}

	template <typename Type>
	Matrix<Type> Matrix<Type>::operator * (Matrix const& m)
	{
		Matrix r { Matrix::Zero() };
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					r.mat[i][j] += this->mat[i][k] * m.mat[k][j];
				}
			}
		}
		return r;
	}
	template <typename Type>
	Matrix<Type> Matrix<Type>::operator * (Type const& s)
	{
		Matrix m { *this };
		for (int i = 0; i < 16; ++i)
		{
			m.elm[i] *= s;
		}
		return m;
	}

	template class Matrix<float>;
	template class Matrix<double>;
}
