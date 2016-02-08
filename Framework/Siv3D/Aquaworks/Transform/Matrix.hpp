# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include "Vector4.hpp"

namespace Aquaworks
{
	namespace Transform
	{
		// -------------------------------------------------------------------
		// 前置宣言
		// -------------------------------------------------------------------

		class Vector3;
		class Quaternion;
		class Pose;

		/// <summary>行列</summary>
		class Matrix
		{
			// ---------------------------------------------------------------
			// 定数
			// ---------------------------------------------------------------

		public:

			/// <summary>零行列を返す</summary>
			static Matrix const& Zero();

			/// <summary>単位行列を返す</summary>
			static Matrix const& Identity();

			// ---------------------------------------------------------------
			// システム
			// ---------------------------------------------------------------

		public:

			/// <summary>コンストラクタ</summary>
			Matrix();

			/// <summary>配列から構築する</summary>
			explicit Matrix(f32 const* m);

			/// <summary>要素を指定して構築する</summary>
			Matrix(
				f32 m11, f32 m12, f32 m13, f32 m14,
				f32 m21, f32 m22, f32 m23, f32 m24,
				f32 m31, f32 m32, f32 m33, f32 m34,
				f32 m41, f32 m42, f32 m43, f32 m44);

			/// <summary>代入演算子</summary>
			Matrix& operator = (Matrix const& m);

			// ---------------------------------------------------------------
			// 状態を返す
			// ---------------------------------------------------------------

		public:

			/// <summary>単位行列かどうかを返す</summary>
			static bool IsIdentity(Matrix const& m);

			/// <summary>零行列かどうかを返す</summary>
			static bool IsZero(Matrix const& m);

			/// <summary>逆行列が作れるかを返す</summary>
			static bool CanInverse(Matrix const& m);

			/// <summary>逆行列かどうかを返す</summary>
			static bool IsInverse(Matrix const& m1, Matrix const& m2);

			// ---------------------------------------------------------------
			// 変換行列を返す
			// ---------------------------------------------------------------

		public:

			/// <summary>平行移動行列を返す</summary>
			/// <param name="translation">平行移動量</param>
			static Matrix Translation(Vector3 const& translation);

			/// <summary>回転行列を返す</summary>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			static Matrix Rotation(Vector3 const& axis, f32 angle);

			/// <summary>回転行列を返す</summary>
			/// <param name="rotation">回転</param>
			static Matrix Rotation(Quaternion const& rotation);

			/// <summary>拡大縮小行列を返す</summary>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix Scaling(Vector3 const& scaling);

			/// <summary>アフィン変換行列を返す</summary>
			/// <param name="translation">平行移動量</param>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix Transformation(Vector3 const& translation, Vector3 const& axis, f32 angle, Vector3 const& scaling);

			/// <summary>アフィン変換行列を返す</summary>
			/// <param name="translation">平行移動量</param>
			/// <param name="rotation">回転</param>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix Transformation(Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

			// ---------------------------------------------------------------
			// 変換する
			// ---------------------------------------------------------------

		public:

			/// <summary>平行移動する</summary>
			/// <param name="translation">平行移動量</param>
			static Matrix& Translate(Matrix& matrix, Vector3 const& translation);

			/// <summary>回転する</summary>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			static Matrix& Rotate(Matrix& matrix, Vector3 const& axis, f32 angle);

			/// <summary>回転する</summary>
			/// <param name="rotation">回転</param>
			static Matrix& Rotate(Matrix& matrix, Quaternion const& rotation);

			/// <summary>拡大縮小する</summary>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix& Scale(Matrix& matrix, Vector3 const& scaling);

			/// <summary>アフィン変換する</summary>
			/// <param name="translation">平行移動量</param>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Vector3 const& axis, f32 angle, Vector3 const& scaling);

			/// <summary>アフィン変換する</summary>
			/// <param name="translation">平行移動量</param>
			/// <param name="rotation">回転</param>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

			/// <summary>転置行列にする</summary>
			static Matrix& Transpose(Matrix& matrix);

			/// <summary>逆行列にする</summary>
			static Matrix& Inverse(Matrix& matrix);

