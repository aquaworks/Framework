# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include <string>

namespace Transform
{
	// -------------------------------------------------------------------
	// �O�u�錾
	// -------------------------------------------------------------------
	class Point4;
	class Vector3;


	/// <summary>�O�����_</summary>
	class Point3
	{
	public:

		/// <summary>(0, 0, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Zero();

		/// <summary>(1, 1, 1)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& One();

		/// <summary>(-1, 0, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Left();

		/// <summary>(1, 0, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Right();

		/// <summary>(0, 1, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Up();

		/// <summary>(0, -1, 0)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Down();

		/// <summary>(0, 0, 1)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Forward();

		/// <summary>(0, 0, -1)�ŏ��������ꂽ�_��Ԃ�</summary>
		static Point3 const& Backward();

	public:

		/// <summary>�R���X�g���N�^</summary>
		Point3();

		/// <summary>�R�s�[�R���X�g���N�^</summary>
		Point3(Point3 const& v);

		/// <summary>�v�f���w�肵�č\�z����</summary>
		Point3(int x, int y, int z);

		/// <summary>�l�����_����\�z����</summary>
		explicit Point3(Point4 const& v);

		/// <summary>�O�����x�N�g������\�z����</summary>
		explicit Point3(Vector3 const& v);

		/// <summary>������Z�q</summary>
		Point3& operator = (Point3 const& v);

	public:

		/// <summary>�z��ɕϊ�����</summary>
		operator int* ();

		/// <summary>�z��ɕϊ�����</summary>
		operator int const* () const;

	public:


		/// <summary>���ς�Ԃ�</summary>
		/// <param name="v1">�_</param>
		/// <param name="v2">�_</param>
		static int Dot(Point3 const& v1, Point3 const& v2);

		/// <summary>�O�ς�Ԃ�</summary>
		static Point3 Cross(Point3 const& v1, Point3 const& v2);

		/// <summary>�����̓���Ԃ�</summary>
		/// <param name="v">�_</param>
		static int LengthSquared(Point3 const& v);

		/// <summary>������Ԃ�</summary>
		/// <param name="v">�_</param>
		static float Length(Point3 const& v);

	public:

		union
		{
			int elm[3];

			int mat[1][3];

			struct
			{
				int r, g, b;
			};

			struct
			{
				int x, y, z;
			};
		};
	};

	bool operator == (Point3 const& v1, Point3 const& v2);

	bool operator != (Point3 const& v1, Point3 const& v2);

	Point3 operator + (Point3 const& v);

	Point3 operator - (Point3 const& v);

	Point3& operator += (Point3& v1, Point3 const& v2);

	Point3& operator -= (Point3& v1, Point3 const& v2);

	Point3& operator *= (Point3& v1, Point3 const& v2);

	Point3& operator *= (Point3& v, int s);

	Point3& operator /= (Point3& v1, Point3 const& v2);

	Point3& operator /= (Point3& v, int s);

	Point3 operator + (Point3 const& v1, Point3 const& v2);

	Point3 operator - (Point3 const& v1, Point3 const& v2);

	Point3 operator * (Point3 const& v1, Point3 const& v2);

	Point3 operator * (Point3 const& v, int s);

	Point3 operator * (int s, Point3 const& v);

	Point3 operator / (Point3 const& v1, Point3 const& v2);

	Point3 operator / (Point3 const& v, int s);
}

# pragma warning (pop)
