# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include <string>

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
		Vector4(float x, float y, float z, float w);

		/// <summary>三次元ベクトルとw要素を指定して構築する</summary>
		Vector4(Vector3 const& v, float w);

		/// <summary>四次元点から構築する</summary>
		explicit Vector4(Point4 const& v);

		/// <summary>代入演算子</summary>
		Vector4& operator = (Vector4 const& v);

	public:

		/// <summary>配列に変換する</summary>
		operator float* ();

		/// <summary>配列に変換する</summary>
		operator float const* () const;

	public:

		/// <summary>内積を返す</summary>
		static float Dot(Vector4 const& v1, Vector4 const& v2);

		/// <summary>長さの二乗を返す</summary>
		/// <param name="v">ベクトル</param>
		static float LengthSquared(Vector4 const& v);

		/// <summary>長さを返す</summary>
		/// <param name="v">ベクトル</param>
		static float Length(Vector4 const& v);

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
			float elm[4];

			float mat[1][4];

			struct
			{
				float r, g, b, a;
			};

			struct
			{
				float x, y, z, w;
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

	Vector4& operator *= (Vector4& v, float s);

	Vector4& operator /= (Vector4& v1, Vector4 const& v2);

	Vector4& operator /= (Vector4& v, float s);

	Vector4 operator + (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator - (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator * (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator * (Vector4 const& v, float s);

	Vector4 operator * (float s, Vector4 const& v);

	Vector4 operator / (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator / (Vector4 const& v, float s);
}

# pragma warning (pop)
