# include <iostream>

# include "Matrix.hpp"

void main()
{
	using namespace Transform;
	Matrix<double> a = Matrix<double>::Identity();
	auto b = Matrix<double>::Inversed(a) * a;
	std::cout << "inverse" << std::endl;
}
