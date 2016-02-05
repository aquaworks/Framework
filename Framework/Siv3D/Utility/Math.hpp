# pragma once

# include <initializer_list>
# include <algorithm>

namespace Utility
{
	namespace Math
	{
		/// <summary>�ʓx�@</summary>
		static float const Radian = 0.01745329251994329547f;

		/// <summary>�x���@</summary>
		static float const Degree = 57.29577951308232286f;

		/// <summary>�~����</summary>
		static float const Pi = 3.141592653589793116f;

		/// <summary>2 * ��</summary>
		static float const Mul2Pi = 6.283185307179586232f;

		/// <summary>3 * ��</summary>
		static float const Mul3Pi = 9.424777960769379348f;

		/// <summary>4 * ��</summary>
		static float const Mul4Pi = 12.56637061435917246f;

		/// <summary>��/2</summary>
		static float const Div2Pi = 1.570796326794896558f;

		/// <summary>��/3</summary>
		static float const Div3Pi = 1.047197551196597853f;

		/// <summary>��/4</summary>
		static float const Div4Pi = 0.785398163397448279f;

		/// <summary>����</summary>
		static float const Eps = 0.00000001f;

		/// <summary>�x���@���ʓx�@�ɕϊ�</summary>
		/// <param name="x">�x���@</param>
		/// <returns>�ʓx�@</returns>
		float ToRadian(float x);

		/// <summary>�ʓx�@��x���@�ɕϊ�</summary>
		/// <param name="x">�ʓx�@</param>
		/// <returns>�x���@</returns>
		float ToDegree(float x);

		/// <summary>�T�C�����v�Z</summary>
		/// <param name="x">�p�x</param>
		/// <returns>�T�C��</returns>
		float Sin(float x);

		/// <summary>�R�T�C�����v�Z</summary>
		/// <param name="x">�p�x</param>
		/// <returns>�R�T�C��</returns>
		float Cos(float x);

		/// <summary>�^���W�F���g���v�Z</summary>
		/// <param name="x">�p�x</param>
		/// <returns>�^���W�F���g</returns>
		float Tan(float x);

		/// <summary>�A�[�N�T�C�����v�Z</summary>
		/// <param name="x">�䗦</param>
		/// <returns>�A�[�N�T�C��</returns>
		float Asin(float x);

		/// <summary>�A�[�N�R�T�C�����v�Z</summary>
		/// <param name="x">�䗦</param>
		/// <returns>�A�[�N�T�C��</returns>
		float Acos(float x);

		/// <summary>�A�[�N�^���W�F���g���v�Z</summary>
		/// <param name="x">�䗦</param>
		/// <returns>�A�[�N�^���W�F���g</returns>
		float Atan(float x);

		/// <summary>�A�[�N�^���W�F���g���v�Z</summary>
		/// <param name="y">y����</param>
		/// <param name="x">x����</param>
		/// <returns>�A�[�N�^���W�F���g</returns>
		float Atan2(float y, float x);

		/// <summary>x�ȉ��ōő�̐�����Ԃ�</summary>
		/// <param name="x">��l</param>
		/// <returns>x�ȉ��ōő�̐���</returns>
		float Floor(float x);

		/// <summary>x�ȏ�ōő�̐�����Ԃ�</summary>
		/// <param name="x">��l</param>
		/// <returns>x�ȏ�ōő�̐���</returns>
		float Ceiling(float x);

		/// <summary>�l�̌ܓ������l��Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <returns>�l�̌ܓ������l</returns>
		float Round(float x);

		/// <summary>������Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <returns>����</returns>
		float Sign(float x);

		/// <summary>x��y���Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <param name="x">�搔</param>
		/// <returns>�ݏ�</returns>
		float Pow(float x, float y);

		/// <summary>��������Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <returns>������</returns>
		float Sqrt(float x);

		/// <summary>x��y���ŋς����l��Ԃ�</summary>
		/// <param name="x">�l</param>
		/// <param name="y">����</param>
		/// <returns>�ς����l</returns>
		float Smooth(float x, int y);

		/// <summary>0����1�̊ԂɃN�����v����</summary>
		/// <param name="x">�l</param>
		/// <returns>0����1�̊ԂɃN�����v���ꂽ�l</returns>
		float Saturate(float x);

		/// <summary>�w�肵���l�̊ԂɃN�����v����</summary>
		/// <param name="x">�l</param>
		/// <param name="y">�ŏ��l</param>
		/// <param name="z">�ő�l</param>
		/// <returns>�N�����v���ꂽ�l</returns>
		float Clamp(float x, float y, float z);

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
		std::pair<size_t, Type> MaxData(std::initializer_list<Type> const& args)
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
		Type Lerp(Type const& begin, Type const& end, float t)
		{
			return begin + (end - begin) * t;
		}
	}
}
