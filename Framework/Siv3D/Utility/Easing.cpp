# include "Easing.hpp"

# include "Math.hpp"

namespace Utility
{
	double Quad(double t)
	{
		return t * t;
	}

	double Cubic(double t)
	{
		return t * t * t;
	}

	double Quart(double t)
	{
		return t * t * t * t;
	}

	double Quint(double t)
	{
		return t * t * t * t * t;
	}

	double Sine(double t)
	{
		return 1.0 - Math::Cos(Math::HALF_PI * t);
	}

	double Exp(double t)
	{
		return t == 0.0 ?
			0.0 :
			Math::Pow(2.0, 10.0 * (t - 1.0));
	}

	double Circ(double t)
	{
		t -= 1;
		return 1.0 - Math::Sqrt(1 - t * t);
	}

	double Back(double t)
	{
		return t * t * (2.70158 * t - 1.70158);
	}

	double Bounce(double t)
	{
		if (t < 1 / 2.75)
		{
			return 7.5625 * t * t;
		}
		if (t < 2 / 2.75)
		{
			t -= 1.5 / 2.75;
			return 7.5625 * t * t + 0.75;
		}
		if (t < 2.5 / 2.75)
		{
			t -= 2.25 / 2.75;
			return 7.5625 * t * t + 0.9375;
		}
		t -= 2.625 / 2.75;
		return 7.5625 * t * t + 0.984375;
	}

	double Elastic(double t)
	{
		if (t == 0.0)
		{
			return 0.0;
		}

		if (t == 1.0)
		{
			return 1.0;
		}

		double s = 0.04774648292756859813 * Math::Asin(1.0);

		t -= 1.0;
		return -Math::Pow(2.0, 10.0 * t) * Math::Sin((t - s) *
			20.94395102393195529);
	}

	double Linear(double t)
	{
		return t;
	}
}
