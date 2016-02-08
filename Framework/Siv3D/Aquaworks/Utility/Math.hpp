# pragma once

# include <initializer_list>
# include <algorithm>

# include "../Typedef.hpp"

namespace Aquaworks
{
	namespace Utility
	{
		namespace Math
		{
			/// <summary>弧度法</summary>
			static f32 const Radian = 0.01745329251994329547f;

			/// <summary>度数法</summary>
			static f32 const Degree = 57.29577951308232286f;

			/// <summary>円周率</summary>
			static f32 const Pi = 3.141592653589793116f;

			/// <summary>2 * π</summary>
			static f32 const Mul2Pi = 6.283185307179586232f;

			/// <summary>3 * π</summary>
			static f32 const Mul3Pi = 9.424777960769379348f;

			/// <summary>4 * π</summary>
			static f32 const Mul4Pi = 12.56637061435917246f;

			/// <summary>π/2</summary>
			static f32 const Div2Pi = 1.570796326794896558f;

			/// <summary>π/3</summary>
			static f32 const Div3Pi = 1.047197551196597853f;

			/// <summary>π/4</summary>
			static f32 const Div4Pi = 0.785398163397448279f;

			/// <summary>微小</summary>
			static f32 const Eps = 0.00000001f;

			/// <summary>度数法を弧度法に変換</summary>
			/// <param name="x">度数法</param>
			/// <returns>弧度法</returns>
			f32 ToRadian(f32 x);

			/// <summary>弧度法を度数法に変換</summary>
			/// <param name="x">弧度法</param>
			/// <returns>度数法</returns>
			f32 ToDegree(f32 x);

			/// <summary>サインを計算</summary>
			/// <param name="x">角度</param>
			/// <returns>サイン</returns>
			f32 Sin(f32 x);

			/// <summary>コサインを計算</summary>
			/// <param name="x">角度</param>
			/// <returns>コサイン</returns>
			f32 Cos(f32 x);

			/// <summary>タンジェントを計算</summary>
			/// <param name="x">角度</param>
			/// <returns>タンジェント</returns>
			f32 Tan(f32 x);

			/// <summary>アークサインを計算</summary>
			/// <param name="x">比率</param>
			/// <returns>アークサイン</returns>
			f32 Asin(f32 x);

			/// <summary>アークコサインを計算</summary>
			/// <param name="x">比率</param>
			/// <returns>アークサイン</returns>
			f32 Acos(f32 x);

			/// <summary>アークタンジェントを計算</summary>
			/// <param name="x">比率</param>
			/// <returns>アークタンジェント</returns>
			f32 Atan(f32 x);

			/// <summary>アークタンジェントを計算</summary>
			/// <param name="y">y成分</param>
			/// <param name="x">x成分</param>
			/// <returns>アークタンジェント</returns>
			f32 Atan2(f32 y, f32 x);

			/// <summary>x以下で最大の整数を返す</summary>
			/// <param name="x">基準値</param>
			/// <returns>x以下で最大の整数</returns>
			f32 Floor(f32 x);

			/// <summary>x以上で最大の整数を返す</summary>
			/// <param name="x">基準値</param>
			/// <returns>x以上で最大の整数</returns>
			f32 Ceiling(f32 x);

			/// <summary>四捨五入した値を返す</summary>
			/// <param name="x">値</param>
			/// <returns>四捨五入した値</returns>
			f32 Round(f32 x);

			/// <summary>符号を返す</summary>
			/// <param name="x">値</param>
			/// <returns>符号</returns>
			f32 Sign(f32 x);

			/// <summary>xのy乗を返す</summary>
			/// <param name="x">値</param>
			/// <param name="x">乗数</param>
			/// <returns>累乗</returns>
			f32 Pow(f32 x, f32 y);

			/// <summary>平方根を返す</summary>
			/// <param name="x">値</param>
			/// <returns>平方根</returns>
			f32 Sqrt(f32 x);

			/// <summary>xをy桁で均した値を返す</summary>
			/// <param name="x">値</param>
			/// <param name="y">桁数</param>
			/// <returns>均した値</returns>
			f32 Smooth(f32 x, s32 y);

			/// <summary>0から1の間にクランプする</summary>
			/// <param name="x">値</param>
			/// <returns>0から1の間にクランプされた値</returns>
			f32 Saturate(f32 x);

			/// <summary>指定した値の間にクランプする</summary>
			/// <param name="x">値</param>
			/// <param name="y">最小値</param>
			/// <param name="z">最大値</param>
			/// <returns>クランプされた値</returns>
			f32 Clamp(f32 x, f32 y, f32 z);

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
			Type Lerp(Type const& begin, Type const& end, f32 t)
			{
				return begin + (end - begin) * t;
			}
		}
	}
}
