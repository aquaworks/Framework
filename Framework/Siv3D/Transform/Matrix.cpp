# include "Matrix.hpp"
# include "Vector3.hpp"
# include "Vector4.hpp"
# include "Point3.hpp"

# include "Utility/String.hpp"
# include "Utility/Math.hpp"
# include "Utility/MemoryCast.hpp"

# include <tuple>

namespace
{
	void Multiply(float* mat, int row, int column, int match, float const* m1, float const* m2)
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				for (int k = 0; k < match; ++k)
				{
					double elm0 = mat[i * column + j];
					double elm1 = m1[i * column + k];
					double elm2 = m2[k * column + j];
					double mul = elm0 + elm1 * elm2;
					mat[i * column + j] = (float)mul;
				}
			}
		}
	}
}

namespace Transform
{
	using namespace Utility;

	Matrix const& Matrix::zero()
	{
		static Matrix zero { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		return zero;
	}

	Matrix const& Matrix::identity()
	{
		static Matrix identity { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
		return identity;
	}

	Matrix::Matrix()
		: Matrix(identity())
	{

	}

	Matrix::Matrix(float const* m)
		: Matrix(
			m[0], m[1], m[2], m[3],
			m[4], m[5], m[6], m[7],
			m[8], m[9], m[10], m[11],
			m[12], m[13], m[14], m[15])
	{

	}

	Matrix::Matrix(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44)
		: m11(m11)
		, m12(m12)
		, m13(m13)
		, m14(m14)
		, m21(m21)
		, m22(m22)
		, m23(m23)
		, m24(m24)
		, m31(m31)
		, m32(m32)
		, m33(m33)
		, m34(m34)
		, m41(m41)
		, m42(m42)
		, m43(m43)
		, m44(m44)
	{

	}

	Matrix& Matrix::operator = (Matrix const& m)
	{
		this->m11 = m.m11;
		this->m12 = m.m12;
		this->m13 = m.m13;
		this->m14 = m.m14;

		this->m21 = m.m21;
		this->m22 = m.m22;
		this->m23 = m.m23;
		this->m24 = m.m24;

		this->m31 = m.m31;
		this->m32 = m.m32;
		this->m33 = m.m33;
		this->m34 = m.m34;

		this->m41 = m.m41;
		this->m42 = m.m42;
		this->m43 = m.m43;
		this->m44 = m.m44;

		return *this;
	}

	Matrix::operator float* ()
	{
		return elm;
	}

	Matrix::operator float const* () const
	{
		return elm;
	}

	bool Matrix::isIdentity() const
	{
		return IsIdentity(*this);
	}

	bool Matrix::isZero() const
	{
		return IsZero(*this);
	}

	bool Matrix::canInverse() const
	{
		return CanInverse(*this);
	}

	bool Matrix::isInverse(Matrix const& matrix) const
	{
		return IsInverse(*this, matrix);
	}

	float Matrix::determinant() const
	{
		return Determinant(*this);
	}

	std::wstring Matrix::toString() const
	{
		return ToString(*this);
	}

	Matrix& Matrix::Translate(Vector3 const& translation)
	{
		return Translate(*this, translation);
	}

	Matrix& Matrix::rotate(Vector3 const& axis, double angle)
	{
		return Rotate(*this, axis, angle);
	}

	Matrix& Matrix::scale(Vector3 const& scaling)
	{
		return Scale(*this, scaling);
	}

	Matrix& Matrix::transform(Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling)
	{
		return Transform(*this, translation, axis, angle, scaling);
	}

	Matrix& Matrix::transpose()
	{
		return Transpose(*this);
	}

	Matrix& Matrix::inverse()
	{
		return Inverse(*this);
	}

	Matrix Matrix::translated(Vector3 const& translation) const
	{
		return Translated(*this, translation);
	}

	Matrix Matrix::rotated(Vector3 const& axis, double angle) const
	{
		return Rotated(*this, axis, angle);
	}

	Matrix Matrix::scaled(Vector3 const& scaling) const
	{
		return Scaled(*this, scaling);
	}

	Matrix Matrix::transformed(Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling) const
	{
		return Transformed(*this, translation, axis, angle, scaling);
	}

	Matrix Matrix::transposed() const
	{
		return Transposed(*this);
	}

	Matrix Matrix::inversed() const
	{
		return Inversed(*this);
	}

	Quaternion Matrix::ToQuaternion() const
	{
		double x = m11 - m22 - m33 + 1.0;
		double y = m22 - m33 - m11 + 1.0;
		double z = m33 - m11 - m22 + 1.0;
		double w = m11 + m22 + m33 + 1.0;

		int index;
		double max;
		std::tie(index, max) = Math::MaxData({ x, y, z, w });

		if (max < 0.0)
		{
			return Quaternion::Identity();
		}
		
		float v = (float)Math::Sqrt(max) / 2.0f;
		float m = v * 4.0f;

		float const table[4][4] =
		{
			v, (m12 + m21) * m, (m31 + m13) * m, (m23 - m32) * m,
			(m12 + m21) * m, v, (m23 + m32) * m, (m31 - m13) * m,
			(m31 + m13) * m, (m23 + m32) * m, v, (m12 - m21) * m,
			(m23 - m32) * m, (m31 - m13) * m, (m12 - m21) * m, v,
		};

		return Quaternion(
			table[index][0],
			table[index][1],
			table[index][2],
			table[index][3]);
		
	}

	Vector4 Matrix::up() const
	{
		return Up(*this);
	}

	Vector4 Matrix::right() const
	{
		return Right(*this);
	}

	Vector4 Matrix::forward() const
	{
		return Forward(*this);
	}

	bool Matrix::IsIdentity(Matrix const& m)
	{
		return m == identity();
	}

	bool Matrix::IsZero(Matrix const& m)
	{
		return m == zero();
	}

	bool Matrix::CanInverse(Matrix const& m)
	{
		return Determinant(m) != 0.0;
	}

	bool Matrix::IsInverse(Matrix const& m1, Matrix const& m2)
	{
		return IsIdentity(m1 * m2);
	}

	float Matrix::Determinant(Matrix const& matrix)
	{
		double det =
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
		return (float)det;
	}

	std::wstring Matrix::ToString(Matrix const& m)
	{
		return String::Create(
			"f[0] : ", MemoryCast<Vector4>(m.mat[0])->toString(), "\n",
			"f[1] : ", MemoryCast<Vector4>(m.mat[1])->toString(), "\n",
			"f[2] : ", MemoryCast<Vector4>(m.mat[2])->toString(), "\n",
			"f[3] : ", MemoryCast<Vector4>(m.mat[3])->toString());
	}

	Matrix Matrix::Translation(Vector3 const& translation)
	{
		return Translated(identity(), translation);
	}

	Matrix Matrix::Rotation(Vector3 const& axis, double angle)
	{
		return Rotated(identity(), axis, angle);
	}

	Matrix Matrix::Scaling(Vector3 const& scaling)
	{
		return Scaled(identity(), scaling);
	}

	Matrix Matrix::Transformation(Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling)
	{
		return Transformed(identity(), translation, axis, angle, scaling);
	}

	Matrix& Matrix::Translate(Matrix& matrix, Vector3 const& translation)
	{
		matrix.m41 += translation.x;
		matrix.m42 += translation.y;
		matrix.m43 += translation.z;
		return matrix;
	}

	Matrix& Matrix::Rotate(Matrix& matrix, Vector3 const& axis, double angle)
	{
		Vector4 X = Vector4(Vector3(matrix.m11, matrix.m12, matrix.m13).rotate(axis, angle), 0.0f);
		Vector4 Y = Vector4(Vector3(matrix.m21, matrix.m22, matrix.m23).rotate(axis, angle), 0.0f);
		Vector4 Z = Vector4(Vector3(matrix.m31, matrix.m32, matrix.m33).rotate(axis, angle), 0.0f);
		matrix.m11 = X.x; matrix.m12 = X.y; matrix.m13 = X.z;
		matrix.m21 = Y.x; matrix.m22 = Y.y; matrix.m23 = Y.z;
		matrix.m31 = Z.x; matrix.m32 = Z.y; matrix.m33 = Z.z;
		return matrix;
	}
	Matrix& Matrix::Scale(Matrix& matrix, Vector3 const& scaling)
	{
		matrix.m11 *= scaling.x; matrix.m12 *= scaling.x; matrix.m13 *= scaling.x;
		matrix.m21 *= scaling.y; matrix.m22 *= scaling.y; matrix.m23 *= scaling.y;
		matrix.m31 *= scaling.z; matrix.m32 *= scaling.z; matrix.m33 *= scaling.z;
		return matrix;
	}

	Matrix& Matrix::Transform(Matrix& matrix, Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling)
	{
		return Translate(Rotate(Scale(matrix, scaling), axis, angle), translation);
	}

	Matrix& Matrix::Transpose(Matrix& matrix)
	{
		return matrix = Transposed(matrix);
	}

	Matrix& Matrix::Inverse(Matrix& matrix)
	{
		return matrix = Inversed(matrix);
	}

	Matrix Matrix::Translated(Matrix const& matrix, Vector3 const& translation)
	{
		Matrix m = matrix;
		return Translate(m, translation);
	}

	Matrix Matrix::Rotated(Matrix const& matrix, Vector3 const& axis, double angle)
	{
		Matrix m = matrix;
		return Rotate(m, axis, angle);
	}

	Matrix Matrix::Scaled(Matrix const& matrix, Vector3 const& scaling)
	{
		Matrix m = matrix;
		return Scale(m, scaling);
	}

	Matrix Matrix::Transformed(Matrix const& matrix, Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling)
	{
		Matrix m = matrix;
		return Transform(m, translation, axis, angle, scaling);
	}

	Matrix Matrix::Transposed(Matrix const& matrix)
	{
		return Matrix {
			matrix.m11, matrix.m21, matrix.m31, matrix.m41,
			matrix.m12, matrix.m22, matrix.m32, matrix.m42,
			matrix.m13, matrix.m23, matrix.m33, matrix.m43,
			matrix.m14, matrix.m24, matrix.m34, matrix.m44 };
	}

	Matrix Matrix::Inversed(Matrix const& matrix)
	{
		float det = Determinant(matrix);

		if (det == 0.0f)
		{
			return zero();
		}

		double m11 = (
			matrix.mat[1][1] * matrix.mat[2][2] * matrix.mat[3][3] +
			matrix.mat[1][2] * matrix.mat[2][3] * matrix.mat[3][1] +
			matrix.mat[1][3] * matrix.mat[2][1] * matrix.mat[3][2] -
			matrix.mat[1][1] * matrix.mat[2][3] * matrix.mat[3][2] -
			matrix.mat[1][2] * matrix.mat[2][1] * matrix.mat[3][3] -
			matrix.mat[1][3] * matrix.mat[2][2] * matrix.mat[3][1]) / det;

		double m12 = (
			matrix.mat[0][1] * matrix.mat[2][3] * matrix.mat[3][2] +
			matrix.mat[0][2] * matrix.mat[2][1] * matrix.mat[3][3] +
			matrix.mat[0][3] * matrix.mat[2][2] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[2][2] * matrix.mat[3][3] -
			matrix.mat[0][2] * matrix.mat[2][3] * matrix.mat[3][1] -
			matrix.mat[0][3] * matrix.mat[2][1] * matrix.mat[3][2]) / det;

		double m13 = (
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[3][3] +
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[3][1] +
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[3][2] -
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[3][3] -
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[3][1]) / det;

		double m14 = (
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[2][2] +
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[2][3] +
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[2][1] -
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[2][3] -
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[2][1] -
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[2][2]) / det;

		double m21 = (
			matrix.mat[1][0] * matrix.mat[2][3] * matrix.mat[3][2] +
			matrix.mat[1][2] * matrix.mat[2][0] * matrix.mat[3][3] +
			matrix.mat[1][3] * matrix.mat[2][2] * matrix.mat[3][0] -
			matrix.mat[1][0] * matrix.mat[2][2] * matrix.mat[3][3] -
			matrix.mat[1][2] * matrix.mat[2][3] * matrix.mat[3][0] -
			matrix.mat[1][3] * matrix.mat[2][0] * matrix.mat[3][2]) / det;

		double m22 = (
			matrix.mat[0][0] * matrix.mat[2][2] * matrix.mat[3][3] +
			matrix.mat[0][2] * matrix.mat[2][3] * matrix.mat[3][0] +
			matrix.mat[0][3] * matrix.mat[2][0] * matrix.mat[3][2] -
			matrix.mat[0][0] * matrix.mat[2][3] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[2][0] * matrix.mat[3][3] -
			matrix.mat[0][3] * matrix.mat[2][2] * matrix.mat[3][0]) / det;

		double m23 = (
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[3][2] +
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[3][3] +
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[3][3] -
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[3][0] -
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[3][2]) / det;

		double m24 = (
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[2][3] +
			matrix.mat[0][2] * matrix.mat[1][3] * matrix.mat[2][0] +
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[2][2] -
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[2][2] -
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[2][3] -
			matrix.mat[0][3] * matrix.mat[1][2] * matrix.mat[2][0]) / det;

		double m31 = (
			matrix.mat[1][0] * matrix.mat[2][1] * matrix.mat[3][3] +
			matrix.mat[1][1] * matrix.mat[2][3] * matrix.mat[3][0] +
			matrix.mat[1][3] * matrix.mat[2][0] * matrix.mat[3][1] -
			matrix.mat[1][0] * matrix.mat[2][3] * matrix.mat[3][1] -
			matrix.mat[1][1] * matrix.mat[2][0] * matrix.mat[3][3] -
			matrix.mat[1][3] * matrix.mat[2][1] * matrix.mat[3][0]) / det;

		double m32 = (
			matrix.mat[0][0] * matrix.mat[2][3] * matrix.mat[3][1] +
			matrix.mat[0][1] * matrix.mat[2][0] * matrix.mat[3][3] +
			matrix.mat[0][3] * matrix.mat[2][1] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[2][1] * matrix.mat[3][3] -
			matrix.mat[0][1] * matrix.mat[2][3] * matrix.mat[3][0] -
			matrix.mat[0][3] * matrix.mat[2][0] * matrix.mat[3][1]) / det;

		double m33 = (
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[3][3] +
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[3][0] +
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[3][1] -
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[3][3] -
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[3][0]) / det;

		double m34 = (
			matrix.mat[0][0] * matrix.mat[1][3] * matrix.mat[2][1] +
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[2][3] +
			matrix.mat[0][3] * matrix.mat[1][1] * matrix.mat[2][0] -
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[2][3] -
			matrix.mat[0][1] * matrix.mat[1][3] * matrix.mat[2][0] -
			matrix.mat[0][3] * matrix.mat[1][0] * matrix.mat[2][1]) / det;

		double m41 = (
			matrix.mat[1][0] * matrix.mat[2][2] * matrix.mat[3][1] +
			matrix.mat[1][1] * matrix.mat[2][0] * matrix.mat[3][2] +
			matrix.mat[1][2] * matrix.mat[2][1] * matrix.mat[3][0] -
			matrix.mat[1][0] * matrix.mat[2][1] * matrix.mat[3][2] -
			matrix.mat[1][1] * matrix.mat[2][2] * matrix.mat[3][0] -
			matrix.mat[1][2] * matrix.mat[2][0] * matrix.mat[3][1]) / det;

		double m42 = (
			matrix.mat[0][0] * matrix.mat[2][1] * matrix.mat[3][2] +
			matrix.mat[0][1] * matrix.mat[2][2] * matrix.mat[3][0] +
			matrix.mat[0][2] * matrix.mat[2][0] * matrix.mat[3][1] -
			matrix.mat[0][0] * matrix.mat[2][2] * matrix.mat[3][1] -
			matrix.mat[0][1] * matrix.mat[2][0] * matrix.mat[3][2] -
			matrix.mat[0][2] * matrix.mat[2][1] * matrix.mat[3][0]) / det;

		double m43 = (
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[3][1] +
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[3][2] +
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[3][0] -
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[3][2] -
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[3][0] -
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[3][1]) / det;

		double m44 = (
			matrix.mat[0][0] * matrix.mat[1][1] * matrix.mat[2][2] +
			matrix.mat[0][1] * matrix.mat[1][2] * matrix.mat[2][0] +
			matrix.mat[0][2] * matrix.mat[1][0] * matrix.mat[2][1] -
			matrix.mat[0][0] * matrix.mat[1][2] * matrix.mat[2][1] -
			matrix.mat[0][1] * matrix.mat[1][0] * matrix.mat[2][2] -
			matrix.mat[0][2] * matrix.mat[1][1] * matrix.mat[2][0]) / det;

		return Matrix(
			(float)m11, (float)m12, (float)m13, (float)m14,
			(float)m21, (float)m22, (float)m23, (float)m24,
			(float)m31, (float)m32, (float)m33, (float)m34,
			(float)m41, (float)m42, (float)m43, (float)m44);
	}

	Vector4 Matrix::Up(Matrix const& matrix)
	{
		return Vector4(matrix.m21, matrix.m22, matrix.m23, 0.0f);
	}

	Vector4 Matrix::Right(Matrix  const& matrix)
	{
		return Vector4(matrix.m11, matrix.m12, matrix.m13, 0.0f);
	}

	Vector4 Matrix::Forward(Matrix  const& matrix)
	{
		return Vector4(matrix.m31, matrix.m32, matrix.m33, 0.0f);
	}

	Vector3 Matrix::Translation(Matrix const& matrix)
	{
		return Vector3(matrix.m41, matrix.m42, matrix.m43);
	}

	Matrix Matrix::Rotation(Matrix const& matrix)
	{
		Vector3 scale = Scaling(matrix);
		return Matrix(
			matrix.m11 / scale.x, matrix.m12 / scale.x, matrix.m13 / scale.x, 0.0f,
			matrix.m21 / scale.y, matrix.m22 / scale.y, matrix.m23 / scale.y, 0.0f,
			matrix.m31 / scale.z, matrix.m32 / scale.z, matrix.m33 / scale.z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
	}

	Vector3 Matrix::Scaling(Matrix const& matrix)
	{
		return Vector3(
			MemoryCast<Vector4>(matrix.mat[0])->length(),
			MemoryCast<Vector4>(matrix.mat[1])->length(),
			MemoryCast<Vector4>(matrix.mat[2])->length());
	}

	Matrix Matrix::LookAt(Vector3 const& position, Vector3 const& target, Vector3 const& up)
	{
		Matrix matrix;
		Vector3 Z = Vector3::Normalize(target - position);
		Vector3 X = Vector3::Normalize(Vector3::Cross(up, Z));
		Vector3 Y = Vector3::Cross(Z, X);
		matrix.m11 = X.x; matrix.m21 = X.y; matrix.m31 = X.z;
		matrix.m12 = Y.x; matrix.m22 = Y.y; matrix.m32 = Y.z;
		matrix.m13 = Z.x; matrix.m23 = Z.y; matrix.m33 = Z.z;
		Vector3 pos = -position;
		matrix.m41 = Vector3::Dot(pos, X);
		matrix.m42 = Vector3::Dot(pos, Y);
		matrix.m43 = Vector3::Dot(pos, Z);
		return matrix;
	}

	Matrix Matrix::Perspective(double fov, float aspect, float nearclip, float farclip)
	{
		float y = (float)(1 / Math::Tan(fov / 2.0));
		float x = y / aspect;
		float z = farclip / (farclip - nearclip);
		float w = -z * nearclip;
		return Matrix(
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 1,
			0, 0, w, 0);
	}

	Matrix Matrix::Viewport(int width, int height)
	{
		float w = width / 2.0f;
		float h = height / 2.0f;
		return Matrix(
			w, 0, 0, 0,
			0, -h, 0, 0,
			0, 0, 1, 0,
			w, h, 0, 1);
	}

	Matrix Matrix::Lerp(Matrix const& m1, Matrix const& m2, float t)
	{
		Matrix r1 = Matrix::Rotation(m1);
		Matrix r2 = Matrix::Rotation(m2);
		Vector3 translate = Vector3::Lerp(Matrix::Translation(m1), Matrix::Translation(m2), t);
		Vector3 xAxis = Vector3::Slerp(Vector3(Matrix::Right(r1)), Vector3(Matrix::Right(r2)), t);
		Vector3 yAxis = Vector3::Slerp(Vector3(Matrix::Up(r1)), Vector3(Matrix::Up(r2)), t);
		Vector3 zAxis = Vector3::Slerp(Vector3(Matrix::Forward(r1)), Vector3(Matrix::Forward(r2)), t);
		Vector3 scale = Vector3::Lerp(Matrix::Scaling(m1), Matrix::Scaling(m2), t);
		return Matrix(
			xAxis.x * scale.x, xAxis.y * scale.x, xAxis.z * scale.x, 0.0f,
			xAxis.x * scale.y, xAxis.y * scale.y, xAxis.z * scale.y, 0.0f,
			xAxis.x * scale.z, xAxis.y * scale.z, xAxis.z * scale.z, 0.0f,
			translate.x, translate.y, translate.z, 1.0f);
	}

	bool operator == (Matrix const& m1, Matrix const& m2)
	{
		for (int i = 0; i < 16; ++i)
		{
			if (m1.elm[i] != m2.elm[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator != (Matrix const& m1, Matrix const& m2)
	{
		return !(m1 == m2);
	}

	Matrix operator * (Matrix const& m1, Matrix const& m2)
	{
		Matrix m = Matrix::zero();

		Multiply(m, 4, 4, 4, m1, m2);

		return m;
	}

	Vector3 operator * (Vector3 const& v, Matrix const& m)
	{
		return Vector3(Vector4(v, 1.0f) * m);
	}

	Vector4 operator * (Vector4 const& v, Matrix const& m)
	{
		Vector4 r;

		Multiply(r, 1, 4, 4, v, m);

		return r;
	}

	Matrix& operator *= (Matrix& m1, Matrix const& m2)
	{
		return m1 = m1 * m2;
	}

	Vector3& operator *= (Vector3& v, Matrix const& m)
	{
		return v = v * m;
	}

	Vector4& operator *= (Vector4& v, Matrix const& m)
	{
		return v = v * m;
	}
}
