# pragma once

# include <memory>

namespace Utility
{
	/// <summary>�����l</summary>
	struct NullOpt
	{
		static NullOpt const None;
	};

	/// <summary>�����l��\���ł���l�N���X</summary>
	template <typename Type>
	class Optional
	{
	public:

		/// <summary>�f�t�H���g�R���X�g���N�^</summary>
		Optional()
			: m_value()
		{

		}

		/// <summary>���z�f�X�g���N�^</summary>
		virtual ~Optional()
		{

		}

		/// <summary>�l�ŏ�����</summary>
		Optional(Type const& value)
			: m_value(std::make_unique<Type>(value))
		{

		}

		/// <summary>�l�����[�u���ď�����</summary>
		Optional(Type&& value)
			: m_value(&value)
		{

		}

		/// <param name="nullopt">�����l</param>
		Optional(NullOpt const& nullopt)
			: m_value()
		{
			(void)nullopt;
		}

		/// <summary>�R�s�[�R���X�g���N�^</summary>
		Optional(Optional const& other)
			: m_value(other ? std::make_unique<Type>(*other) : nullptr)
		{

		}

		/// <summary>���[�u�R���X�g���N�^</summary>
		Optional(Optional&& other)
			: m_value(other ? other.m_value.release() : nullptr)
		{

		}

		Optional& operator = (Type const& value)
		{
			return *this = Optional(value);
		}

		/// <param name="nullopt">�����l</param>
		Optional& operator = (NullOpt const& nullopt)
		{
			Release();
			return *this;
		}

		Optional& operator = (Optional const& other)
		{
			Optional& own = *this;

			if (own && other)
			{
				own = other;
			}
			else if (!own && other)
			{
				create(*other);
			}
			else if (own && !other)
			{
				Release();
			}

			return *this;
		}

		Optional& operator = (Optional&& other)
		{
			if ((*this) && !other)
			{
				Release();
			}
			else if (other)
			{
				create(std::move(*other));
			}
			return *this;
		}

		/// <summary>����</summary>
		void Create(Type const& value)
		{
			Release();
			m_value.reset(new Type(value));
		}

		/// <summary>����</summary>
		void Create(Type&& value)
		{
			Release();
			m_value.reset(new Type(std::forward<Type>(value)));
		}

		/// <summary>���</summary>
		void Release()
		{
			m_value.reset();
		}

		/// <summary>���</summary>
		/// <param name="args">����</param>
		template <typename ...Args>
		void Emplace(Args&& ...args)
		{
			m_value = std::make_unique<Type>(std::forward<Args>(args)...);
		}

	public:

		operator bool const() const
		{
			return IsEnabled();
		}

		Type& operator * ()
		{
			return Ref();
		}

		Type const& operator * () const
		{
			return Ref();
		}

		Type* operator & ()
		{
			return Pointer();
		}

		operator Type* const& () const
		{
			return Pointer();
		}

		/// <summary>�l���L�����ǂ�����Ԃ�</summary>
		bool IsEnabled() const
		{
			return m_value.get() != nullptr;
		}

		/// <summary>�Q�Ƃ�Ԃ�</summary>
		Type& Ref()
		{
			return *m_value.get();
		}

		/// <summary>�Q�Ƃ�Ԃ�</summary>
		Type const& Ref() const
		{
			return *m_value.get();
		}

		/// <summary>�|�C���^��Ԃ�</summary>
		Type* Pointer()
		{
			return m_value.get();
		}

		/// <summary>�|�C���^��Ԃ�</summary>
		Type const* Pointer() const
		{
			return m_value.get();
		}

	private:

		std::unique_ptr<Type> m_value;
	};

	/// <summary>Optional���\�z����</summary>
	/// <param name="args">����</param>
	template <typename Type, typename ...Args>
	Optional<Type>&& MakeOptional(Args&& ...args)
	{
		return std::move(Optional<Type>(std::forward<Args>(args)...));
	}

	template <typename Type>
	std::ostream& operator << (std::ostream& stream, Optional<Type> const& opt)
	{
		stream << opt.Ref();
		return stream;
	}

	template <typename Type>
	bool operator != (Optional<Type> const& o1, Optional<Type> const& o2)
	{
		return !(o1 == o2);
	}

	template <typename Type>
	bool operator == (Optional<Type> const& o, NullOpt const&)
	{
		return !o;
	}

	template <typename Type>
	bool operator != (Optional<Type> const& o, NullOpt const&)
	{
		return o;
	}

	template <typename Type>
	bool operator == (NullOpt const&, Optional<Type> const& o)
	{
		return !o;
	}

	template <typename Type>
	bool operator != (NullOpt const&, Optional<Type> const& o)
	{
		return o;
	}

	template <typename Type>
	bool operator == (Optional<Type> const& o1, Optional<Type> const& o2)
	{
		if (o1.IsEnabled() != o2.IsEnabled())
		{
			return false;
		}
		if (!o1)
		{
			return true;
		}
		return *o1 == *o2;
	}
}
