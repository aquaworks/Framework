# pragma once

# include "Vector4.hpp"
# include "Matrix.hpp"

namespace Aquaworks
{
	namespace Transform
	{
		// -------------------------------------------------------------------
		// �O�u�錾
		// -------------------------------------------------------------------

		class Matrix;

		class Quaternion
		{
			// ---------------------------------------------------------------
			// �V�X�e��
			// ---------------------------------------------------------------

		public:

			Quaternion();

			Quaternion(Quaternion const& q);

			Quaternion(f32 x, f32 y, f32 z, f32 w);

			// ---------------------------------------------------------------
			// �萔
			// ---------------------------------------------------------------

		public:

			/// <summary>�P�ʃN�H�[�^�j�I����Ԃ�</summary>
			static Quaternion& Identity();

			// ---------------------------------------------------------------
			// �ϊ�����
			// ---------------------------------------------------------------

		public:

			/// <summary>�C�ӎ���]���s�Ȃ�</summary>
			Quaternion& Rotate(Vector3 const& axis, f32 angle);

			/// <summary>���[����]���s�Ȃ�</summary>
			Quaternion& Roll(f32 angle);

			/// <summary>�s�b�`��]���s�Ȃ�</summary>
			Quaternion& Pitch(f32 angle);

			/// <summary>���[��]���s�Ȃ�</summary>
			Quaternion& Yaw(f32 angle);

			/// <summary>�s��ɕϊ�����</summary>
			Matrix ToMatrix();

			// ---------------------------------------------------------------
			// �ϊ��N�H�[�^�j�I����Ԃ�
			// ---------------------------------------------------------------

		public:

			/// <summary>�C�ӎ���]�N�H�[�^�j�I����Ԃ�</summary>
			static Quaternion Rotation(Vector3 const& axis, f32 angle);

			/// <summary>�s��ɕϊ�����</summary>
			static Matrix ToMatrix(Quaternion const& q);

			/// <summary>�����N�H�[�^�j�I����Ԃ�</summary>
			static Quaternion Conjugate(Quaternion const& q);

		public:

			f32 x, y, z, w;
		};

		// ---------------------------------------------------------------
		// ���Z�q�I�[�o�[���[�h
		// ---------------------------------------------------------------

		Quaternion operator * (Quaternion const& q1, Quaternion const& q2);
		Quaternion& operator *= (Quaternion& q1, Quaternion const& q2);
		Vector3 operator * (Vector3 const& v, Quaternion const& q);
		Vector3& operator *= (Vector3 & v, Quaternion const& q);
	}
}
