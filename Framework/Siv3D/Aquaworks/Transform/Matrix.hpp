# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include "Vector4.hpp"

namespace Aquaworks
{
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
			// ---------------------------------------------------------------
			// �萔
			// ---------------------------------------------------------------

		public:

			/// <summary>��s���Ԃ�</summary>
			static Matrix const& Zero();

			/// <summary>�P�ʍs���Ԃ�</summary>
			static Matrix const& Identity();

			// ---------------------------------------------------------------
			// �V�X�e��
			// ---------------------------------------------------------------

		public:

			/// <summary>�R���X�g���N�^</summary>
			Matrix();

			/// <summary>�z�񂩂�\�z����</summary>
			explicit Matrix(f32 const* m);

			/// <summary>�v�f���w�肵�č\�z����</summary>
			Matrix(
				f32 m11, f32 m12, f32 m13, f32 m14,
				f32 m21, f32 m22, f32 m23, f32 m24,
				f32 m31, f32 m32, f32 m33, f32 m34,
				f32 m41, f32 m42, f32 m43, f32 m44);

			/// <summary>������Z�q</summary>
			Matrix& operator = (Matrix const& m);

			// ---------------------------------------------------------------
			// ��Ԃ�Ԃ�
			// ---------------------------------------------------------------

		public:

			/// <summary>�P�ʍs�񂩂ǂ�����Ԃ�</summary>
			static bool IsIdentity(Matrix const& m);

			/// <summary>��s�񂩂ǂ�����Ԃ�</summary>
			static bool IsZero(Matrix const& m);

			/// <summary>�t�s�񂪍��邩��Ԃ�</summary>
			static bool CanInverse(Matrix const& m);

			/// <summary>�t�s�񂩂ǂ�����Ԃ�</summary>
			static bool IsInverse(Matrix const& m1, Matrix const& m2);

			// ---------------------------------------------------------------
			// �ϊ��s���Ԃ�
			// ---------------------------------------------------------------

		public:

			/// <summary>���s�ړ��s���Ԃ�</summary>
			/// <param name="translation">���s�ړ���</param>
			static Matrix Translation(Vector3 const& translation);

			/// <summary>��]�s���Ԃ�</summary>
			/// <param name="axis">��]��</param>
			/// <param name="angle">��]��</param>
			static Matrix Rotation(Vector3 const& axis, f32 angle);

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
			static Matrix Transformation(Vector3 const& translation, Vector3 const& axis, f32 angle, Vector3 const& scaling);

			/// <summary>�A�t�B���ϊ��s���Ԃ�</summary>
			/// <param name="translation">���s�ړ���</param>
			/// <param name="rotation">��]</param>
			/// <param name="scaling">�g��k����</param>
			static Matrix Transformation(Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

			// ---------------------------------------------------------------
			// �ϊ�����
			// ---------------------------------------------------------------

		public:

			/// <summary>���s�ړ�����</summary>
			/// <param name="translation">���s�ړ���</param>
			static Matrix& Translate(Matrix& matrix, Vector3 const& translation);

			/// <summary>��]����</summary>
			/// <param name="axis">��]��</param>
			/// <param name="angle">��]��</param>
			static Matrix& Rotate(Matrix& matrix, Vector3 const& axis, f32 angle);

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
			static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Vector3 const& axis, f32 angle, Vector3 const& scaling);

			/// <summary>�A�t�B���ϊ�����</summary>
			/// <param name="translation">���s�ړ���</param>
			/// <param name="rotation">��]</param>
			/// <param name="scaling">�g��k����</param>
			static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

			/// <summary>�]�u�s��ɂ���</summary>
			static Matrix& Transpose(Matrix& matrix);

			/// <summary>�t�s��ɂ���</summary>
			static Matrix& Inverse(Matrix& matrix);

			// ---------------------------------------------------------------
			// �ϊ��ςݍs���Ԃ�
			// ---------------------------------------------------------------

		public:

			/// <summary>���s�ړ������s���Ԃ�</summary>
			/// <param name="translation">���s�ړ���</param>
			static Matrix Translated(Matrix const& matrix, Vector3 const& translation);

			/// <summary>��]�����s���Ԃ�</summary>
			/// <param name="axis">��]��</param>
			/// <param name="angle">��]��</param>
			static Matrix Rotated(Matrix const& matrix, Vector3 const& axis, f32 angle);

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
			static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Vector3 const& axis, f32 angle, Vector3 const& scaling);

			/// <summary>�A�t�B���ϊ������s���Ԃ�</summary>
			/// <param name="translation">���s�ړ���</param>
			/// <param name="rotation">��]</param>
			/// <param name="scaling">�g��k����</param>
			static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

			/// <summary>�]�u�s���Ԃ�</summary>
			static Matrix Transposed(Matrix const& matrix);

			/// <summary>�t�s���Ԃ�</summary>
			static Matrix Inversed(Matrix const& matrix);

			// ---------------------------------------------------------------
			// �p�����[�^�擾
			// ---------------------------------------------------------------

		public:

			/// <summary>������x�N�g����Ԃ�</summary>
			static Vector4 Up(Matrix const& matrix);

			/// <summary>�E�����x�N�g����Ԃ�</summary>
			static Vector4 Right(Matrix const& matrix);

			/// <summary>�O�����x�N�g����Ԃ�</summary>
			static Vector4 Forward(Matrix const& matrix);

			/// <summary>���s�ړ�������Ԃ�</summary>
			static Vector3 Translation(Matrix const& matrix);

			/// <summary>��]������Ԃ�</summary>
			static Quaternion Rotation(Matrix const& matrix);

			/// <summary>�g��k��������Ԃ�</summary>
			static Vector3 Scaling(Matrix const& matrix);

			/// <summary>������������</summary>
			static Pose Decompose(Matrix const& matrix);

			/// <summary>�s�񎮂�Ԃ�</summary>
			static f32 Determinant(Matrix const& m);

			/// <summary>�N�H�[�^�j�I���ɕϊ�����</summary>
			static Quaternion ToQuaternion(Matrix const& matrix);

			// ---------------------------------------------------------------
			// ����ȍs�񐶐�
			// ---------------------------------------------------------------

		public:

			/// <summary>�r���[�s���Ԃ�</summary>
			static Matrix LookAt(Vector3 const& position, Vector3 const& target, Vector3 const& up);

			/// <summary>�����ˉe�s���Ԃ�</summary>
			static Matrix Perspective(f32 fov, f32 aspect, f32 nearclip, f32 farclip);

			/// <summary>�r���[�|�[�g�s���Ԃ�</summary>
			static Matrix Viewport(s32 width, s32 height);

		public:

			union
			{
				f32 elm[16];

				f32 mat[4][4];

				struct
				{
					f32 m11, m12, m13, m14;
					f32 m21, m22, m23, m24;
					f32 m31, m32, m33, m34;
					f32 m41, m42, m43, m44;
				};
			};
		};

		// ---------------------------------------------------------------
		// ���Z�q�I�[�o�[���[�h
		// ---------------------------------------------------------------

		bool operator == (Matrix const& m1, Matrix const& m2);
		bool operator != (Matrix const& m1, Matrix const& m2);
		Matrix operator * (Matrix const& m1, Matrix const& m2);
		Vector3 operator * (Vector3 const& v, Matrix const& m);
		Vector4 operator * (Vector4 const& v, Matrix const& m);
		Matrix& operator *= (Matrix& m1, Matrix const& m2);
		Vector3& operator *= (Vector3& v, Matrix const& m);
		Vector4& operator *= (Vector4& v, Matrix const& m);
	}
}

# pragma warning (pop)
