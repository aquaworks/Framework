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

		Quaternion& Rotate(Vector3 const& axis, double angle);

		Quaternion& Roll(double angle);

		Quaternion& Pitch(double angle);

		Quaternion& Yaw(double angle);

		Matrix ToMatrix();

	public:

		static Quaternion Rotation(Vector3 const& axis, double angle);

		static std::wstring ToString(Quaternion const& q);

		static Matrix ToMatrix(Quaternion const& q);

	public:

		float x, y, z, w;
	};

	Quaternion operator * (Quaternion const& q1, Quaternion const& q2);
	Quaternion& operator *= (Quaternion& q1, Quaternion const& q2);
}
