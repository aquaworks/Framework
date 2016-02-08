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
			/// <summary>�ʓx�@</summary>
			static f32 const Radian = 0.01745329251994329547f;

			/// <summary>�x���@</summary>
			static f32 const Degree = 57.29577951308232286f;

			/// <summary>�~����</summary>
			static f32 const Pi = 3.141592653589793116f;

			/// <summary>2 * ��</summary>
			static f32 const Mul2Pi = 6.283185307179586232f;

			/// <summary>3 * ��</summary>
			static f32 const Mul3Pi = 9.424777960769379348f;

			/// <summary>4 * ��</summary>
			static f32 const Mul4Pi = 12.56637061435917246f;

			/// <summary>��/2</summary>
			static f32 const Div2Pi = 1.570796326794896558f;

			/// <summary>��/3</summary>
			static f32 const Div3Pi = 1.047197551196597853f;

			/// <summary>��/4</summary>
			static f32 const Div4Pi = 0.785398163397448279f;

			/// <summary>����</summary>
			static f32 const Eps = 0.00000001f;

			/// <summary>�x���@���ʓx�@�ɕϊ�</summary>
			/// <param name="x">�x���@</param>
			/// <returns>�ʓx�@</returns>
			f32 ToRadian(f32 x);

			/// <summary>�ʓx�@��x���@�ɕϊ�</summary>
			/// <param name="x">�ʓx�@</param>
			/// <returns>�x���@</returns>
			f32 ToDegree(f32 x);

			/// <summary>�T�C�����v�Z</summary>
			/// <param name="x">�p�x</param>
			/// <returns>�T�C��</returns>
			f32 Sin(f32 x);

			/// <summary>�R�T�C�����v�Z</summary>
			/// <param name="x">�p�x</param>
			/// <returns>�R�T�C��</returns>
			f32 Cos(f32 x);

			/// <summary>�^���W�F���g���v�Z</summary>
			/// <param name="x">�p�x</param>
			/// <returns>�^���W�F���g</returns>
			f32 Tan(f32 x);

			/// <summary>�A�[�N�T�C�����v�Z</summary>
			/// <param name="x">�䗦</param>
			/// <returns>�A�[�N�T�C��</returns>
			f32 Asin(f32 x);

			/// <summary>�A�[�N�R�T�C�����v�Z</summary>
			/// <param name="x">�䗦</param>
			/// <returns>�A�[�N�T�C��</returns>
			f32 Acos(f32 x);

			/// <summary>�A�[�N�^���W�F���g���v�Z</summary>
			/// <param name="x">�䗦</param>
			/// <returns>�A�[�N�^���W�F���g</returns>
			f32 Atan(f32 x);

			/// <summary>�A�[�N�^���W�F���g���v�Z</summary>
			/// <param name="y">y����</param>
			/// <param name="x">x����</param>
			/// <returns>�A�[�N�^���W�F���g</returns>
			f32 Atan2(f32 y, f32 x);

			/// <summary>x�ȉ��ōő�̐�����Ԃ�</summary>
			/// <param name="x">��l</param>
			/// <returns>x�ȉ��ōő�̐���</returns>
			f32 Floor(f32 x);

			/// <summary>x�ȏ�ōő�̐�����Ԃ�</summary>
			/// <param name="x">��l</param>
			/// <returns>x�ȏ�ōő�̐���</returns>
			f32 Ceiling(f32 x);

			/// <summary>�l�̌ܓ������l��Ԃ�</summary>
			/// <param name="x">�l</param>
			/// <returns>�l�̌ܓ������l</returns>
			f32 Round(f32 x);

			/// <summary>������Ԃ�</summary>
			/// <param name="x">�l</param>
			/// <returns>����</returns>
			f32 Sign(f32 x);

			/// <summary>x��y���Ԃ�</summary>
			/// <param name="x">�l</param>
			/// <param name="x">�搔</param>
			/// <returns>�ݏ�</returns>
			f32 Pow(f32 x, f32 y);

			/// <summary>��������Ԃ�</summary>
			/// <param name="x">�l</param>
			/// <returns>������</returns>
			f32 Sqrt(f32 x);

			/// <summary>x��y���ŋς����l��Ԃ�</summary>
			/// <param name="x">�l</param>
			/// <param name="y">����</param>
			/// <returns>�ς����l</returns>
			f32 Smooth(f32 x, s32 y);

			/// <summary>0����1�̊ԂɃN�����v����</summary>
			/// <param name="x">�l</param>
			/// <returns>0����1�̊ԂɃN�����v���ꂽ�l</returns>
			f32 Saturate(f32 x);

			/// <summary>�w�肵���l�̊ԂɃN�����v����</summary>
			/// <param name="x">�l</param>
			/// <param name="y">�ŏ��l</param>
			/// <param name="z">�ő�l</param>
			/// <returns>�N�����v���ꂽ�l</returns>
			f32 Clamp(f32 x, f32 y, f32 z);

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
			Type Lerp(Type const& begin, Type const& end, f32 t)
			{
				return begin + (end - begin) * t;
			}
		}
	}
}
