# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include "Vector4.hpp"

namespace Transform
{
	// -------------------------------------------------------------------
	// �O�u�錾
	// -------------------------------------------------------------------
	class Vector3;
	class Quaternion;
	class Pose;

	/// <summary>�s��</summary>
	class Matrix
	{
	public:

		/// <summary>��s���Ԃ�</summary>
		static Matrix const& Zero();

		/// <summary>�P�ʍs���Ԃ�</summary>
		static Matrix const& Identity();

	public:

		/// <summary>�R���X�g���N�^</summary>
		Matrix();

		/// <summary>�z�񂩂�\�z����</summary>
		explicit Matrix(float const* m);

		/// <summary>�v�f���w�肵�č\�z����</summary>
		Matrix(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

		/// <summary>������Z�q</summary>
		Matrix& operator = (Matrix const& m);

	public:

		/// <summary>�z��ɕϊ�����</summary>
		operator float* ();

		/// <summary>�z��ɕϊ�����</summary>
		operator float const* () const;

	public:

		/// <summary>�P�ʍs�񂩂ǂ�����Ԃ�</summary>
		static bool IsIdentity(Matrix const& m);

		/// <summary>��s�񂩂ǂ�����Ԃ�</summary>
		static bool IsZero(Matrix const& m);

		/// <summary>�t�s�񂪍��邩��Ԃ�</summary>
		static bool CanInverse(Matrix const& m);

		/// <summary>�t�s�񂩂ǂ�����Ԃ�</summary>
		static bool IsInverse(Matrix const& m1, Matrix const& m2);

		/// <summary>�s�񎮂�Ԃ�</summary>
		static float Determinant(Matrix const& m);

	public:

		/// <summary>���s�ړ��s���Ԃ�</summary>
		/// <param name="translation">���s�ړ���</param>
		static Matrix Translation(Vector3 const& translation);

		/// <summary>��]�s���Ԃ�</summary>
		/// <param name="axis">��]��</param>
		/// <param name="angle">��]��</param>
		static Matrix Rotation(Vector3 const& axis, float angle);

		/// <summary>��]�s���Ԃ�</summary>
		/// <param name="rotation">��]</param>
		static Matrix Rotation(Quaternion const& rotation);

		/// <summary>�g��k���s���Ԃ�</summary>
		/// <param name="scaling">�g��k����</param>
		static Matrix Scaling(Vector3 const& scaling);

		/// <summary>�A�t�B���ϊ��s���Ԃ�</summary>
		/// <param name="translation">���s�ړ���</param>
		/// <param name="axis">��]��</param>
		/// <param name="angle">��]��</param>
		/// <param name="scaling">�g��k����</param>
		static Matrix Transformation(Vector3 const& translation, Vector3 const& axis, float angle, Vector3 const& scaling);

		/// <summary>�A�t�B���ϊ��s���Ԃ�</summary>
		/// <param name="translation">���s�ړ���</param>
		/// <param name="rotation">��]</param>
		/// <param name="scaling">�g��k����</param>
		static Matrix Transformation(Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

	public:

		/// <summary>���s�ړ�����</summary>
		/// <param name="translation">���s�ړ���</param>
		static Matrix& Translate(Matrix& matrix, Vector3 const& translation);

		/// <summary>��]����</summary>
		/// <param name="axis">��]��</param>
		/// <param name="angle">��]��</param>
		static Matrix& Rotate(Matrix& matrix, Vector3 const& axis, float angle);

		/// <summary>��]����</summary>
		/// <param name="rotation">��]</param>
		static Matrix& Rotate(Matrix& matrix, Quaternion const& rotation);

		/// <summary>�g��k������</summary>
		/// <param name="scaling">�g��k����</param>
		static Matrix& Scale(Matrix& matrix, Vector3 const& scaling);

		/// <summary>�A�t�B���ϊ�����</summary>
		/// <param name="translation">���s�ړ���</param>
		/// <param name="axis">��]��</param>
		/// <param name="angle">��]��</param>
		/// <param name="scaling">�g��k����</param>
		static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Vector3 const& axis, float angle, Vector3 const& scaling);

		/// <summary>�A�t�B���ϊ�����</summary>
		/// <param name="translation">���s�ړ���</param>
		/// <param name="rotation">��]</param>
		/// <param name="scaling">�g��k����</param>
		static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

		/// <summary>�]�u�s��ɂ���</summary>
		static Matrix& Transpose(Matrix& matrix);

		/// <summary>�t�s��ɂ���</summary>
		static Matrix& Inverse(Matrix& matrix);

		/// <summary>�N�H�[�^�j�I���ɕϊ�����</summary>
		static Quaternion ToQuaternion(Matrix const& matrix);

	public:

		/// <summary>���s�ړ������s���Ԃ�</summary>
		/// <param name="translation">���s�ړ���</param>
		static Matrix Translated(Matrix const& matrix, Vector3 const& translation);

		/// <summary>��]�����s���Ԃ�</summary>
		/// <param name="axis">��]��</param>
		/// <param name="angle">��]��</param>
		static Matrix Rotated(Matrix const& matrix, Vector3 const& axis, float angle);

		/// <summary>��]�����s���Ԃ�</summary>
		/// <param name="rotation">��]</param>
		static Matrix Rotated(Matrix const& matrix, Quaternion const& rotation);

		/// <summary>�g��k�������s���Ԃ�</summary>
		/// <param name="scaling">�g��k����</param>
		static Matrix Scaled(Matrix const& matrix, Vector3 const& scaling);

		/// <summary>�A�t�B���ϊ������s���Ԃ�</summary>
		/// <param name="translation">���s�ړ���</param>
		/// <param name="axis">��]��</param>
		/// <param name="angle">��]��</param>
		/// <param name="scaling">�g��k����</param>
		static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Vector3 const& axis, float angle, Vector3 const& scaling);

