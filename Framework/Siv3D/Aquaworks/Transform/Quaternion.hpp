# pragma once

# include "Vector4.hpp"
# include "Matrix.hpp"

namespace Aquaworks
{
	namespace Transform
	{
		// -------------------------------------------------------------------
		// 前置宣言
		// -------------------------------------------------------------------

		class Matrix;

		class Quaternion
		{
			// ---------------------------------------------------------------
			// システム
			// ---------------------------------------------------------------

		public:

			Quaternion();

			Quaternion(Quaternion const& q);

			Quaternion(f32 x, f32 y, f32 z, f32 w);

			// ---------------------------------------------------------------
			// 定数
			// ---------------------------------------------------------------

		public:

			/// <summary>単位クォータニオンを返す</summary>
			static Quaternion& Identity();

			// ---------------------------------------------------------------
			// 変換する
			// ---------------------------------------------------------------

		public:

			/// <summary>任意軸回転を行なう</summary>
			Quaternion& Rotate(Vector3 const& axis, f32 angle);

			/// <summary>ロール回転を行なう</summary>
			Quaternion& Roll(f32 angle);

			/// <summary>ピッチ回転を行なう</summary>
			Quaternion& Pitch(f32 angle);

			/// <summary>ヨー回転を行なう</summary>
			Quaternion& Yaw(f32 angle);

			/// <summary>行列に変換する</summary>
			Matrix ToMatrix();

			// ---------------------------------------------------------------
			// 変換クォータニオンを返す
			// ---------------------------------------------------------------

		public:

			/// <summary>任意軸回転クォータニオンを返す</summary>
			static Quaternion Rotation(Vector3 const& axis, f32 angle);

			/// <summary>行列に変換する</summary>
			static Matrix ToMatrix(Quaternion const& q);

			/// <summary>共役クォータニオンを返す</summary>
			static Quaternion Conjugate(Quaternion const& q);

		public:

			f32 x, y, z, w;
		};

		// ---------------------------------------------------------------
		// 演算子オーバーロード
		// ---------------------------------------------------------------

		Quaternion operator * (Quaternion const& q1, Quaternion const& q2);
		Quaternion& operator *= (Quaternion& q1, Quaternion const& q2);
		Vector3 operator * (Vector3 const& v, Quaternion const& q);
		Vector3& operator *= (Vector3 & v, Quaternion const& q);
	}
}
