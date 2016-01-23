# pragma once

# pragma warning (push)
# pragma warning (disable : 4201)

# include "Vector4.hpp"

namespace Transform
{
	// -------------------------------------------------------------------
	// ‘O’uéŒ¾
	// -------------------------------------------------------------------
	class Vector3;
	class Quaternion;
	class Pose;

	/// <summary>s—ñ</summary>
	class Matrix
	{
	public:

		/// <summary>—ës—ñ‚ğ•Ô‚·</summary>
		static Matrix const& Zero();

		/// <summary>’PˆÊs—ñ‚ğ•Ô‚·</summary>
		static Matrix const& Identity();

	public:

		/// <summary>ƒRƒ“ƒXƒgƒ‰ƒNƒ^</summary>
		Matrix();

		/// <summary>”z—ñ‚©‚ç\’z‚·‚é</summary>
		explicit Matrix(float const* m);

		/// <summary>—v‘f‚ğw’è‚µ‚Ä\’z‚·‚é</summary>
		Matrix(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

		/// <summary>‘ã“ü‰‰Zq</summary>
		Matrix& operator = (Matrix const& m);

	public:

		/// <summary>”z—ñ‚É•ÏŠ·‚·‚é</summary>
		operator float* ();

		/// <summary>”z—ñ‚É•ÏŠ·‚·‚é</summary>
		operator float const* () const;

	public:

		/// <summary>’PˆÊs—ñ‚©‚Ç‚¤‚©‚ğ•Ô‚·</summary>
		static bool IsIdentity(Matrix const& m);

		/// <summary>—ës—ñ‚©‚Ç‚¤‚©‚ğ•Ô‚·</summary>
		static bool IsZero(Matrix const& m);

		/// <summary>‹ts—ñ‚ªì‚ê‚é‚©‚ğ•Ô‚·</summary>
		static bool CanInverse(Matrix const& m);

		/// <summary>‹ts—ñ‚©‚Ç‚¤‚©‚ğ•Ô‚·</summary>
		static bool IsInverse(Matrix const& m1, Matrix const& m2);

		/// <summary>s—ñ®‚ğ•Ô‚·</summary>
		static float Determinant(Matrix const& m);

	public:

		/// <summary>•½sˆÚ“®s—ñ‚ğ•Ô‚·</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		static Matrix Translation(Vector3 const& translation);

		/// <summary>‰ñ“]s—ñ‚ğ•Ô‚·</summary>
		/// <param name="axis">‰ñ“]²</param>
		/// <param name="angle">‰ñ“]—Ê</param>
		static Matrix Rotation(Vector3 const& axis, float angle);

		/// <summary>‰ñ“]s—ñ‚ğ•Ô‚·</summary>
		/// <param name="rotation">‰ñ“]</param>
		static Matrix Rotation(Quaternion const& rotation);

		/// <summary>Šg‘åk¬s—ñ‚ğ•Ô‚·</summary>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix Scaling(Vector3 const& scaling);

		/// <summary>ƒAƒtƒBƒ“•ÏŠ·s—ñ‚ğ•Ô‚·</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		/// <param name="axis">‰ñ“]²</param>
		/// <param name="angle">‰ñ“]—Ê</param>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix Transformation(Vector3 const& translation, Vector3 const& axis, float angle, Vector3 const& scaling);

		/// <summary>ƒAƒtƒBƒ“•ÏŠ·s—ñ‚ğ•Ô‚·</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		/// <param name="rotation">‰ñ“]</param>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix Transformation(Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

	public:

		/// <summary>•½sˆÚ“®‚·‚é</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		static Matrix& Translate(Matrix& matrix, Vector3 const& translation);

		/// <summary>‰ñ“]‚·‚é</summary>
		/// <param name="axis">‰ñ“]²</param>
		/// <param name="angle">‰ñ“]—Ê</param>
		static Matrix& Rotate(Matrix& matrix, Vector3 const& axis, float angle);

		/// <summary>‰ñ“]‚·‚é</summary>
		/// <param name="rotation">‰ñ“]</param>
		static Matrix& Rotate(Matrix& matrix, Quaternion const& rotation);

		/// <summary>Šg‘åk¬‚·‚é</summary>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix& Scale(Matrix& matrix, Vector3 const& scaling);

		/// <summary>ƒAƒtƒBƒ“•ÏŠ·‚·‚é</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		/// <param name="axis">‰ñ“]²</param>
		/// <param name="angle">‰ñ“]—Ê</param>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Vector3 const& axis, float angle, Vector3 const& scaling);

		/// <summary>ƒAƒtƒBƒ“•ÏŠ·‚·‚é</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		/// <param name="rotation">‰ñ“]</param>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix& Transform(Matrix& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

		/// <summary>“]’us—ñ‚É‚·‚é</summary>
		static Matrix& Transpose(Matrix& matrix);

		/// <summary>‹ts—ñ‚É‚·‚é</summary>
		static Matrix& Inverse(Matrix& matrix);

		/// <summary>ƒNƒH[ƒ^ƒjƒIƒ“‚É•ÏŠ·‚·‚é</summary>
		static Quaternion ToQuaternion(Matrix const& matrix);

	public:

		/// <summary>•½sˆÚ“®‚µ‚½s—ñ‚ğ•Ô‚·</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		static Matrix Translated(Matrix const& matrix, Vector3 const& translation);

		/// <summary>‰ñ“]‚µ‚½s—ñ‚ğ•Ô‚·</summary>
		/// <param name="axis">‰ñ“]²</param>
		/// <param name="angle">‰ñ“]—Ê</param>
		static Matrix Rotated(Matrix const& matrix, Vector3 const& axis, float angle);

		/// <summary>‰ñ“]‚µ‚½s—ñ‚ğ•Ô‚·</summary>
		/// <param name="rotation">‰ñ“]</param>
		static Matrix Rotated(Matrix const& matrix, Quaternion const& rotation);

		/// <summary>Šg‘åk¬‚µ‚½s—ñ‚ğ•Ô‚·</summary>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix Scaled(Matrix const& matrix, Vector3 const& scaling);

		/// <summary>ƒAƒtƒBƒ“•ÏŠ·‚µ‚½s—ñ‚ğ•Ô‚·</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		/// <param name="axis">‰ñ“]²</param>
		/// <param name="angle">‰ñ“]—Ê</param>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Vector3 const& axis, float angle, Vector3 const& scaling);

		/// <summary>ƒAƒtƒBƒ“•ÏŠ·‚µ‚½s—ñ‚ğ•Ô‚·</summary>
		/// <param name="translation">•½sˆÚ“®—Ê</param>
		/// <param name="rotation">‰ñ“]</param>
		/// <param name="scaling">Šg‘åk¬—¦</param>
		static Matrix Transformed(Matrix const& matrix, Vector3 const& translation, Quaternion const& rotation, Vector3 const& scaling);

		/// <summary>“]’us—ñ‚ğ•Ô‚·</summary>
		static Matrix Transposed(Matrix const& matrix);

		/// <summary>‹ts—ñ‚ğ•Ô‚·</summary>
		static Matrix Inversed(Matrix const& matrix);

	public:

		static Vector4 Up(Matrix const& matrix);

		static Vector4 Right(Matrix const& matrix);

		static Vector4 Forward(Matrix const& matrix);

		static Vector3 Translation(Matrix const& matrix);

		static Quaternion Rotation(Matrix const& matrix);

		static Vector3 Scaling(Matrix const& matrix);

		static Pose Decompose(Matrix const& matrix);

	public:

		static Matrix LookAt(Vector3 const& position, Vector3 const& target, Vector3 const& up);

		static Matrix Perspective(float fov, float aspect, float nearclip, float farclip);

		static Matrix Viewport(int width, int height);

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

# pragma warning (pop)