		/// <summary>�A�t�B���ϊ������s���Ԃ�</summary>
		/// <param name="translation">���s�ړ���</param>
		/// <param name="rotation">��]</param>
		/// <param name="scaling">�g��k����</param>
		static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

		/// <summary>�]�u�s���Ԃ�</summary>
		static Matrix Transposed(Matrix const& matrix);

		/// <summary>�t�s���Ԃ�</summary>
		static Matrix Inversed(Matrix const& matrix);

	public:

		static Vector4 Up(Matrix const& matrix);

		static Vector4 Right(Matrix const& matrix);

		static Vector4 Forward(Matrix const& matrix);

		static Vector3 Translation(Matrix const& matrix);

		static Quaternion Rotation(Matrix const& matrix);

		static Vector3 Scaling(Matrix const& matrix);

		static Pose Decompose(Matrix const& matrix);

	public:

		static Matrix LookAt(Vector3 const& position, Vector3 const& target, Vector3 const& up);

		static Matrix Perspective(float fov, float aspect, float nearclip, float farclip);

		static Matrix Viewport(int width, int height);

	public:

		union
		{
			float elm[16];

			float mat[4][4];

			struct
			{
				float m11, m12, m13, m14;
				float m21, m22, m23, m24;
				float m31, m32, m33, m34;
				float m41, m42, m43, m44;
			};
		};
	};

	bool operator == (Matrix const& m1, Matrix const& m2);

	bool operator != (Matrix const& m1, Matrix const& m2);

	Matrix operator * (Matrix const& m1, Matrix const& m2);

	Vector3 operator * (Vector3 const& v, Matrix const& m);

	Vector4 operator * (Vector4 const& v, Matrix const& m);

	Matrix& operator *= (Matrix& m1, Matrix const& m2);

	Vector3& operator *= (Vector3& v, Matrix const& m);

	Vector4& operator *= (Vector4& v, Matrix const& m);
}

# pragma warning (pop)
