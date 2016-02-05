# pragma once

# include <initializer_list>
# include <algorithm>

namespace Utility
{
	namespace Math
	{
		/// <summary>弧度法</summary>
		static float const Radian = 0.01745329251994329547f;

		/// <summary>度数法</summary>
		static float const Degree = 57.29577951308232286f;

		/// <summary>円周率</summary>
		static float const Pi = 3.141592653589793116f;

		/// <summary>2 * π</summary>
		static float const Mul2Pi = 6.283185307179586232f;

		/// <summary>3 * π</summary>
		static float const Mul3Pi = 9.424777960769379348f;

		/// <summary>4 * π</summary>
		static float const Mul4Pi = 12.56637061435917246f;

		/// <summary>π/2</summary>
		static float const Div2Pi = 1.570796326794896558f;

		/// <summary>π/3</summary>
		static float const Div3Pi = 1.047197551196597853f;

		/// <summary>π/4</summary>
		static float const Div4Pi = 0.785398163397448279f;

		/// <summary>微小</summary>
		static float const Eps = 0.00000001f;

		/// <summary>度数法を弧度法に変換</summary>
		/// <param name="x">度数法</param>
		/// <returns>弧度法</returns>
		float ToRadian(float x);

		/// <summary>弧度法を度数法に変換</summary>
		/// <param name="x">弧度法</param>
		/// <returns>度数法</returns>
		float ToDegree(float x);

		/// <summary>サインを計算</summary>
		/// <param name="x">角度</param>
		/// <returns>サイン</returns>
		float Sin(float x);

		/// <summary>コサインを計算</summary>
		/// <param name="x">角度</param>
		/// <returns>コサイン</returns>
		float Cos(float x);

		/// <summary>タンジェントを計算</summary>
		/// <param name="x">角度</param>
		/// <returns>タンジェント</returns>
		float Tan(float x);

		/// <summary>アークサインを計算</summary>
		/// <param name="x">比率</param>
		/// <returns>アークサイン</returns>
		float Asin(float x);

		/// <summary>アークコサインを計算</summary>
		/// <param name="x">比率</param>
		/// <returns>アークサイン</returns>
		float Acos(float x);

		/// <summary>アークタンジェントを計算</summary>
		/// <param name="x">比率</param>
		/// <returns>アークタンジェント</returns>
		float Atan(float x);

		/// <summary>アークタンジェントを計算</summary>
		/// <param name="y">y成分</param>
		/// <param name="x">x成分</param>
		/// <returns>アークタンジェント</returns>
		float Atan2(float y, float x);

		/// <summary>x以下で最大の整数を返す</summary>
		/// <param name="x">基準値</param>
		/// <returns>x以下で最大の整数</returns>
		float Floor(float x);

		/// <summary>x以上で最大の整数を返す</summary>
		/// <param name="x">基準値</param>
		/// <returns>x以上で最大の整数</returns>
		float Ceiling(float x);

		/// <summary>四捨五入した値を返す</summary>
		/// <param name="x">値</param>
		/// <returns>四捨五入した値</returns>
		float Round(float x);

		/// <summary>符号を返す</summary>
		/// <param name="x">値</param>
		/// <returns>符号</returns>
		float Sign(float x);

		/// <summary>xのy乗を返す</summary>
		/// <param name="x">値</param>
		/// <param name="x">乗数</param>
		/// <returns>累乗</returns>
		float Pow(float x, float y);

		/// <summary>平方根を返す</summary>
		/// <param name="x">値</param>
		/// <returns>平方根</returns>
		float Sqrt(float x);

		/// <summary>xをy桁で均した値を返す</summary>
		/// <param name="x">値</param>
		/// <param name="y">桁数</param>
		/// <returns>均した値</returns>
		float Smooth(float x, int y);

		/// <summary>0から1の間にクランプする</summary>
		/// <param name="x">値</param>
		/// <returns>0から1の間にクランプされた値</returns>
		float Saturate(float x);

		/// <summary>指定した値の間にクランプする</summary>
		/// <param name="x">値</param>
		/// <param name="y">最小値</param>
		/// <param name="z">最大値</param>
		/// <returns>クランプされた値</returns>
		float Clamp(float x, float y, float z);

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
		std::pair<size_t, Type> MaxData(std::initializer_list<Type> const& args)
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
		Type Lerp(Type const& begin, Type const& end, float t)
		{
			return begin + (end - begin) * t;
		}
	}
}
