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
		// 前置宣言
		// -------------------------------------------------------------------
		class Point3;
		class Vector4;


		/// <summary>四次元点</summary>
		class Point4
		{
		public:

			/// <summary>(0, 0, 0, 0)で初期化された点を返す</summary>
			static Point4 const& zero();

			/// <summary>(1, 1, 1, 1)で初期化された点を返す</summary>
			static Point4 const& one();

		public:

			/// <summary>コンストラクタ</summary>
			Point4();

			/// <summary>コピーコンストラクタ</summary>
			Point4(Point4 const& v);

			/// <summary>要素を指定して構築する</summary>
			Point4(s32 x, s32 y, s32 z, s32 w);

			/// <summary>三次元点とw要素を指定して構築する</summary>
			Point4(Point3 const& v, s32 w);

			/// <summary>四次元ベクトルから構築する</summary>
			explicit Point4(Vector4 const& v);

			/// <summary>代入演算子</summary>
			Point4& operator = (Point4 const& v);

		public:

			/// <summary>配列に変換する</summary>
			operator s32* ();

			/// <summary>配列に変換する</summary>
			operator s32 const* () const;

		public:

			/// <summary>内積を返す</summary>
			static s32 Dot(Point4 const& v1, Point4 const& v2);

			/// <summary>長さの二乗を返す</summary>
			/// <param name="v">点</param>
			static s32 LengthSquared(Point4 const& v);

			/// <summary>長さを返す</summary>
			/// <param name="v">点</param>
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
