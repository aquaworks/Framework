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
		class Vector4;
		class Point3;


		/// <summary>三次元ベクトル</summary>
		class Vector3
		{
		public:

			/// <summary>(0, 0, 0)で初期化されたベクトルを返す</summary>
			static Vector3 const& Zero();

			/// <summary>(1, 1, 1)で初期化されたベクトルを返す</summary>
			static Vector3 const& One();

			/// <summary>(-1, 0, 0)で初期化されたベクトルを返す</summary>
			static Vector3 const& Left();

			/// <summary>(1, 0, 0)で初期化されたベクトルを返す</summary>
			static Vector3 const& Right();

			/// <summary>(0, 1, 0)で初期化されたベクトルを返す</summary>
			static Vector3 const& Up();

			/// <summary>(0, -1, 0)で初期化されたベクトルを返す</summary>
			static Vector3 const& Down();

			/// <summary>(0, 0, 1)で初期化されたベクトルを返す</summary>
			static Vector3 const& Forward();

			/// <summary>(0, 0, -1)で初期化されたベクトルを返す</summary>
			static Vector3 const& Backward();

		public:

			/// <summary>コンストラクタ</summary>
			Vector3();

			/// <summary>コピーコンストラクタ</summary>
			Vector3(Vector3 const& v);

			/// <summary>要素を指定して構築する</summary>
			Vector3(f32 x, f32 y, f32 z);

			/// <summary>四次元ベクトルから構築する</summary>
			Vector3(Vector4 const& v);

			/// <summary>三次元点から構築する</summary>
			Vector3(Point3 const& v);

			/// <summary>代入演算子</summary>
			Vector3& operator = (Vector3 const& v);

		public:

			/// <summary>内積を返す</summary>
			/// <param name="v1">ベクトル</param>
			/// <param name="v2">ベクトル</param>
			static f32 Dot(Vector3 const& v1, Vector3 const& v2);

			/// <summary>外積を返す</summary>
			static Vector3 Cross(Vector3 const& v1, Vector3 const& v2);

			/// <summary>長さの二乗を返す</summary>
			/// <param name="v">ベクトル</param>
			static f32 LengthSquared(Vector3 const& v);

			/// <summary>長さを返す</summary>
			/// <param name="v">ベクトル</param>
			static f32 Length(Vector3 const& v);

			/// <summary>正規化したベクトルを返す</summary>
			/// <param name="v">ベクトル</param>
			static Vector3 Normalize(Vector3 const& v);

			/// <summary>任意軸で回転したベクトル返す</summary>
			/// <param name="pos32">任意点</param>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			static Vector3 Rotate(Vector3 const& pos32, Vector3 const& axis, f32 angle);

			/// <summary>投影したベクトルを返す</summary>
			/// <param name="v">ベクトル</param>
			/// <param name="target">対象のベクトル</param>
			static Vector3 Projection(Vector3 const& v, Vector3 const& target);

			/// <summary>ベクトルのなす角を返す</summary>
			static f32 Angle(Vector3 const& v1, Vector3 const& v2);

			/// <summary>球面線形補間したベクトルを返す</summary>
			/// <param name="start">開始ベクトル</param>
			/// <param name="end">終了ベクトル</param>
			/// <param name="t">遷移率</param>
			static Vector3 Slerp(Vector3 const& start, Vector3 const& end, f32 t);

		public:

			union
			{
				f32 elm[3];

				f32 mat[1][3];

				struct
				{
					f32 r, g, b;
				};

				struct
				{
					f32 x, y, z;
				};
			};
		};

		bool operator == (Vector3 const& v1, Vector3 const& v2);

		bool operator != (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator + (Vector3 const& v);

		Vector3 operator - (Vector3 const& v);

		Vector3& operator += (Vector3& v1, Vector3 const& v2);

		Vector3& operator -= (Vector3& v1, Vector3 const& v2);

		Vector3& operator *= (Vector3& v1, Vector3 const& v2);

		Vector3& operator *= (Vector3& v, f32 s);

		Vector3& operator /= (Vector3& v1, Vector3 const& v2);

		Vector3& operator /= (Vector3& v, f32 s);

		Vector3 operator + (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator - (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator * (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator * (Vector3 const& v, f32 s);

		Vector3 operator * (f32 s, Vector3 const& v);

		Vector3 operator / (Vector3 const& v1, Vector3 const& v2);

		Vector3 operator / (Vector3 const& v, f32 s);
	}
}

# pragma warning (pop)
