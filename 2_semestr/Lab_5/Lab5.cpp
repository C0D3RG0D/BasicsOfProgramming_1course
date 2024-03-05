#include "Class_lab5.hpp"


int main() {

	setlocale(LC_ALL, "Rus");

	my_class::Matrix<int, 3, 2> matrix1;
	my_class::Matrix<int, 2, 3> matrix2;

	std::cout << "¬ведите матрицу 1: " << std::endl;
	std::cin >> matrix1;

	std::cout << "¬ведите матрицу 2: " << std::endl;
	std::cin >> matrix2;

	std::cout << std::endl;

	std::cout << matrix1 << std::endl;
	std::cout << matrix2 << std::endl;

	auto matrix3 = matrix1 * matrix2;
	std::cout << matrix3 << std::endl;

	auto matrix4 = matrix2;
	std::cout << matrix4 << std::endl;

	matrix4 *= 2;
	std::cout << matrix4 << std::endl;

	++matrix2;
	std::cout << matrix2 << std::endl;

	std::cout << matrix3.determinant() << std::endl;

	matrix1(0, 0) = 101;

	std::cout << std::endl;

	matrix1(0, 0) = 11;

	std::cout << matrix1 << std::endl;

}