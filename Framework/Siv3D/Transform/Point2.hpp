# pragma once

# include <string>

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
		Point2(int x, int y);

		/// <summary>�O�����_����\�z����</summary>
		Point2(Point3 const& v);

		/// <summary>�񎟌��_����\�z����</summary>
		Point2(Vector2 const& v);

		/// <summary>������Z�q</summary>
		Point2& operator = (Point2 const& v);

	public:

		/// <summary>�z��ɕϊ�����</summary>
		operator int* ();

		/// <summary>�z��ɕϊ�����</summary>
		operator int const* () const;

	public:

		/// <summary>������ɕϊ����ĕԂ�</summary>
		std::wstring toString() const;

		/// <summary>���ς�Ԃ�</summary>
		/// <param name="v">�_</param>
		int dot(Point2 const& v) const;

		/// <summary>�O�ς�Ԃ�</summary>
		/// <param name="v">�_</param>
		int cross(Point2 const& v) const;

		/// <summary>�����̓���Ԃ�</summary>
		/// <param name="v">�_</param>
		int lengthSquared() const;

		/// <summary>������Ԃ�</summary>
		/// <param name="v">�_</param>
		float length() const;

	public:

		/// <summary>������ɕϊ����ĕԂ�</summary>
		/// <param name="v">�_</param>
		static std::wstring ToString(Point2 const& v);

		/// <summary>���ς�Ԃ�</summary>
		/// <param name="v1">�_</param>
		/// <param name="v2">�_</param>
		static int Dot(Point2 const& v1, Point2 const& v2);

		/// <summary>�O�ς�Ԃ�</summary>
		static int Cross(Point2 const& v1, Point2 const& v2);

		/// <summary>�����̓���Ԃ�</summary>
		/// <param name="v">�_</param>
		static int LengthSquared(Point2 const& v);

		/// <summary>������Ԃ�</summary>
		/// <param name="v">�_</param>
		static float Length(Point2 const& v);

	public:

		union
		{
			int elm[2];

			int mat[1][2];

			struct
			{
				int u, v;
			};

			struct
			{
				int x, y;
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

	Point2& operator *= (Point2& v, int s);

	Point2& operator /= (Point2& v1, Point2 const& v2);

	Point2& operator /= (Point2& v, int s);

	Point2 operator + (Point2 const& v1, Point2 const& v2);

	Point2 operator - (Point2 const& v1, Point2 const& v2);

	Point2 operator * (Point2 const& v1, Point2 const& v2);

	Point2 operator * (Point2 const& v, int s);

	Point2 operator * (int s, Point2 const& v);

	Point2 operator / (Point2 const& v1, Point2 const& v2);

	Point2 operator / (Point2 const& v, int s);
}
