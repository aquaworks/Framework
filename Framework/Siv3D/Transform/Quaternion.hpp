# pragma once

# include "Vector4.hpp"
# include "Matrix.hpp"

namespace Transform
{
	class Matrix;

	class Quaternion
	{
	public:

		Quaternion();

		Quaternion(Quaternion const& q);

		Quaternion(float x, float y, float z, float w);

	public:

		static Quaternion& Identity();

	public:

		Quaternion& Rotate(Vector3 const& axis, float angle);

		Quaternion& Roll(float angle);

		Quaternion& Pitch(float angle);

		Quaternion& Yaw(float angle);

		Matrix ToMatrix();

	public:

		static Quaternion Rotation(Vector3 const& axis, float angle);

		static Matrix ToMatrix(Quaternion const& q);

		static Quaternion Conjugate(Quaternion const& q);

	public:

		float x, y, z, w;
	};

	Quaternion operator * (Quaternion const& q1, Quaternion const& q2);
	Quaternion& operator *= (Quaternion& q1, Quaternion const& q2);

	Vector3 operator * (Vector3 const& v, Quaternion const& q);
	Vector3& operator *= (Vector3 & v, Quaternion const& q);
}
