#include "Class_lab6.hpp"	


int main() {

	my_class::Vector<bool> boolvector;

	boolvector.push_back(true);
	boolvector.push_back(false);
	boolvector.push_back(true);
	boolvector.push_back(false);
	boolvector.push_back(true);
	boolvector.push_back(true);
	boolvector.push_back(false);

	for (size_t i = 0; i < boolvector.size(); i++)
		std::cout << boolvector[i] << std::endl;

	std::cout << std::endl;

	std::cout << "boolvector[1]: " << std::endl;
	std::cout << boolvector[1] << std::endl;

	std::cout << std::endl;

	boolvector.set(1, true);

	std::cout << "boolvector.set(1, true): " << std::endl;
	std::cout << boolvector[1] << std::endl;

	std::cout << std::endl;

	std::cout << "boolvector.insert(2, false): " << std::endl;
	boolvector.insert(2, false);

	for (size_t i = 0; i < boolvector.size(); i++)
		std::cout << boolvector[i] << std::endl;

	std::cout << std::endl;

	std::cout << "boolvector.erase(2): " << std::endl;
	boolvector.erase(2);

	for (size_t i = 0; i < boolvector.size(); i++)
		std::cout << boolvector[i] << std::endl;


	return 0;
}