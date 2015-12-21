# include "Quaternion.hpp"

# include "Matrix.hpp"
# include "Vector3.hpp"
# include "Vector4.hpp"

# include "Utility/Math.hpp"
# include "Utility/String.hpp"
# include "Utility/MemoryCast.hpp"

namespace Transform
{
	using namespace Utility;

	Quaternion::Quaternion()
		: x(0.0f)
		, y(0.0f)
		, z(0.0f)
		, w(1.0f)
	{

	}

	Quaternion::Quaternion(Quaternion const& q)
		: x(q.x)
		, y(q.y)
		, z(q.z)
		, w(q.w)
	{

	}

	Quaternion::Quaternion(float x, float y, float z, float w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{

	}

	Quaternion& Quaternion::Identity()
	{
		static Quaternion identity { 0.0f, 0.0f, 0.0f, 1.0f };
		return identity;
	}

	Quaternion& Quaternion::Rotate(Vector3 const& axis, double angle)
	{
		return *this *= Rotation(axis, angle);
	}

	Quaternion& Quaternion::Roll(double angle)
	{
		return *this *= Rotation(Vector3::Forward(), angle);
	}

	Quaternion& Quaternion::Pitch(double angle)
	{
		return *this *= Rotation(Vector3::Right(), angle);
	}

	Quaternion& Quaternion::Yaw(double angle)
	{
		return *this *= Rotation(Vector3::Up(), angle);
	}

	Matrix Quaternion::ToMatrix()
	{
		return ToMatrix(*this);
	}

	Quaternion Quaternion::Rotation(Vector3 const& axis, double angle)
	{
		double theta = angle / 2.0;
		float sin = (float)Math::Sin(theta);
		float cos = (float)Math::Cos(theta);
		return Quaternion(
			axis.x * sin, axis.y * sin, axis.z * sin, cos);
	}
	std::wstring Quaternion::ToString(Quaternion const& q)
	{
		return Vector4::ToString(*MemoryCast<Vector4>(&q.x));
	}
	Matrix Quaternion::ToMatrix(Quaternion const& q)
	{
		float x2 = 2 * q.x * q.x;
		float y2 = 2 * q.y * q.y;
		float z2 = 2 * q.z * q.z;
		float xy = 2 * q.x * q.y;
		float wz = 2 * q.w * q.z;
		float xz = 2 * q.x * q.z;
		float wy = 2 * q.w * q.y;
		float yz = 2 * q.y * q.z;
		float wx = 2 * q.w * q.x;

		return Matrix(
			1 - y2 - z2, xy + wz, xz - wy, 0,
			xy - wz, 1 - x2 - z2, yz + wx, 0,
			xz + wy, yz - wx, 1 - x2 - y2, 0,
			0, 0, 0, 1);
	}

	Quaternion operator * (Quaternion const& q1, Quaternion const& q2)
	{
		Quaternion result;
		Vector3& v = *MemoryCast<Vector3>(&result.x);
		float& t = result.w;

		Vector3 v1 = *MemoryCast<Vector3>(&q1.x);
		Vector3 v2 = *MemoryCast<Vector3>(&q2.x);
		float t1 = q1.w;
		float t2 = q2.w;

		v = v2 * t1 + v1 * t2 + Vector3::Cross(v1, v2);
		t = t1 * t2 - Vector3::Dot(v1, v2);

		return result;
	}

	Quaternion& operator *= (Quaternion& q1, Quaternion const& q2)
	{
		return q1 = q1 * q2;
	}

	Vector3 operator * (Vector3 const& v, Quaternion const& q)
	{
		Quaternion result = -q * Quaternion(v.x, v.y, v.z, 0.0f) * q;
		return { result.x, result.y, result.z };
	}

	Vector3& operator *= (Vector3& v, Quaternion const& q)
	{
		return v = v * q;
	}

	Quaternion operator - (Quaternion const& q)
	{
		return { -q.x, -q.y, -q.z, -q.w };
	}
}
