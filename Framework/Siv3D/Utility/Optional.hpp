# pragma once

# include <memory>

namespace Utility
{
	/// <summary>無効値</summary>
	struct NullOpt
	{
		static NullOpt const None;
	};

	/// <summary>無効値を表現できる値クラス</summary>
	template <typename Type>
	class Optional
	{
	public:

		/// <summary>デフォルトコンストラクタ</summary>
		Optional()
			: m_value()
		{

		}

		/// <summary>仮想デストラクタ</summary>
		virtual ~Optional()
		{

		}

		/// <summary>値で初期化</summary>
		Optional(Type const& value)
			: m_value(std::make_unique<Type>(value))
		{

		}

		/// <summary>値をムーブして初期化</summary>
		Optional(Type&& value)
			: m_value(&value)
		{

		}

		/// <param name="nullopt">無効値</param>
		Optional(NullOpt const& nullopt)
			: m_value()
		{
			(void)nullopt;
		}

		/// <summary>コピーコンストラクタ</summary>
		Optional(Optional const& other)
			: m_value(other ? std::make_unique<Type>(*other) : nullptr)
		{

		}

		/// <summary>ムーブコンストラクタ</summary>
		Optional(Optional&& other)
			: m_value(other ? other.m_value.release() : nullptr)
		{

		}

		Optional& operator = (Type const& value)
		{
			return *this = Optional(value);
		}

		/// <param name="nullopt">無効値</param>
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

		/// <summary>生成</summary>
		void Create(Type const& value)
		{
			Release();
			m_value.reset(new Type(value));
		}

		/// <summary>生成</summary>
		void Create(Type&& value)
		{
			Release();
			m_value.reset(new Type(std::forward<Type>(value)));
		}

		/// <summary>解放</summary>
		void Release()
		{
			m_value.reset();
		}

		/// <summary>代入</summary>
		/// <param name="args">引数</param>
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

		/// <summary>値が有効かどうかを返す</summary>
		bool IsEnabled() const
		{
			return m_value.get() != nullptr;
		}

		/// <summary>参照を返す</summary>
		Type& Ref()
		{
			return *m_value.get();
		}

		/// <summary>参照を返す</summary>
		Type const& Ref() const
		{
			return *m_value.get();
		}

		/// <summary>ポインタを返す</summary>
		Type* Pointer()
		{
			return m_value.get();
		}

		/// <summary>ポインタを返す</summary>
		Type const* Pointer() const
		{
			return m_value.get();
		}

	private:

		std::unique_ptr<Type> m_value;
	};

	/// <summary>Optionalを構築する</summary>
	/// <param name="args">引数</param>
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
