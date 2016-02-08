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
		class Vector3;
		class Point2;


		/// <summary>二次元ベクトル</summary>
		class Vector2
		{
		public:

			/// <summary>(0, 0)で初期化されたベクトルを返す</summary>
			static Vector2 const& Zero();

			/// <summary>(1, 1)で初期化されたベクトルを返す</summary>
			static Vector2 const& One();

			/// <summary>(-1, 0)で初期化されたベクトルを返す</summary>
			static Vector2 const& Left();

			/// <summary>(1, 0)で初期化されたベクトルを返す</summary>
			static Vector2 const& Right();

			/// <summary>(0, -1)で初期化されたベクトルを返す</summary>
			static Vector2 const& Up();

			/// <summary>(0, 1)で初期化されたベクトルを返す</summary>
			static Vector2 const& Down();

		public:

			/// <summary>コンストラクタ</summary>
			Vector2();

			/// <summary>コピーコンストラクタ</summary>
			Vector2(Vector2 const& v);

			/// <summary>要素を指定して構築する</summary>
			Vector2(f32 x, f32 y);

			/// <summary>三次元ベクトルから構築する</summary>
			explicit Vector2(Vector3 const& v);

			/// <summary>二次元点から構築する</summary>
			explicit Vector2(Point2 const& v);

			/// <summary>代入演算子</summary>
			Vector2& operator = (Vector2 const& v);

		public:

			/// <summary>内積を返す</summary>
			/// <param name="v1">ベクトル</param>
			/// <param name="v2">ベクトル</param>
			static f32 Dot(Vector2 const& v1, Vector2 const& v2);

			/// <summary>外積を返す</summary>
			static f32 Cross(Vector2 const& v1, Vector2 const& v2);

			/// <summary>長さの二乗を返す</summary>
			/// <param name="v">ベクトル</param>
			static f32 LengthSquared(Vector2 const& v);

			/// <summary>長さを返す</summary>
			/// <param name="v">ベクトル</param>
			static f32 Length(Vector2 const& v);

			/// <summary>正規化したベクトルを返す</summary>
			/// <param name="v">ベクトル</param>
			static Vector2 Nornalize(Vector2 const& v);

			/// <summary>任意軸で回転したベクトル返す</summary>
			/// <param name="pos32">任意点</param>
			/// <param name="origin">中心点</param>
			/// <param name="angle">回転量</param>
			static Vector2 Rotate(Vector2 const& pos32, Vector2 const& origin, f32 angle);

			/// <summary>投影したベクトルを返す</summary>
			/// <param name="v">ベクトル</param>
			/// <param name="target">対象のベクトル</param>
			static Vector2 Projection(Vector2 const& v, Vector2 const& target);

			/// <summary>ベクトルのなす角を返す</summary>
			static f32 Angle(Vector2 const& v1, Vector2 const& v2);

		public:

			union
			{
				f32 elm[2];

				f32 mat[1][2];

				struct
				{
					f32 u, v;
				};

				struct
				{
					f32 x, y;
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

		Vector2& operator *= (Vector2& v, f32 s);

		Vector2& operator /= (Vector2& v1, Vector2 const& v2);

		Vector2& operator /= (Vector2& v, f32 s);

		Vector2 operator + (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator - (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator * (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator * (Vector2 const& v, f32 s);

		Vector2 operator * (f32 s, Vector2 const& v);

		Vector2 operator / (Vector2 const& v1, Vector2 const& v2);

		Vector2 operator / (Vector2 const& v, f32 s);
	}
}

# pragma warning (pop)
