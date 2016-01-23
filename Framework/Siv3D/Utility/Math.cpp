# include "Math.hpp"

# include <cmath>

namespace Utility
{
	namespace Math
	{
		float ToRadian(float x)
		{
			return x * RADIAN;
		}

		float ToDegree(float x)
		{
			return x * DEGREE;
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
	}
}