			// ---------------------------------------------------------------
			// 変換済み行列を返す
			// ---------------------------------------------------------------

		public:

			/// <summary>平行移動した行列を返す</summary>
			/// <param name="translation">平行移動量</param>
			static Matrix Translated(Matrix const& matrix, Vector3 const& translation);

			/// <summary>回転した行列を返す</summary>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			static Matrix Rotated(Matrix const& matrix, Vector3 const& axis, f32 angle);

			/// <summary>回転した行列を返す</summary>
			/// <param name="rotation">回転</param>
			static Matrix Rotated(Matrix const& matrix, Quaternion const& rotation);

			/// <summary>拡大縮小した行列を返す</summary>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix Scaled(Matrix const& matrix, Vector3 const& scaling);

			/// <summary>アフィン変換した行列を返す</summary>
			/// <param name="translation">平行移動量</param>
			/// <param name="axis">回転軸</param>
			/// <param name="angle">回転量</param>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Vector3 const& axis, f32 angle, Vector3 const& scaling);

			/// <summary>アフィン変換した行列を返す</summary>
			/// <param name="translation">平行移動量</param>
			/// <param name="rotation">回転</param>
			/// <param name="scaling">拡大縮小率</param>
			static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

			/// <summary>転置行列を返す</summary>
			static Matrix Transposed(Matrix const& matrix);

			/// <summary>逆行列を返す</summary>
			static Matrix Inversed(Matrix const& matrix);

			// ---------------------------------------------------------------
			// パラメータ取得
			// ---------------------------------------------------------------

		public:

			/// <summary>上方向ベクトルを返す</summary>
			static Vector4 Up(Matrix const& matrix);

			/// <summary>右方向ベクトルを返す</summary>
			static Vector4 Right(Matrix const& matrix);

			/// <summary>前方向ベクトルを返す</summary>
			static Vector4 Forward(Matrix const& matrix);

			/// <summary>平行移動成分を返す</summary>
			static Vector3 Translation(Matrix const& matrix);

			/// <summary>回転成分を返す</summary>
			static Quaternion Rotation(Matrix const& matrix);

			/// <summary>拡大縮小成分を返す</summary>
			static Vector3 Scaling(Matrix const& matrix);

			/// <summary>成分分解する</summary>
			static Pose Decompose(Matrix const& matrix);

			/// <summary>行列式を返す</summary>
			static f32 Determinant(Matrix const& m);

			/// <summary>クォータニオンに変換する</summary>
			static Quaternion ToQuaternion(Matrix const& matrix);

			// ---------------------------------------------------------------
			// 特殊な行列生成
			// ---------------------------------------------------------------

		public:

			/// <summary>ビュー行列を返す</summary>
			static Matrix LookAt(Vector3 const& position, Vector3 const& target, Vector3 const& up);

			/// <summary>透視射影行列を返す</summary>
			static Matrix Perspective(f32 fov, f32 aspect, f32 nearclip, f32 farclip);

			/// <summary>ビューポート行列を返す</summary>
			static Matrix Viewport(s32 width, s32 height);

		public:

			union
			{
				f32 elm[16];

				f32 mat[4][4];

				struct
				{
					f32 m11, m12, m13, m14;
					f32 m21, m22, m23, m24;
					f32 m31, m32, m33, m34;
					f32 m41, m42, m43, m44;
				};
			};
		};

		// ---------------------------------------------------------------
		// 演算子オーバーロード
		// ---------------------------------------------------------------

		bool operator == (Matrix const& m1, Matrix const& m2);
		bool operator != (Matrix const& m1, Matrix const& m2);
		Matrix operator * (Matrix const& m1, Matrix const& m2);
		Vector3 operator * (Vector3 const& v, Matrix const& m);
		Vector4 operator * (Vector4 const& v, Matrix const& m);
		Matrix& operator *= (Matrix& m1, Matrix const& m2);
		Vector3& operator *= (Vector3& v, Matrix const& m);
		Vector4& operator *= (Vector4& v, Matrix const& m);
	}
}

# pragma warning (pop)
