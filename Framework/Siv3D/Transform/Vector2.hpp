# pragma once

# include <string>

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
		Vector2(float x, float y);

		/// <summary>三次元ベクトルから構築する</summary>
		explicit Vector2(Vector3 const& v);

		/// <summary>二次元点から構築する</summary>
		explicit Vector2(Point2 const& v);

		/// <summary>代入演算子</summary>
		Vector2& operator = (Vector2 const& v);

	public:

		/// <summary>配列に変換する</summary>
		operator float* ();

		/// <summary>配列に変換する</summary>
		operator float const* () const;

	public:

		/// <summary>文字列に変換して返す</summary>
		std::wstring toString() const;

		/// <summary>内積を返す</summary>
		/// <param name="v">ベクトル</param>
		float dot(Vector2 const& v) const;

		/// <summary>外積を返す</summary>
		/// <param name="v">ベクトル</param>
		float cross(Vector2 const& v) const;

		/// <summary>長さの二乗を返す</summary>
		/// <param name="v">ベクトル</param>
		float lengthSquared() const;

		/// <summary>長さを返す</summary>
		/// <param name="v">ベクトル</param>
		float length() const;

		/// <summary>正規化する</summary>
		Vector2& normalize();

		/// <summary>任意軸で回転する</summary>
		/// <param name="origin">中心点</param>
		/// <param name="angle">回転量</param>
		Vector2& rotate(Vector2 const& origin, double angle);

		/// <summary>ベクトルに射影する</summary>
		/// <param name="v">対象のベクトル</param>
		Vector2& projection(Vector2 const& v);

		/// <summary>ベクトルのなす角を返す</summary>
		float angle(Vector2 const& v) const;

	public:

		/// <summary>文字列に変換して返す</summary>
		/// <param name="v">ベクトル</param>
		static std::wstring ToString(Vector2 const& v);

		/// <summary>内積を返す</summary>
		/// <param name="v1">ベクトル</param>
		/// <param name="v2">ベクトル</param>
		static float Dot(Vector2 const& v1, Vector2 const& v2);

		/// <summary>外積を返す</summary>
		static float Cross(Vector2 const& v1, Vector2 const& v2);

		/// <summary>長さの二乗を返す</summary>
		/// <param name="v">ベクトル</param>
		static float LengthSquared(Vector2 const& v);

		/// <summary>長さを返す</summary>
		/// <param name="v">ベクトル</param>
		static float Length(Vector2 const& v);

		/// <summary>正規化したベクトルを返す</summary>
		/// <param name="v">ベクトル</param>
		static Vector2 Nornalize(Vector2 const& v);

		/// <summary>任意軸で回転したベクトル返す</summary>
		/// <param name="point">任意点</param>
		/// <param name="origin">中心点</param>
		/// <param name="angle">回転量</param>
		static Vector2 Rotate(Vector2 const& point, Vector2 const& origin, double angle);

		/// <summary>投影したベクトルを返す</summary>
		/// <param name="v">ベクトル</param>
		/// <param name="target">対象のベクトル</param>
		static Vector2 Projection(Vector2 const& v, Vector2 const& target);

		/// <summary>線形補間したベクトルを返す</summary>
		/// <param name="start">開始ベクトル</param>
		/// <param name="end">終了ベクトル</param>
		/// <param name="t">遷移率</param>
		static Vector2 Lerp(Vector2 const& start, Vector2 const& end, float t);

		/// <summary>ベクトルのなす角を返す</summary>
		static float Angle(Vector2 const& v1, Vector2 const& v2);

	public:

		union
		{
			float elm[2];

			float mat[1][2];

			struct
			{
				float u, v;
			};

			struct
			{
				float x, y;
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

	Vector2& operator *= (Vector2& v, float s);

	Vector2& operator /= (Vector2& v1, Vector2 const& v2);

	Vector2& operator /= (Vector2& v, float s);

	Vector2 operator + (Vector2 const& v1, Vector2 const& v2);

	Vector2 operator - (Vector2 const& v1, Vector2 const& v2);

	Vector2 operator * (Vector2 const& v1, Vector2 const& v2);

	Vector2 operator * (Vector2 const& v, float s);

	Vector2 operator * (float s, Vector2 const& v);

	Vector2 operator / (Vector2 const& v1, Vector2 const& v2);

	Vector2 operator / (Vector2 const& v, float s);
}
