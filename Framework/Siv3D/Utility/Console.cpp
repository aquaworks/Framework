# include "Console.hpp"

# include "String.hpp"

namespace Utility
{
	namespace Console
	{
		void Print()
		{

		}

		void Print(wchar_t const* value)
		{
			std::cout << String::ToNarrow(std::wstring(value));
		}

		void Println()
		{
			Print();
			Break();
		}

		void Break()
		{
			std::cout << std::endl;
		}
	}
}
