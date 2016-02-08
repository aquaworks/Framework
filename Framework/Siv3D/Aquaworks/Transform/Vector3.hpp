# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include <string>

# include "../Typedef.hpp"

namespace Aquaworks
{
	namespace Transform
	{
		// -------------------------------------------------------------------
		// �O�u�錾
		// -------------------------------------------------------------------
		class Vector4;
		class Point3;


		/// <summary>�O�����x�N�g��</summary>
		class Vector3
		{
		public:

			/// <summary>(0, 0, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Zero();

			/// <summary>(1, 1, 1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& One();

			/// <summary>(-1, 0, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Left();

			/// <summary>(1, 0, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Right();

			/// <summary>(0, 1, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Up();

			/// <summary>(0, -1, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Down();

			/// <summary>(0, 0, 1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Forward();

			/// <summary>(0, 0, -1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector3 const& Backward();

		public:

			/// <summary>�R���X�g���N�^</summary>
			Vector3();

			/// <summary>�R�s�[�R���X�g���N�^</summary>
			Vector3(Vector3 const& v);

			/// <summary>�v�f���w�肵�č\�z����</summary>
			Vector3(f32 x, f32 y, f32 z);

			/// <summary>�l�����x�N�g������\�z����</summary>
			Vector3(Vector4 const& v);

			/// <summary>�O�����_����\�z����</summary>
			Vector3(Point3 const& v);

			/// <summary>������Z�q</summary>
			Vector3& operator = (Vector3 const& v);

		public:

			/// <summary>���ς�Ԃ�</summary>
			/// <param name="v1">�x�N�g��</param>
			/// <param name="v2">�x�N�g��</param>
			static f32 Dot(Vector3 const& v1, Vector3 const& v2);

			/// <summary>�O�ς�Ԃ�</summary>
			static Vector3 Cross(Vector3 const& v1, Vector3 const& v2);

			/// <summary>�����̓���Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static f32 LengthSquared(Vector3 const& v);

			/// <summary>������Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static f32 Length(Vector3 const& v);

			/// <summary>���K�������x�N�g����Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static Vector3 Normalize(Vector3 const& v);

			/// <summary>�C�ӎ��ŉ�]�����x�N�g���Ԃ�</summary>
			/// <param name="pos32">�C�ӓ_</param>
			/// <param name="axis">��]��</param>
			/// <param name="angle">��]��</param>
			static Vector3 Rotate(Vector3 const& pos32, Vector3 const& axis, f32 angle);

			/// <summary>���e�����x�N�g����Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			/// <param name="target">�Ώۂ̃x�N�g��</param>
			static Vector3 Projection(Vector3 const& v, Vector3 const& target);

			/// <summary>�x�N�g���̂Ȃ��p��Ԃ�</summary>
			static f32 Angle(Vector3 const& v1, Vector3 const& v2);

			/// <summary>���ʐ��`��Ԃ����x�N�g����Ԃ�</summary>
			/// <param name="start">�J�n�x�N�g��</param>
			/// <param name="end">�I���x�N�g��</param>
			/// <param name="t">�J�ڗ�</param>
			static Vector3 Slerp(Vector3 const& start, Vector3 const& end, f32 t);

		public:

			union
			{
				f32 elm[3];

				f32 mat[1][3];

				struct
				{
					f32 r, g, b;
				};

				struct
				{
					f32 x, y, z;
				};
			};
		};

		bool operator == (Vector3 const& v1, Vector3 const& v2);

		bool operator != (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator + (Vector3 const& v);

		Vector3 operator - (Vector3 const& v);

		Vector3& operator += (Vector3& v1, Vector3 const& v2);

		Vector3& operator -= (Vector3& v1, Vector3 const& v2);

		Vector3& operator *= (Vector3& v1, Vector3 const& v2);

		Vector3& operator *= (Vector3& v, f32 s);

		Vector3& operator /= (Vector3& v1, Vector3 const& v2);

		Vector3& operator /= (Vector3& v, f32 s);

		Vector3 operator + (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator - (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator * (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator * (Vector3 const& v, f32 s);

		Vector3 operator * (f32 s, Vector3 const& v);

		Vector3 operator / (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator / (Vector3 const& v, f32 s);
	}
}

# pragma warning (pop)
