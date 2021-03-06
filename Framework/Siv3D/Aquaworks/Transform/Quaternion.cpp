# include "Quaternion.hpp"

# include "Matrix.hpp"
# include "Vector3.hpp"
# include "Vector4.hpp"

# include "../Utility/Math.hpp"
# include "../Utility/MemoryCast.hpp"

namespace Aquaworks
{
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

		Quaternion::Quaternion(f32 x, f32 y, f32 z, f32 w)
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

		Quaternion& Quaternion::Rotate(Vector3 const& axis, f32 angle)
		{
			return *this *= Rotation(axis, angle);
		}

		Quaternion& Quaternion::Roll(f32 angle)
		{
			return *this *= Rotation(Vector3::Forward(), angle);
		}

		Quaternion& Quaternion::Pitch(f32 angle)
		{
			return *this *= Rotation(Vector3::Right(), angle);
		}

		Quaternion& Quaternion::Yaw(f32 angle)
		{
			return *this *= Rotation(Vector3::Up(), angle);
		}

		Matrix Quaternion::ToMatrix()
		{
			return ToMatrix(*this);
		}

		Quaternion Quaternion::Rotation(Vector3 const& axis, f32 angle)
		{
			f32 theta = angle / 2.0f;
			f32 sin = Math::Sin(theta);
			f32 cos = Math::Cos(theta);
			return Quaternion(
				axis.x * sin, axis.y * sin, axis.z * sin, cos);
		}

		Matrix Quaternion::ToMatrix(Quaternion const& q)
		{
			f32 x2 = 2 * q.x * q.x;
			f32 y2 = 2 * q.y * q.y;
			f32 z2 = 2 * q.z * q.z;
			f32 xy = 2 * q.x * q.y;
			f32 wz = 2 * q.w * q.z;
			f32 xz = 2 * q.x * q.z;
			f32 wy = 2 * q.w * q.y;
			f32 yz = 2 * q.y * q.z;
			f32 wx = 2 * q.w * q.x;

			return Matrix(
				1 - y2 - z2, xy + wz, xz - wy, 0,
				xy - wz, 1 - x2 - z2, yz + wx, 0,
				xz + wy, yz - wx, 1 - x2 - y2, 0,
				0, 0, 0, 1);
		}

		Quaternion Quaternion::Conjugate(Quaternion const& q)
		{
			return { -q.x, -q.y, -q.z, q.w };
		}

		Quaternion operator * (Quaternion const& q1, Quaternion const& q2)
		{
			Quaternion result;
			Vector3& v = memory_cast<Vector3>(result);
			f32& t = result.w;

			Vector3 v1 = memory_cast<Vector3>(q1);
			Vector3 v2 = memory_cast<Vector3>(q2);
			f32 t1 = q1.w;
			f32 t2 = q2.w;

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
			Quaternion result = Quaternion::Conjugate(q) * Quaternion(v.x, v.y, v.z, 0.0f) * q;
			return { result.x, result.y, result.z };
		}

		Vector3& operator *= (Vector3& v, Quaternion const& q)
		{
			return v = v * q;
		}
	}
}
