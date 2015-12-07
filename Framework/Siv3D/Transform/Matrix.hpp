# pragma once

# include "Vector4.hpp"
# include "Quaternion.hpp"

namespace Transform
{
	// -------------------------------------------------------------------
	// 前置宣言
	// -------------------------------------------------------------------
	class Vector3;
	class Quaternion;

	/// <summary>行列</summary>
	class Matrix
	{
	public:

		/// <summary>零行列を返す</summary>
		static Matrix const& zero();

		/// <summary>単位行列を返す</summary>
		static Matrix const& identity();

	public:

		/// <summary>コンストラクタ</summary>
		Matrix();

		/// <summary>配列から構築する</summary>
		explicit Matrix(float const* m);

		/// <summary>要素を指定して構築する</summary>
		Matrix(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

		/// <summary>代入演算子</summary>
		Matrix& operator = (Matrix const& m);

	public:

		/// <summary>配列に変換する</summary>
		operator float* ();

		/// <summary>配列に変換する</summary>
		operator float const* () const;

	public:

		/// <summary>単位行列かどうかを返す</summary>
		bool isIdentity() const;

		/// <summary>零行列かどうかを返す</summary>
		bool isZero() const;

		/// <summary>逆行列が作れるかを返す</summary>
		bool canInverse() const;

		/// <summary>逆行列かどうかを返す</summary>
		bool isInverse(Matrix const& matrix) const;

		/// <summary>行列式を返す</summary>
		float determinant() const;

		/// <summary>文字列に変換する</summary>
		std::wstring toString() const;

	public:

		/// <summary>平行移動する</summary>
		/// <param name="translation">平行移動量</param>
		Matrix& Translate(Vector3 const& translation);

		/// <summary>回転する</summary>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		Matrix& rotate(Vector3 const& axis, double angle);

		/// <summary>拡大縮小する</summary>
		/// <param name="scaling">拡大縮小率</param>
		Matrix& scale(Vector3 const& scaling);

		/// <summary>アフィン変換する</summary>
		/// <param name="translation">平行移動量</param>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		/// <param name="scaling">拡大縮小率</param>
		Matrix& transform(Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling);

		/// <summary>転置行列にする</summary>
		Matrix& transpose();

		/// <summary>逆行列にする</summary>
		Matrix& inverse();

	public:

		/// <summary>平行移動した行列を返す</summary>
		/// <param name="translation">平行移動量</param>
		Matrix translated(Vector3 const& translation) const;

		/// <summary>回転した行列を返す</summary>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		Matrix rotated(Vector3 const& axis, double angle) const;

		/// <summary>拡大縮小した行列を返す</summary>
		/// <param name="scaling">拡大縮小率</param>
		Matrix scaled(Vector3 const& scaling) const;

		/// <summary>アフィン変換した行列を返す</summary>
		/// <param name="translation">平行移動量</param>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		/// <param name="scaling">拡大縮小率</param>
		Matrix transformed(Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling) const;

		/// <summary>転置行列を返す</summary>
		Matrix transposed() const;

		/// <summary>逆行列を返す</summary>
		Matrix inversed() const;

		Quaternion ToQuaternion() const;

	public:

		Vector4 up() const;

		Vector4 right() const;

		Vector4 forward() const;

	public:

		/// <summary>単位行列かどうかを返す</summary>
		static bool IsIdentity(Matrix const& m);

		/// <summary>零行列かどうかを返す</summary>
		static bool IsZero(Matrix const& m);

		/// <summary>逆行列が作れるかを返す</summary>
		static bool CanInverse(Matrix const& m);

		/// <summary>逆行列かどうかを返す</summary>
		static bool IsInverse(Matrix const& m1, Matrix const& m2);

		/// <summary>行列式を返す</summary>
		static float Determinant(Matrix const& m);

		/// <summary>文字列に変換する</summary>
		static std::wstring ToString(Matrix const& m);

	public:

		/// <summary>平行移動行列を返す</summary>
		/// <param name="translation">平行移動量</param>
		static Matrix Translation(Vector3 const& translation);

		/// <summary>回転行列を返す</summary>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		static Matrix Rotation(Vector3 const& axis, double angle);

		/// <summary>拡大縮小行列を返す</summary>
		/// <param name="scaling">拡大縮小率</param>
		static Matrix Scaling(Vector3 const& scaling);

		/// <summary>アフィン変換行列を返す</summary>
		/// <param name="translation">平行移動量</param>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		/// <param name="scaling">拡大縮小率</param>
		static Matrix Transformation(Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling);

	public:

		/// <summary>平行移動する</summary>
		/// <param name="translation">平行移動量</param>
		static Matrix& Translate(Matrix& matrix, Vector3 const& translation);

		/// <summary>回転する</summary>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		static Matrix& Rotate(Matrix& matrix, Vector3 const& axis, double angle);

		/// <summary>拡大縮小する</summary>
		/// <param name="scaling">拡大縮小率</param>
		static Matrix& Scale(Matrix& matrix, Vector3 const& scaling);

		/// <summary>アフィン変換する</summary>
		/// <param name="translation">平行移動量</param>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		/// <param name="scaling">拡大縮小率</param>
		static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling);

