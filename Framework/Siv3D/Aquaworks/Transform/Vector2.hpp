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
		class Vector3;
		class Point2;


		/// <summary>�񎟌��x�N�g��</summary>
		class Vector2
		{
		public:

			/// <summary>(0, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector2 const& Zero();

			/// <summary>(1, 1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector2 const& One();

			/// <summary>(-1, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector2 const& Left();

			/// <summary>(1, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector2 const& Right();

			/// <summary>(0, -1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector2 const& Up();

			/// <summary>(0, 1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
			static Vector2 const& Down();

		public:

			/// <summary>�R���X�g���N�^</summary>
			Vector2();

			/// <summary>�R�s�[�R���X�g���N�^</summary>
			Vector2(Vector2 const& v);

			/// <summary>�v�f���w�肵�č\�z����</summary>
			Vector2(float x, float y);

			/// <summary>�O�����x�N�g������\�z����</summary>
			explicit Vector2(Vector3 const& v);

			/// <summary>�񎟌��_����\�z����</summary>
			explicit Vector2(Point2 const& v);

			/// <summary>������Z�q</summary>
			Vector2& operator = (Vector2 const& v);

		public:

			/// <summary>���ς�Ԃ�</summary>
			/// <param name="v1">�x�N�g��</param>
			/// <param name="v2">�x�N�g��</param>
			static float Dot(Vector2 const& v1, Vector2 const& v2);

			/// <summary>�O�ς�Ԃ�</summary>
			static float Cross(Vector2 const& v1, Vector2 const& v2);

			/// <summary>�����̓���Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static float LengthSquared(Vector2 const& v);

			/// <summary>������Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static float Length(Vector2 const& v);

			/// <summary>���K�������x�N�g����Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			static Vector2 Nornalize(Vector2 const& v);

			/// <summary>�C�ӎ��ŉ�]�����x�N�g���Ԃ�</summary>
			/// <param name="point">�C�ӓ_</param>
			/// <param name="origin">���S�_</param>
			/// <param name="angle">��]��</param>
			static Vector2 Rotate(Vector2 const& point, Vector2 const& origin, float angle);

			/// <summary>���e�����x�N�g����Ԃ�</summary>
			/// <param name="v">�x�N�g��</param>
			/// <param name="target">�Ώۂ̃x�N�g��</param>
			static Vector2 Projection(Vector2 const& v, Vector2 const& target);

			/// <summary>�x�N�g���̂Ȃ��p��Ԃ�</summary>
			static float Angle(Vector2 const& v1, Vector2 const& v2);

		public:

			union
			{
				float elm[2];

				float mat[1][2];

				struct
				{
					float u, v;
				};

				struct
				{
					float x, y;
				};
			};
		};

		bool operator == (Vector2 const& v1, Vector2 const& v2);

		bool operator != (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator + (Vector2 const& v);

		Vector2 operator - (Vector2 const& v);

		Vector2& operator += (Vector2& v1, Vector2 const& v2);

		Vector2& operator -= (Vector2& v1, Vector2 const& v2);

		Vector2& operator *= (Vector2& v1, Vector2 const& v2);

		Vector2& operator *= (Vector2& v, float s);

		Vector2& operator /= (Vector2& v1, Vector2 const& v2);

		Vector2& operator /= (Vector2& v, float s);

		Vector2 operator + (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator - (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator * (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator * (Vector2 const& v, float s);

		Vector2 operator * (float s, Vector2 const& v);

		Vector2 operator / (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator / (Vector2 const& v, float s);
	}
}

# pragma warning (pop)