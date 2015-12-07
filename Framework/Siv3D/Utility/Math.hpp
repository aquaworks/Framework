# pragma once

# include <initializer_list>
# include <algorithm>

namespace Utility
{
	namespace Math
	{
		/// <summary>弧度法</summary>
		static double const RADIAN = 0.01745329251994329547;

		/// <summary>度数法</summary>
		static double const DEGREE = 57.29577951308232286;

		/// <summary>円周率</summary>
		static double const PI = 3.141592653589793116;

		/// <summary>2 * π</summary>
		static double const DOUBLE_PI = 6.283185307179586232;

		/// <summary>3 * π</summary>
		static double const TRIPLE_PI = 9.424777960769379348;

		/// <summary>4 * π</summary>
		static double const QUADRUPLE_PI = 12.56637061435917246;

		/// <summary>π/2</summary>
		static double const HALF_PI = 1.570796326794896558;

		/// <summary>π/3</summary>
		static double const DIV3_PI = 1.047197551196597853;

		/// <summary>π/4</summary>
		static double const DIV4_PI = 0.785398163397448279;

		/// <summary>度数法を弧度法に変換</summary>
		/// <param name="x">度数法</param>
		/// <returns>弧度法</returns>
		double ToRadian(double x);

		/// <summary>弧度法を度数法に変換</summary>
		/// <param name="x">弧度法</param>
		/// <returns>度数法</returns>
		double ToDegree(double x);

		/// <summary>サインを計算</summary>
		/// <param name="x">角度</param>
		/// <returns>サイン</returns>
		double Sin(double x);

		/// <summary>コサインを計算</summary>
		/// <param name="x">角度</param>
		/// <returns>コサイン</returns>
		double Cos(double x);

		/// <summary>タンジェントを計算</summary>
		/// <param name="x">角度</param>
		/// <returns>タンジェント</returns>
		double Tan(double x);

		/// <summary>アークサインを計算</summary>
		/// <param name="x">比率</param>
		/// <returns>アークサイン</returns>
		double Asin(double x);

		/// <summary>アークコサインを計算</summary>
		/// <param name="x">比率</param>
		/// <returns>アークサイン</returns>
		double Acos(double x);

		/// <summary>アークタンジェントを計算</summary>
		/// <param name="x">比率</param>
		/// <returns>アークタンジェント</returns>
		double Atan(double x);

		/// <summary>アークタンジェントを計算</summary>
		/// <param name="y">y成分</param>
		/// <param name="x">x成分</param>
		/// <returns>アークタンジェント</returns>
		double Atan2(double y, double x);

		/// <summary>x以下で最大の整数を返す</summary>
		/// <param name="x">基準値</param>
		/// <returns>x以下で最大の整数</returns>
		double Floor(double x);

		/// <summary>x以上で最大の整数を返す</summary>
		/// <param name="x">基準値</param>
		/// <returns>x以上で最大の整数</returns>
		double Ceiling(double x);

		/// <summary>四捨五入した値を返す</summary>
		/// <param name="x">値</param>
		/// <returns>四捨五入した値</returns>
		double Round(double x);

		/// <summary>符号を返す</summary>
		/// <param name="x">値</param>
		/// <returns>符号</returns>
		double Sign(double x);

		/// <summary>xのy乗を返す</summary>
		/// <param name="x">値</param>
		/// <param name="x">乗数</param>
		/// <returns>累乗</returns>
		double Pow(double x, double y);

		/// <summary>平方根を返す</summary>
		/// <param name="x">値</param>
		/// <returns>平方根</returns>
		double Sqrt(double x);

		/// <summary>xをy桁で均した値を返す</summary>
		/// <param name="x">値</param>
		/// <param name="y">桁数</param>
		/// <returns>均した値</returns>
		double Smooth(double x, int y);

		/// <summary>0から1の間にクランプする</summary>
		/// <param name="x">値</param>
		/// <returns>0から1の間にクランプされた値</returns>
		double Saturate(double x);

		/// <summary>指定した値の間にクランプする</summary>
		/// <param name="x">値</param>
		/// <param name="y">最小値</param>
		/// <param name="z">最大値</param>
		/// <returns>クランプされた値</returns>
		double Clamp(double x, double y, double z);

		/// <summary>絶対値を返す</summary>
		/// <param name="value">値</param>
		/// <returns>絶対値</returns>
		template <typename Type>
		Type Abs(Type const& value)
		{
			return std::abs(value);
		}

		/// <summary>最大の値を返す</summary>
		/// <param name="args">値の初期化リスト</param>
		/// <returns>最大値</returns>
		template <typename Type>
		Type Max(std::initializer_list<Type> const& args)
		{
			return *std::max_element(args.begin(), args.end());
		}

		/// <summary>最小の値を返す</summary>
		/// <param name="args">値の初期化リスト</param>
		/// <returns>最小値</returns>
		template <typename Type>
		Type Min(std::initializer_list<Type> const& args)
		{
			return *std::min_element(args.begin(), args.end());
		}

		/// <summary>最大の値のインデックスを返す</summary>
		/// <param name="args">値の初期化リスト</param>
		/// <returns>最大値のインデックス</returns>
		template <typename Type>
		size_t MaxIndex(std::initializer_list<Type> const& args)
		{
			return std::max_element(args.begin(), args.end()) - args.begin();
		}

		/// <summary>最大の値とインデックスを返す</summary>
		/// <param name="args">値の初期化リスト</param>
		/// <returns>最大値とインデックス</returns>
		template <typename Type>
		std::pair<int, Type> MaxData(std::initializer_list<Type> const& args)
		{
			auto it = std::max_element(args.begin(), args.end());
			return std::make_pair(it - args.begin(), *it);
		}

		/// <summary>値が範囲内にあるかを返す</summary>
		/// <param name="value">値</param>
		/// <param name="min">最小値</param>
		/// <param name="max">最大値</param>
		template <typename Type>
		bool IsContains(Type const& value, Type const& min, Type const& max)
		{
			return
				min <= value &&
				value <= max;
		}

		/// <summary>線形補間した値を返す</summary>
		/// <param name="begin">開始値</param>
		/// <param name="end">終了値</param>
		/// <param name="t">変化率</param>
		/// <returns>線形補間した値</returns>
		template <typename Type>
		Type Lerp(Type const& begin, Type const& end, double t)
		{
			return begin + (end - begin) * t;
		}
	}
}
