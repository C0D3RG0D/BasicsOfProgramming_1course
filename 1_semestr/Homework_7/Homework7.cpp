#include <iostream>
#include "Homework7.hpp"


int Lab7() {

	/*Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
	Если в матрице есть еще один элемент, равный ее минимальному элементу, 
	и не менее 2-х элементов, абсолютные величины которых - простые числа, 
	упорядочить строки матрицы по невозрастанию произведений элементов. */

	setlocale(LC_ALL, "Rus");

	int sequence[N][N];
	int n;
	int m;

	std::cout << "Введите размерность матрицы: " << std::endl;
	std::cin >> n;
	std::cin >> m;

	std::cout << "Вводите элементы матрицы построчно: " << std::endl;
	mt::input_matrix(sequence, n, m);

	mt::Sort(sequence, n, m);
	std::cout << ' ' << std::endl;

	mt::out_matrix(sequence, n, m);


	return 0;
}