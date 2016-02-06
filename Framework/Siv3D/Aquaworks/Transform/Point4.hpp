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
			Point4(int x, int y, int z, int w);

			/// <summary>�O�����_��w�v�f���w�肵�č\�z����</summary>
			Point4(Point3 const& v, int w);

			/// <summary>�l�����x�N�g������\�z����</summary>
			explicit Point4(Vector4 const& v);

			/// <summary>������Z�q</summary>
			Point4& operator = (Point4 const& v);

		public:

			/// <summary>�z��ɕϊ�����</summary>
			operator int* ();

			/// <summary>�z��ɕϊ�����</summary>
			operator int const* () const;

		public:

			/// <summary>���ς�Ԃ�</summary>
			static int Dot(Point4 const& v1, Point4 const& v2);

			/// <summary>�����̓���Ԃ�</summary>
			/// <param name="v">�_</param>
			static int LengthSquared(Point4 const& v);

			/// <summary>������Ԃ�</summary>
			/// <param name="v">�_</param>
			static float Length(Point4 const& v);

		public:

			union
			{
				int elm[4];

				int mat[1][4];

				struct
				{
					int r, g, b, a;
				};

				struct
				{
					int x, y, z, w;
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

		Point4& operator *= (Point4& v, int s);

		Point4& operator /= (Point4& v1, Point4 const& v2);

		Point4& operator /= (Point4& v, int s);

		Point4 operator + (Point4 const& v1, Point4 const& v2);

		Point4 operator - (Point4 const& v1, Point4 const& v2);

		Point4 operator * (Point4 const& v1, Point4 const& v2);

		Point4 operator * (Point4 const& v, int s);

		Point4 operator * (int s, Point4 const& v);

		Point4 operator / (Point4 const& v1, Point4 const& v2);

		Point4 operator / (Point4 const& v, int s);
	}
}

# pragma warning (pop)
