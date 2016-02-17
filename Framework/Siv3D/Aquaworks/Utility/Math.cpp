# include "Math.hpp"
# include "MemoryCast.hpp"

# include "../Transform/Quaternion.hpp"
# include "../Transform/Matrix.hpp"
# include "../Transform/Pose.hpp"

# include <cmath>

namespace Aquaworks
{
	namespace Utility
	{
		namespace Math
		{
			float ToRadian(float x)
			{
				return x * Radian;
			}

			float ToDegree(float x)
			{
				return x * Degree;
			}

			float Sin(float x)
			{
				return std::sin(x);
			}

			float Cos(float x)
			{
				return std::cos(x);
			}

			float Tan(float x)
			{
				return std::tan(x);
			}

			float Asin(float x)
			{
				return std::asin(x);
			}

			float Acos(float x)
			{
				return std::acos(x);
			}

			float Atan(float x)
			{
				return std::atan(x);
			}

			float Atan2(float y, float x)
			{
				return std::atan2(y, x);
			}

			float Floor(float x)
			{
				return std::floor(x);
			}

			float Ceiling(float x)
			{
				return std::ceil(x);
			}

			float Round(float x)
			{
				return std::round(x);
			}

			float Sign(float x)
			{
				return std::signbit(x) ? 1.0f : -1.0f;
			}

			float Pow(float x, float y)
			{
				return std::pow(x, y);
			}

			float Sqrt(float x)
			{
				return std::sqrt(x);
			}

			float Smooth(float x, int y)
			{
				float f = Math::Pow(10.0, -static_cast<float>(y));
				int i = (int)(x * f);
				return i / f;
			}

			float Saturate(float x)
			{
				return Clamp(x, 0.0f, 1.0f);
			}

			float Clamp(float x, float y, float z)
			{
				return Math::Min({ Math::Max({ x, y }), z });
			}

			template <>
			Transform::Quaternion Lerp(Transform::Quaternion const& begin, Transform::Quaternion const& end, float t)
			{
				Transform::Vector4 a =
					memory_cast<Transform::Vector4>(begin);

				Transform::Vector4 b =
					memory_cast<Transform::Vector4>(end);

				float omega = Math::Acos(Transform::Vector4::Dot(a, b));

				if (omega == 0.0f)
				{
					return begin;
				}

				float sin = Math::Sin(omega);
				
				Transform::Vector4 result =
					Math::Sin((1 - t) * omega) / sin * a +
					Math::Sin(t * omega) / sin * b;

				return memory_cast<Transform::Quaternion>(result);
			}

			template <>
			Transform::Matrix Lerp(Transform::Matrix const& begin, Transform::Matrix const& end, float t)
			{
				Transform::Pose a = Transform::Matrix::Decompose(begin);
				Transform::Pose b = Transform::Matrix::Decompose(end);

				Transform::Vector3 translate = Lerp(a.position, b.position, t);
				Transform::Quaternion rotate = Lerp(a.rotation, b.rotation, t);
				Transform::Vector3 scale = Lerp(a.scaling, b.scaling, t);

				return Transform::Matrix::Transformation(translate, rotate, scale);
			}
		}
	}
}
