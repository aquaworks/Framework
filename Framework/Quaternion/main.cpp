# include "Transform/Quaternion.hpp"
# include <iostream>

using namespace Transform;

void main()
{
	Quaternion q;

	std::wcout << Quaternion::ToString(q) << std::endl;
}
