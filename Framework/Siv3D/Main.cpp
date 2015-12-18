# include <Siv3D.hpp>

template <typename Type>
Type Lerp(Type const& begin, Type const& end, double t)
{
	return begin + (end - begin) * t;
}

void Main()
{

}
