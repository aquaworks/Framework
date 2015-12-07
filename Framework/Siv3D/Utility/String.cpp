# include "String.hpp"

# include <Windows.h>

namespace Utility
{
	namespace String
	{
		std::wstring Create(char const* value)
		{
			return ToWide(value);
		}

		std::wstring Create(std::string const& value)
		{
			return ToWide(value);
		}

		std::wstring Create(wchar_t const* value)
		{
			return std::wstring(value);
		}

		std::wstring Create(std::wstring const& value)
		{
			return value;
		}

		std::wstring Create(long double value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(double value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(float value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(unsigned long long value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(long long value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(unsigned long value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(long value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(unsigned int value)
		{
			return std::to_wstring(value);
		}

		std::wstring Create(int value)
		{
			return std::to_wstring(value);
		}

		std::vector<std::string> Split(std::string const& str, char delim)
		{
			std::vector<std::string> res;
			size_t current = 0, found;
			std::string s = str;
			while ((found = s.find_first_of(delim, current)) != std::string::npos)
			{
				res.push_back(std::string(s, current, found - current));
				current = found + 1;
			}
			res.push_back(std::string(s, current, s.size() - current));
			return res;
		}

		std::vector<std::wstring> Split(std::wstring const& str, wchar_t delim)
		{
			std::vector<std::wstring> res;
			size_t current = 0, found;
			std::wstring s = str;
			while ((found = s.find_first_of(delim, current)) != std::wstring::npos)
			{
				res.push_back(std::wstring(s, current, found - current));
				current = found + 1;
			}
			res.push_back(std::wstring(s, current, s.size() - current));
			return res;
		}

		std::wstring ToWide(std::string const& narrow)
		{
			int length =
				MultiByteToWideChar(CP_ACP, 0, narrow.c_str(), -1, NULL, 0);
			wchar_t* buffer = new wchar_t[length];
			MultiByteToWideChar(CP_ACP, 0, narrow.c_str(), -1, buffer, length);
			std::wstring result(buffer, buffer + length - 1);
			delete[] buffer;
			return result;
		}

		std::string ToNarrow(std::wstring const& wide)
		{
			int length = WideCharToMultiByte(
				CP_OEMCP, 0, wide.c_str(), -1, NULL, 0, NULL, NULL);
			char* buffer = new char[length];
			WideCharToMultiByte(
				CP_OEMCP, 0, wide.c_str(), -1, buffer, length, NULL, NULL);
			std::string result(buffer, buffer + length - 1);
			delete[] buffer;
			return result;
		}
	}
}
