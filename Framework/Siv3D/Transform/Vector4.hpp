# pragma once

# include <string>

namespace Transform
{
	// -------------------------------------------------------------------
	// �O�u�錾
	// -------------------------------------------------------------------
	class Vector3;
	class Point4;


	/// <summary>�l�����x�N�g��</summary>
	class Vector4
	{
	public:

		/// <summary>(0, 0, 0)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
		static Vector4 const& Zero();

		/// <summary>(1, 1, 1)�ŏ��������ꂽ�x�N�g����Ԃ�</summary>
		static Vector4 const& One();

	public:

		/// <summary>�R���X�g���N�^</summary>
		Vector4();

		/// <summary>�R�s�[�R���X�g���N�^</summary>
		Vector4(Vector4 const& v);

		/// <summary>�v�f���w�肵�č\�z����</summary>
		Vector4(float x, float y, float z, float w);

		/// <summary>�O�����x�N�g����w�v�f���w�肵�č\�z����</summary>
		Vector4(Vector3 const& v, float w);

		/// <summary>�l�����_����\�z����</summary>
		explicit Vector4(Point4 const& v);

		/// <summary>������Z�q</summary>
		Vector4& operator = (Vector4 const& v);

	public:

		/// <summary>�z��ɕϊ�����</summary>
		operator float* ();

		/// <summary>�z��ɕϊ�����</summary>
		operator float const* () const;

	public:

		/// <summary>������ɕϊ����ĕԂ�</summary>
		std::wstring toString() const;

		/// <summary>���ς�Ԃ�</summary>
		/// <param name="v">�x�N�g��</param>
		float dot(Vector4 const& v) const;

		/// <summary>���K������</summary>
		Vector4& normalize();

		/// <summary>�����̓���Ԃ�</summary>
		float lengthSquared() const;

		/// <summary>������Ԃ�</summary>
		float length() const;

		/// <summary>�ˉe����</summary>
		/// <param name="v">�Ώۂ̃x�N�g��</param>
		Vector4& projection(Vector4 const& v);

	public:

		/// <summary>������ɕϊ����ĕԂ�</summary>
		/// <param name="v">�x�N�g��</param>
		static std::wstring ToString(Vector4 const& v);

		/// <summary>���ς�Ԃ�</summary>
		static float Dot(Vector4 const& v1, Vector4 const& v2);

		/// <summary>�����̓���Ԃ�</summary>
		/// <param name="v">�x�N�g��</param>
		static float LengthSquared(Vector4 const& v);

		/// <summary>������Ԃ�</summary>
		/// <param name="v">�x�N�g��</param>
		static float Length(Vector4 const& v);

		/// <summary>���K�������x�N�g���Ԃ�</summary>
		/// <param name="v">�x�N�g��</param>
		static Vector4 Normalize(Vector4 const& v);

		/// <summary>�ˉe�����x�N�g����Ԃ�</summary>
		/// <param name="v">�x�N�g��</param>
		/// <param name="target">�Ώۂ̃x�N�g��</param>
		static Vector4 Projection(Vector4 const& v, Vector4 const& target);

		/// <summary>���`��Ԃ����x�N�g����Ԃ�</summary>
		/// <param name="start">�J�n�x�N�g��</param>
		/// <param name="end">�I���x�N�g��</param>
		/// <param name="t">�J�ڗ�</param>
		static Vector4 Lerp(Vector4 const& start, Vector4 const& end, float t);

	public:

		union
		{
			float elm[4];

			float mat[1][4];

			struct
			{
				float r, g, b, a;
			};

			struct
			{
				float x, y, z, w;
			};
		};
	};

	bool operator == (Vector4 const& v1, Vector4 const& v2);

	bool operator != (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator + (Vector4 const& v);

	Vector4 operator - (Vector4 const& v);

	Vector4& operator += (Vector4& v1, Vector4 const& v2);

	Vector4& operator -= (Vector4& v1, Vector4 const& v2);

	Vector4& operator *= (Vector4& v1, Vector4 const& v2);

	Vector4& operator *= (Vector4& v, float s);

	Vector4& operator /= (Vector4& v1, Vector4 const& v2);

	Vector4& operator /= (Vector4& v, float s);

	Vector4 operator + (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator - (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator * (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator * (Vector4 const& v, float s);

	Vector4 operator * (float s, Vector4 const& v);

	Vector4 operator / (Vector4 const& v1, Vector4 const& v2);

	Vector4 operator / (Vector4 const& v, float s);
}