		/// <summary>転置行列にする</summary>
		static Matrix& Transpose(Matrix& matrix);

		/// <summary>逆行列にする</summary>
		static Matrix& Inverse(Matrix& matrix);

	public:

		/// <summary>平行移動した行列を返す</summary>
		/// <param name="translation">平行移動量</param>
		static Matrix Translated(Matrix const& matrix, Vector3 const& translation);

		/// <summary>回転した行列を返す</summary>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		static Matrix Rotated(Matrix const& matrix, Vector3 const& axis, double angle);

		/// <summary>拡大縮小した行列を返す</summary>
		/// <param name="scaling">拡大縮小率</param>
		static Matrix Scaled(Matrix const& matrix, Vector3 const& scaling);

		/// <summary>アフィン変換した行列を返す</summary>
		/// <param name="translation">平行移動量</param>
		/// <param name="axis">回転軸</param>
		/// <param name="angle">回転量</param>
		/// <param name="scaling">拡大縮小率</param>
		static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Vector3 const& axis, double angle, Vector3 const& scaling);

		/// <summary>転置行列を返す</summary>
		static Matrix Transposed(Matrix const& matrix);

		/// <summary>逆行列を返す</summary>
		static Matrix Inversed(Matrix const& matrix);

	public:

		static Vector4 Up(Matrix const& matrix);

		static Vector4 Right(Matrix const& matrix);

		static Vector4 Forward(Matrix const& matrix);

		static Vector3 Translation(Matrix const& matrix);

		static Matrix Rotation(Matrix const& matrix);

		static Vector3 Scaling(Matrix const& matrix);

	public:

		static Matrix LookAt(Vector3 const& position, Vector3 const& target, Vector3 const& up);

		static Matrix Perspective(double fov, float aspect, float nearclip, float farclip);

		static Matrix Viewport(int width, int height);

		static Matrix Lerp(Matrix const& m1, Matrix const& m2, float t);

	public:

		union
		{
			float elm[16];

			float mat[4][4];

			struct
			{
				float m11, m12, m13, m14;
				float m21, m22, m23, m24;
				float m31, m32, m33, m34;
				float m41, m42, m43, m44;
			};
		};
	};

	bool operator == (Matrix const& m1, Matrix const& m2);

	bool operator != (Matrix const& m1, Matrix const& m2);

	Matrix operator * (Matrix const& m1, Matrix const& m2);

	Vector3 operator * (Vector3 const& v, Matrix const& m);

	Vector4 operator * (Vector4 const& v, Matrix const& m);

	Matrix& operator *= (Matrix& m1, Matrix const& m2);

	Vector3& operator *= (Vector3& v, Matrix const& m);

	Vector4& operator *= (Vector4& v, Matrix const& m);
}
