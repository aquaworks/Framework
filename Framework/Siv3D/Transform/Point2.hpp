# pragma once

# include <string>

namespace Transform
{
	// -------------------------------------------------------------------
	// 前置宣言
	// -------------------------------------------------------------------
	class Point3;
	class Vector2;

	/// <summary>二次元点</summary>
	class Point2
	{
	public:

		/// <summary>(0, 0)で初期化された点を返す</summary>
		static Point2 const& Zero();

		/// <summary>(1, 1)で初期化された点を返す</summary>
		static Point2 const& One();

		/// <summary>(-1, 0)で初期化された点を返す</summary>
		static Point2 const& Left();

		/// <summary>(1, 0)で初期化された点を返す</summary>
		static Point2 const& Right();

		/// <summary>(0, -1)で初期化された点を返す</summary>
		static Point2 const& Up();

		/// <summary>(0, 1)で初期化された点を返す</summary>
		static Point2 const& Down();

	public:

		/// <summary>コンストラクタ</summary>
		Point2();

		/// <summary>コピーコンストラクタ</summary>
		Point2(Point2 const& v);

		/// <summary>要素を指定して構築する</summary>
		Point2(int x, int y);

		/// <summary>三次元点から構築する</summary>
		Point2(Point3 const& v);

		/// <summary>二次元点から構築する</summary>
		Point2(Vector2 const& v);

		/// <summary>代入演算子</summary>
		Point2& operator = (Point2 const& v);

	public:

		/// <summary>配列に変換する</summary>
		operator int* ();

		/// <summary>配列に変換する</summary>
		operator int const* () const;

	public:

		/// <summary>文字列に変換して返す</summary>
		std::wstring toString() const;

		/// <summary>内積を返す</summary>
		/// <param name="v">点</param>
		int dot(Point2 const& v) const;

		/// <summary>外積を返す</summary>
		/// <param name="v">点</param>
		int cross(Point2 const& v) const;

		/// <summary>長さの二乗を返す</summary>
		/// <param name="v">点</param>
		int lengthSquared() const;

		/// <summary>長さを返す</summary>
		/// <param name="v">点</param>
		float length() const;

	public:

		/// <summary>文字列に変換して返す</summary>
		/// <param name="v">点</param>
		static std::wstring ToString(Point2 const& v);

		/// <summary>内積を返す</summary>
		/// <param name="v1">点</param>
		/// <param name="v2">点</param>
		static int Dot(Point2 const& v1, Point2 const& v2);

		/// <summary>外積を返す</summary>
		static int Cross(Point2 const& v1, Point2 const& v2);

		/// <summary>長さの二乗を返す</summary>
		/// <param name="v">点</param>
		static int LengthSquared(Point2 const& v);

		/// <summary>長さを返す</summary>
		/// <param name="v">点</param>
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
