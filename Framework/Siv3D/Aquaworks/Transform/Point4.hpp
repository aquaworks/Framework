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
		class Vector4;


		/// <summary>�l�����_</summary>
		class Point4
		{
		public:

			/// <summary>(0, 0, 0, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point4 const& zero();

			/// <summary>(1, 1, 1, 1)�ŏ��������ꂽ�_��Ԃ�</summary>
			static Point4 const& one();

		public:

			/// <summary>�R���X�g���N�^</summary>
			Point4();

			/// <summary>�R�s�[�R���X�g���N�^</summary>
			Point4(Point4 const& v);

			/// <summary>�v�f���w�肵�č\�z����</summary>
			Point4(s32 x, s32 y, s32 z, s32 w);

			/// <summary>�O�����_��w�v�f���w�肵�č\�z����</summary>
			Point4(Point3 const& v, s32 w);

			/// <summary>�l�����x�N�g������\�z����</summary>
			explicit Point4(Vector4 const& v);

			/// <summary>������Z�q</summary>
			Point4& operator = (Point4 const& v);

		public:

			/// <summary>�z��ɕϊ�����</summary>
			operator s32* ();

			/// <summary>�z��ɕϊ�����</summary>
			operator s32 const* () const;

		public:

			/// <summary>���ς�Ԃ�</summary>
			static s32 Dot(Point4 const& v1, Point4 const& v2);

			/// <summary>�����̓���Ԃ�</summary>
			/// <param name="v">�_</param>
			static s32 LengthSquared(Point4 const& v);

			/// <summary>������Ԃ�</summary>
			/// <param name="v">�_</param>
			static f32 Length(Point4 const& v);

		public:

			union
			{
				s32 elm[4];

				s32 mat[1][4];

				struct
				{
					s32 r, g, b, a;
				};

				struct
				{
					s32 x, y, z, w;
				};
			};
		};

		bool operator == (Point4 const& v1, Point4 const& v2);

		bool operator != (Point4 const& v1, Point4 const& v2);

		Point4 operator + (Point4 const& v);

		Point4 operator - (Point4 const& v);

		Point4& operator += (Point4& v1, Point4 const& v2);

		Point4& operator -= (Point4& v1, Point4 const& v2);

		Point4& operator *= (Point4& v1, Point4 const& v2);

		Point4& operator *= (Point4& v, s32 s);

		Point4& operator /= (Point4& v1, Point4 const& v2);

		Point4& operator /= (Point4& v, s32 s);

		Point4 operator + (Point4 const& v1, Point4 const& v2);

		Point4 operator - (Point4 const& v1, Point4 const& v2);

		Point4 operator * (Point4 const& v1, Point4 const& v2);

		Point4 operator * (Point4 const& v, s32 s);

		Point4 operator * (s32 s, Point4 const& v);

		Point4 operator / (Point4 const& v1, Point4 const& v2);

		Point4 operator / (Point4 const& v, s32 s);
	}
}

# pragma warning (pop)
