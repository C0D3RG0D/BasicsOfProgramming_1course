#include <iostream>
#include "Class_lab2.hpp"


int main() {
	setlocale(LC_ALL, "Rus");

	std::cout << "Первая матрица" << std::endl;
	myClass::Matrix matrix(3, 3);
	matrix.Print();

	std::cout << std::endl;

	std::cout << "Вторая матрица" << std::endl;
	myClass::Matrix otherMatrix(4, 4);
	otherMatrix.Print();

	std::cout << std::endl;

	std::cout << "Матрица, скопированная из первой" << std::endl;
	myClass::Matrix copyMatrix(matrix);
	copyMatrix.Print();

	std::cout << std::endl;

	std::cout << "Второй матрице присвоена первая" << std::endl;
	otherMatrix = matrix;
	otherMatrix.Print();

	std::cout << std::endl;

	std::cout << "Еще раз первая матрица" << std::endl;
	matrix.Print();


	return 0;
}