# pragma once

# include <functional>

namespace Utility
{
	using EasingFunction = double(double);

	template <EasingFunction easing>
	class Easing
	{
	public:

		static double In(double t)
		{
			return easing(t);
		}

		static double Out(double t)
		{
			return 1.0 - In(1.0 - t);
		}

		static double InOut(double t)
		{
			return t < 0.5 ?
				In(2.0 * t) / 2.0 :
				0.5 + Out(2.0 * t - 1.0) / 2.0;
		}
	};

	double Quad(double t);
	double Cubic(double t);
	double Quart(double t);
	double Quint(double t);
	double Sine(double t);
	double Exp(double t);
	double Circ(double t);
	double Back(double t);
	double Bounce(double t);
	double Elastic(double t);
	double Linear(double t);

	using EaseQuad = Easing<Quad>;
	using EaseCubic = Easing<Cubic>;
	using EaseQuart = Easing<Quart>;
	using EaseQuint = Easing<Quint>;
	using EaseSine = Easing<Sine>;
	using EaseExp = Easing<Exp>;
	using EaseCirc = Easing<Circ>;
	using EaseBack = Easing<Back>;
	using EaseBounce = Easing<Bounce>;
	using EaseElastic = Easing<Elastic>;
	using EaseLinear = Easing<Linear>;
}
