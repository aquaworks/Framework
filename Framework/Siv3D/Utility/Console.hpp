# pragma once

# include <iostream>

namespace Utility
{
	namespace Console
	{
		void Print();

		void Print(wchar_t const* value);

		template <typename Type>
		void Print(Type const& value)
		{
			std::cout << value;
		}

		template <typename Type, typename ...Args>
		void Print(Type const& value, Args&& ...args)
		{
			Print(value);
			Print(std::forward<Args>(args)...);
		}

		void Println();

		template <typename Type>
		void Println(Type const& value)
		{
			Print(value);
			Break();
		}

		template <typename Type, typename ...Args>
		void Println(Type const& value, Args&& ...args)
		{
			Print(value, std::forward<Args>(args)...);
			Break();
		}

		void Break();
	}
}
