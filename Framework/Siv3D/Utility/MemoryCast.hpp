# pragma once

namespace Utility
{
	template <typename To, typename From>
	To& memory_cast(From& from)
	{
		return *reinterpret_cast<To*>(&from);
	}

	template <typename To, typename From>
	To const& memory_cast(From const& from)
	{
		return *reinterpret_cast<To const*>(&from);
	}

	template <typename To, typename From>
	To* memory_cast(From* from)
	{
		return reinterpret_cast<To*>(from);
	}

	template <typename To, typename From>
	To const* memory_cast(From const* from)
	{
		return reinterpret_cast<To const*>(from);
	}
}
