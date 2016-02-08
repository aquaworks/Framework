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
		class Point4;


		/// <summary>四次元ベクトル</summary>
		class Vector4
		{
		public:

			/// <summary>(0, 0, 0)で初期化されたベクトルを返す</summary>
			static Vector4 const& Zero();

			/// <summary>(1, 1, 1)で初期化されたベクトルを返す</summary>
			static Vector4 const& One();

		public:

			/// <summary>コンストラクタ</summary>
			Vector4();

			/// <summary>コピーコンストラクタ</summary>
			Vector4(Vector4 const& v);

			/// <summary>要素を指定して構築する</summary>
			Vector4(f32 x, f32 y, f32 z, f32 w);

			/// <summary>三次元ベクトルとw要素を指定して構築する</summary>
			Vector4(Vector3 const& v, f32 w);

			/// <summary>四次元点から構築する</summary>
			explicit Vector4(Point4 const& v);

			/// <summary>代入演算子</summary>
			Vector4& operator = (Vector4 const& v);

		public:

			/// <summary>内積を返す</summary>
			static f32 Dot(Vector4 const& v1, Vector4 const& v2);

			/// <summary>長さの二乗を返す</summary>
			/// <param name="v">ベクトル</param>
			static f32 LengthSquared(Vector4 const& v);

			/// <summary>長さを返す</summary>
			/// <param name="v">ベクトル</param>
			static f32 Length(Vector4 const& v);

			/// <summary>正規化したベクトル返す</summary>
			/// <param name="v">ベクトル</param>
			static Vector4 Normalize(Vector4 const& v);

			/// <summary>射影したベクトルを返す</summary>
			/// <param name="v">ベクトル</param>
			/// <param name="target">対象のベクトル</param>
			static Vector4 Projection(Vector4 const& v, Vector4 const& target);

		public:

			union
			{
				f32 elm[4];

				f32 mat[1][4];

				struct
				{
					f32 r, g, b, a;
				};

				struct
				{
					f32 x, y, z, w;
				};
			};
		};

		bool operator == (Vector4 const& v1, Vector4 const& v2);

		bool operator != (Vector4 const& v1, Vector4 const& v2);

		Vector4 operator + (Vector4 const& v);

		Vector4 operator - (Vector4 const& v);

		Vector4& operator += (Vector4& v1, Vector4 const& v2);

		Vector4& operator -= (Vector4& v1, Vector4 const& v2);

		Vector4& operator *= (Vector4& v1, Vector4 const& v2);

		Vector4& operator *= (Vector4& v, f32 s);

		Vector4& operator /= (Vector4& v1, Vector4 const& v2);

		Vector4& operator /= (Vector4& v, f32 s);

		Vector4 operator + (Vector4 const& v1, Vector4 const& v2);

		Vector4 operator - (Vector4 const& v1, Vector4 const& v2);

		Vector4 operator * (Vector4 const& v1, Vector4 const& v2);

		Vector4 operator * (Vector4 const& v, f32 s);

		Vector4 operator * (f32 s, Vector4 const& v);

		Vector4 operator / (Vector4 const& v1, Vector4 const& v2);

		Vector4 operator / (Vector4 const& v, f32 s);
	}
}

# pragma warning (pop)
