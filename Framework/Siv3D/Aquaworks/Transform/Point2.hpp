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
		class Point3;
		class Vector2;

		/// <summary>�񎟌��_</summary>
		class Point2
		{
		public:

			/// <summary>(0, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point2 const& Zero();

			/// <summary>(1, 1)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point2 const& One();

			/// <summary>(-1, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point2 const& Left();

			/// <summary>(1, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point2 const& Right();

			/// <summary>(0, -1)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point2 const& Up();

			/// <summary>(0, 1)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point2 const& Down();

		public:

			/// <summary>�R���X�g���N�^</summary>
			Point2();

			/// <summary>�R�s�[�R���X�g���N�^</summary>
			Point2(Point2 const& v);

			/// <summary>�v�f���w�肵�č\�z����</summary>
			Point2(s32 x, s32 y);

			/// <summary>�O�����_����\�z����</summary>
			Point2(Point3 const& v);

			/// <summary>�񎟌��_����\�z����</summary>
			Point2(Vector2 const& v);

			/// <summary>������Z�q</summary>
			Point2& operator = (Point2 const& v);

		public:

			/// <summary>�z��ɕϊ�����</summary>
			operator s32* ();

			/// <summary>�z��ɕϊ�����</summary>
			operator s32 const* () const;

		public:

			/// <summary>���ς�Ԃ�</summary>
			/// <param name="v1">�_</param>
			/// <param name="v2">�_</param>
			static s32 Dot(Point2 const& v1, Point2 const& v2);

			/// <summary>�O�ς�Ԃ�</summary>
			static s32 Cross(Point2 const& v1, Point2 const& v2);

			/// <summary>�����̓���Ԃ�</summary>
			/// <param name="v">�_</param>
			static s32 LengthSquared(Point2 const& v);

			/// <summary>������Ԃ�</summary>
			/// <param name="v">�_</param>
			static f32 Length(Point2 const& v);

		public:

			union
			{
				s32 elm[2];

				s32 mat[1][2];

				struct
				{
					s32 u, v;
				};

				struct
				{
					s32 x, y;
				};
			};
		};

		bool operator == (Point2 const& v1, Point2 const& v2);

		bool operator != (Point2 const& v1, Point2 const& v2);

		Point2 operator + (Point2 const& v);

		Point2 operator - (Point2 const& v);

		Point2& operator += (Point2& v1, Point2 const& v2);

		Point2& operator -= (Point2& v1, Point2 const& v2);

		Point2& operator *= (Point2& v1, Point2 const& v2);

		Point2& operator *= (Point2& v, s32 s);

		Point2& operator /= (Point2& v1, Point2 const& v2);

		Point2& operator /= (Point2& v, s32 s);

		Point2 operator + (Point2 const& v1, Point2 const& v2);

		Point2 operator - (Point2 const& v1, Point2 const& v2);

		Point2 operator * (Point2 const& v1, Point2 const& v2);

		Point2 operator * (Point2 const& v, s32 s);

		Point2 operator * (s32 s, Point2 const& v);

		Point2 operator / (Point2 const& v1, Point2 const& v2);

		Point2 operator / (Point2 const& v, s32 s);
	}
}

# pragma warning (pop)
