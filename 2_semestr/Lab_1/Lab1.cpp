#include "Class_lab1.hpp"
#include <iostream>


int main() {

	myclass::Parallelepiped my_box(5.0f, 5.0f, 12.0f);

	std::cout << "Parallelepiped data: " << std::endl;

	std::cout << std::endl;

	std::cout << "The length of the parallelepiped: " << my_box.getLength() << std::endl;
	std::cout << "The width of the parallelepiped: " << my_box.getWidth() << std::endl;
	std::cout << "The height of the parallelepiped: " << my_box.getHeight() << std::endl;

	std::cout << std::endl;

	std::cout << "Calculations of the area, volume and diagonal of a parallelepiped: " << std::endl;

	std::cout << std::endl;

	std::cout << "The area of the parallelepiped: " << my_box.calculating_the_area() << std::endl;
	std::cout << "The volume of the parallelepiped: " << my_box.calculating_the_volume() << std::endl;
	std::cout << "The diagonal of the parallelepiped: " << my_box.calculating_the_diagonal() << std::endl;

	return 0;
}