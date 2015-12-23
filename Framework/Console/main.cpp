# include "Utility/Console.hpp"
# include <string>

using namespace Utility;

void main()
{
	std::string str = "すとりんぐ";
	int i = 123;
	float f = 1.08f;
	double d = 3.141592;
	const wchar_t* wstr = L"わいどもじれつ";

	Console::Println();

	Console::Println(str);

	Console::Println(i);

	Console::Println(f);

	Console::Println(d);

	Console::Println(wstr);

	Console::Println("---------------");

	Console::Println(str, i, f, d, wstr);
}
