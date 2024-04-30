#include "Class_lab4.hpp"


int main() {

	setlocale(LC_ALL, "Rus");

	my_class::BigInt num1, num2, num3;

	std::cout << "¬ведите число num1: " << std::endl;
	std::cin >> num1;

	std::cout << std::endl;

	std::cout << "¬ведите число num2: " << std::endl;
	std::cin >> num2;

	std::cout << std::endl;

	std::cout << "¬ведите число num3: " << std::endl;
	std::cin >> num3;

	std::cout << std::endl;

	my_class::BigInt num4(num1);

	my_class::BigInt sum1, sum2;

	sum1 = num1 + num2;
	sum2 = num1 + num3;

	num2 += num1;

	std::cout << "num2 += num1: " << num2 << std::endl;

	std::cout << std::endl;

	std::cout << "num1 + num2: " << sum1 << std::endl;

	std::cout << std::endl;
	std::cout << "num1 + num3: " << sum2 << std::endl;

	std::cout << std::endl;

	my_class::BigInt product;

	product = num1 * num2;

	std::cout << "num1 * num2: " << product << std::endl;

	std::cout << std::endl;

	std::cout << "num1 < num4: " << (num1 < num4) << std::endl;
	std::cout << "num1 > num4: " << (num1 > num4) << std::endl;
	std::cout << "num1 == num4: " << (num1 == num4) << std::endl;
	std::cout << "num1 != num4: " << (num1 != num4) << std::endl;


	return 0;
}