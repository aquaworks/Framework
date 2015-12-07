# pragma once

# include <string>
# include <vector>
# include <sstream>

namespace Utility
{
	namespace String
	{
		std::wstring Create(char const* value);

		std::wstring Create(std::string const& value);

		std::wstring Create(wchar_t const* value);

		std::wstring Create(std::wstring const& value);

		std::wstring Create(long double value);

		std::wstring Create(double value);

		std::wstring Create(float value);

		std::wstring Create(unsigned long long value);

		std::wstring Create(long long value);

		std::wstring Create(unsigned long value);

		std::wstring Create(long value);

		std::wstring Create(unsigned int value);

		std::wstring Create(int value);

		template <typename Type, typename ...Args>
		std::wstring Create(Type const& value, Args&& ...args)
		{
			return Create(value) + Create(std::forward<Args>(args)...);
		}

		std::vector<std::string> Split(std::string const& str, char delim);
		std::vector<std::wstring> Split(std::wstring const& str, wchar_t delim);

		template <typename Type>
		Type ToValue(std::string const& str)
		{
			std::stringstream stream(str);
			Type value;
			stream >> value;
			return value;
		}

		template <typename Type>
		Type ToValue(std::wstring const& str)
		{
			std::wstringstream stream(str);
			Type value;
			stream >> value;
			return value;
		}

		std::wstring ToWide(std::string const& narrow);

		std::string ToNarrow(std::wstring const& wide);
	}
}
