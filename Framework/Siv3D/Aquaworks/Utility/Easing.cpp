# include "Easing.hpp"

# include "Math.hpp"

namespace Aquaworks
{
	namespace Utility
	{
		f32 Quad(f32 t)
		{
			return t * t;
		}

		f32 Cubic(f32 t)
		{
			return t * t * t;
		}

		f32 Quart(f32 t)
		{
			return t * t * t * t;
		}

		f32 Quint(f32 t)
		{
			return t * t * t * t * t;
		}

		f32 Sine(f32 t)
		{
			return 1.0f - Math::Cos(Math::Div2Pi * t);
		}

		f32 Exp(f32 t)
		{
			return t == 0.0f ?
				0.0f :
				Math::Pow(2.0f, 10.0f * (t - 1.0f));
		}

		f32 Circ(f32 t)
		{
			t -= 1.0f;
			return 1.0f - Math::Sqrt(1.0f - t * t);
		}

		f32 Back(f32 t)
		{
			return t * t * (2.70158f * t - 1.70158f);
		}

		f32 Bounce(f32 t)
		{
			if (t < 1.0f / 2.75f)
			{
				return 7.5625f * t * t;
			}
			if (t < 2.0f / 2.75f)
			{
				t -= 1.5f / 2.75f;
				return 7.5625f * t * t + 0.75f;
			}
			if (t < 2.5f / 2.75f)
			{
				t -= 2.25f / 2.75f;
				return 7.5625f * t * t + 0.9375f;
			}
			t -= 2.625f / 2.75f;
			return 7.5625f * t * t + 0.984375f;
		}

		f32 Elastic(f32 t)
		{
			if (t == 0.0f)
			{
				return 0.0f;
			}

			if (t == 1.0f)
			{
				return 1.0f;
			}

			f32 s = 0.04774648292756859813f * Math::Asin(1.0f);

			t -= 1.0f;
			return -Math::Pow(2.0f, 10.0f * t) * Math::Sin((t - s) *
				20.94395102393195529f);
		}

		f32 Linear(f32 t)
		{
			return t;
		}
	}
}
