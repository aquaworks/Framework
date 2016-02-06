# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include <string>

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
			Vector3(float x, float y, float z);

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
			static float Dot(Vector3 const& v1, Vector3 const& v2);

			/// <summary>�O�ς�Ԃ�</summary>
			static Vector3 Cross(Vector3 const& v1, Vector3 const& v2);

			/// <summary>�����̓���Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static float LengthSquared(Vector3 const& v);

			/// <summary>������Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static float Length(Vector3 const& v);

			/// <summary>���K�������x�N�g����Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static Vector3 Normalize(Vector3 const& v);

			/// <summary>�C�ӎ��ŉ�]�����x�N�g���Ԃ�</summary>
			/// <param name="point">�C�ӓ_</param>
			/// <param name="axis">��]��</param>
			/// <param name="angle">��]��</param>
			static Vector3 Rotate(Vector3 const& point, Vector3 const& axis, float angle);

			/// <summary>���e�����x�N�g����Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			/// <param name="target">�Ώۂ̃x�N�g��</param>
			static Vector3 Projection(Vector3 const& v, Vector3 const& target);

			/// <summary>�x�N�g���̂Ȃ��p��Ԃ�</summary>
			static float Angle(Vector3 const& v1, Vector3 const& v2);

			/// <summary>���ʐ��`��Ԃ����x�N�g����Ԃ�</summary>
			/// <param name="start">�J�n�x�N�g��</param>
			/// <param name="end">�I���x�N�g��</param>
			/// <param name="t">�J�ڗ�</param>
			static Vector3 Slerp(Vector3 const& start, Vector3 const& end, float t);

		public:

			union
			{
				float elm[3];

				float mat[1][3];

				struct
				{
					float r, g, b;
				};

				struct
				{
					float x, y, z;
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

		Vector3& operator *= (Vector3& v, float s);

		Vector3& operator /= (Vector3& v1, Vector3 const& v2);

		Vector3& operator /= (Vector3& v, float s);

		Vector3 operator + (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator - (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator * (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator * (Vector3 const& v, float s);

		Vector3 operator * (float s, Vector3 const& v);

		Vector3 operator / (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator / (Vector3 const& v, float s);
	}
}

# pragma warning (pop)
