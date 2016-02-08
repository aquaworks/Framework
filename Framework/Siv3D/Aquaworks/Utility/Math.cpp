# include "Math.hpp"

# include <cmath>

namespace Aquaworks
{
	namespace Utility
	{
		namespace Math
		{
			f32 ToRadian(f32 x)
			{
				return x * Radian;
			}

			f32 ToDegree(f32 x)
			{
				return x * Degree;
			}

			f32 Sin(f32 x)
			{
				return std::sin(x);
			}

			f32 Cos(f32 x)
			{
				return std::cos(x);
			}

			f32 Tan(f32 x)
			{
				return std::tan(x);
			}

			f32 Asin(f32 x)
			{
				return std::asin(x);
			}

			f32 Acos(f32 x)
			{
				return std::acos(x);
			}

			f32 Atan(f32 x)
			{
				return std::atan(x);
			}

			f32 Atan2(f32 y, f32 x)
			{
				return std::atan2(y, x);
			}

			f32 Floor(f32 x)
			{
				return std::floor(x);
			}

			f32 Ceiling(f32 x)
			{
				return std::ceil(x);
			}

			f32 Round(f32 x)
			{
				return std::round(x);
			}

			f32 Sign(f32 x)
			{
				return std::signbit(x) ? 1.0f : -1.0f;
			}

			f32 Pow(f32 x, f32 y)
			{
				return std::pow(x, y);
			}

			f32 Sqrt(f32 x)
			{
				return std::sqrt(x);
			}

			f32 Smooth(f32 x, int y)
			{
				f32 f = Math::Pow(10.0, -static_cast<f32>(y));
				int i = (int)(x * f);
				return i / f;
			}

			f32 Saturate(f32 x)
			{
				return Clamp(x, 0.0f, 1.0f);
			}

			f32 Clamp(f32 x, f32 y, f32 z)
			{
				return Math::Min({ Math::Max({ x, y }), z });
			}
		}
	}
}
