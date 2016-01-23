# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include <string>

namespace Transform
{
	// -------------------------------------------------------------------
	// 前置宣言
	// -------------------------------------------------------------------
	class Point4;
	class Vector3;


	/// <summary>三次元点</summary>
	class Point3
	{
	public:

		/// <summary>(0, 0, 0)で初期化された点を返す</summary>
		static Point3 const& Zero();

		/// <summary>(1, 1, 1)で初期化された点を返す</summary>
		static Point3 const& One();

		/// <summary>(-1, 0, 0)で初期化された点を返す</summary>
		static Point3 const& Left();

		/// <summary>(1, 0, 0)で初期化された点を返す</summary>
		static Point3 const& Right();

		/// <summary>(0, 1, 0)で初期化された点を返す</summary>
		static Point3 const& Up();

		/// <summary>(0, -1, 0)で初期化された点を返す</summary>
		static Point3 const& Down();

		/// <summary>(0, 0, 1)で初期化された点を返す</summary>
		static Point3 const& Forward();

		/// <summary>(0, 0, -1)で初期化された点を返す</summary>
		static Point3 const& Backward();

	public:

		/// <summary>コンストラクタ</summary>
		Point3();

		/// <summary>コピーコンストラクタ</summary>
		Point3(Point3 const& v);

		/// <summary>要素を指定して構築する</summary>
		Point3(int x, int y, int z);

		/// <summary>四次元点から構築する</summary>
		explicit Point3(Point4 const& v);

		/// <summary>三次元ベクトルから構築する</summary>
		explicit Point3(Vector3 const& v);

		/// <summary>代入演算子</summary>
		Point3& operator = (Point3 const& v);

	public:

		/// <summary>配列に変換する</summary>
		operator int* ();

		/// <summary>配列に変換する</summary>
		operator int const* () const;

	public:


		/// <summary>内積を返す</summary>
		/// <param name="v1">点</param>
		/// <param name="v2">点</param>
		static int Dot(Point3 const& v1, Point3 const& v2);

		/// <summary>外積を返す</summary>
		static Point3 Cross(Point3 const& v1, Point3 const& v2);

		/// <summary>長さの二乗を返す</summary>
		/// <param name="v">点</param>
		static int LengthSquared(Point3 const& v);

		/// <summary>長さを返す</summary>
		/// <param name="v">点</param>
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
