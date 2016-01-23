# pragma once

namespace Utility
{
	template <typename To, typename From>
	To& MemoryCast(From& from)
	{
		return *reinterpret_cast<To*>(&from);
	}

	template <typename To, typename From>
	To const& MemoryCast(From const& from)
	{
		return *reinterpret_cast<To const*>(&from);
	}

	template <typename To, typename From>
	To* MemoryCast(From* from)
	{
		return reinterpret_cast<To*>(from);
	}

	template <typename To, typename From>
	To const* MemoryCast(From const* from)
	{
		return reinterpret_cast<To const*>(from);
	}
}
