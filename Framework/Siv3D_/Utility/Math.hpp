# pragma once

# include <initializer_list>
# include <algorithm>

namespace Utility
{
	namespace Math
	{
		/// <summary>�ʓx�@</summary>
		static double const RADIAN = 0.01745329251994329547;

		/// <summary>�x���@</summary>
		static double const DEGREE = 57.29577951308232286;

		/// <summary>�~����</summary>
		static double const PI = 3.141592653589793116;

		/// <summary>2 * ��</summary>
		static double const DOUBLE_PI = 6.283185307179586232;

		/// <summary>3 * ��</summary>
		static double const TRIPLE_PI = 9.424777960769379348;

		/// <summary>4 * ��</summary>
		static double const QUADRUPLE_PI = 12.56637061435917246;

		/// <summary>��/2</summary>
		static double const HALF_PI = 1.570796326794896558;

		/// <summary>��/3</summary>
		static double const DIV3_PI = 1.047197551196597853;

		/// <summary>��/4</summary>
		static double const DIV4_PI = 0.785398163397448279;

		/// <summary>�x���@���ʓx�@�ɕϊ�</summary>
		/// <param name="x">�x���@</param>
		/// <returns>�ʓx�@</returns>
		double ToRadian(double x);

		/// <summary>�ʓx�@��x���@�ɕϊ�</summary>
		/// <param name="x">�ʓx�@</param>
		/// <returns>�x���@</returns>
		double ToDegree(double x);

		/// <summary>�T�C�����v�Z</summary>
		/// <param name="x">�p�x</param>
		/// <returns>�T�C��</returns>
		double Sin(double x);

		/// <summary>�R�T�C�����v�Z</summary>
		/// <param name="x">�p�x</param>
		/// <returns>�R�T�C��</returns>
		double Cos(double x);

		/// <summary>�^���W�F���g���v�Z</summary>
		/// <param name="x">�p�x</param>
		/// <returns>�^���W�F���g</returns>
		double Tan(double x);

		/// <summary>�A�[�N�T�C�����v�Z</summary>
		/// <param name="x">�䗦</param>
		/// <returns>�A�[�N�T�C��</returns>
		double Asin(double x);

		/// <summary>�A�[�N�R�T�C�����v�Z</summary>
		/// <param name="x">�䗦</param>
		/// <returns>�A�[�N�T�C��</returns>
		double Acos(double x);

		/// <summary>�A�[�N�^���W�F���g���v�Z</summary>
		/// <param name="x">�䗦</param>
		/// <returns>�A�[�N�^���W�F���g</returns>
		double Atan(double x);

		/// <summary>�A�[�N�^���W�F���g���v�Z</summary>
		/// <param name="y">y����</param>
		/// <param name="x">x����</param>
		/// <returns>�A�[�N�^���W�F���g</returns>
		double Atan2(double y, double x);

		/// <summary>x�ȉ��ōő�̐�����Ԃ�</summary>
		/// <param name="x">��l</param>
		/// <returns>x�ȉ��ōő�̐���</returns>
		double Floor(double x);

		/// <summary>x�ȏ�ōő�̐�����Ԃ�</summary>
		/// <param name="x">��l</param>
		/// <returns>x�ȏ�ōő�̐���</returns>
		double Ceiling(double x);

		/// <summary>�l�̌ܓ������l��Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <returns>�l�̌ܓ������l</returns>
		double Round(double x);

		/// <summary>������Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <returns>����</returns>
		double Sign(double x);

		/// <summary>x��y���Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <param name="x">�搔</param>
		/// <returns>�ݏ�</returns>
		double Pow(double x, double y);

		/// <summary>��������Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <returns>������</returns>
		double Sqrt(double x);

		/// <summary>x��y���ŋς����l��Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <param name="y">����</param>
		/// <returns>�ς����l</returns>
		double Smooth(double x, int y);

		/// <summary>0����1�̊ԂɃN�����v����</summary>
		/// <param name="x">�l</param>
		/// <returns>0����1�̊ԂɃN�����v���ꂽ�l</returns>
		double Saturate(double x);

		/// <summary>�w�肵���l�̊ԂɃN�����v����</summary>
		/// <param name="x">�l</param>
		/// <param name="y">�ŏ��l</param>
		/// <param name="z">�ő�l</param>
		/// <returns>�N�����v���ꂽ�l</returns>
		double Clamp(double x, double y, double z);

		/// <summary>��Βl��Ԃ�</summary>
		/// <param name="value">�l</param>
		/// <returns>��Βl</returns>
		template <typename Type>
		Type Abs(Type const& value)
		{
			return std::abs(value);
		}

		/// <summary>�ő�̒l��Ԃ�</summary>
		/// <param name="args">�l�̏��������X�g</param>
		/// <returns>�ő�l</returns>
		template <typename Type>
		Type Max(std::initializer_list<Type> const& args)
		{
			return *std::max_element(args.begin(), args.end());
		}

		/// <summary>�ŏ��̒l��Ԃ�</summary>
		/// <param name="args">�l�̏��������X�g</param>
		/// <returns>�ŏ��l</returns>
		template <typename Type>
		Type Min(std::initializer_list<Type> const& args)
		{
			return *std::min_element(args.begin(), args.end());
		}

		/// <summary>�ő�̒l�̃C���f�b�N�X��Ԃ�</summary>
		/// <param name="args">�l�̏��������X�g</param>
		/// <returns>�ő�l�̃C���f�b�N�X</returns>
		template <typename Type>
		size_t MaxIndex(std::initializer_list<Type> const& args)
		{
			return std::max_element(args.begin(), args.end()) - args.begin();
		}

		/// <summary>�ő�̒l�ƃC���f�b�N�X��Ԃ�</summary>
		/// <param name="args">�l�̏��������X�g</param>
		/// <returns>�ő�l�ƃC���f�b�N�X</returns>
		template <typename Type>
		std::pair<int, Type> MaxData(std::initializer_list<Type> const& args)
		{
			auto it = std::max_element(args.begin(), args.end());
			return std::make_pair(it - args.begin(), *it);
		}

		/// <summary>�l���͈͓��ɂ��邩��Ԃ�</summary>
		/// <param name="value">�l</param>
		/// <param name="min">�ŏ��l</param>
		/// <param name="max">�ő�l</param>
		template <typename Type>
		bool IsContains(Type const& value, Type const& min, Type const& max)
		{
			return
				min <= value &&
				value <= max;
		}

		/// <summary>���`��Ԃ����l��Ԃ�</summary>
		/// <param name="begin">�J�n�l</param>
		/// <param name="end">�I���l</param>
		/// <param name="t">�ω���</param>
		/// <returns>���`��Ԃ����l</returns>
		template <typename Type>
		Type Lerp(Type const& begin, Type const& end, double t)
		{
			return begin + (end - begin) * t;
		}
	}
}
