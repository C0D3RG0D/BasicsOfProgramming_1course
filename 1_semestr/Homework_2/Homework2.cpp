#include <iostream>
#include <cmath>
#include <iomanip>


int Lab2() {
	setlocale(LC_ALL, "Rus");

	unsigned int x, i;
	

	std::cout << "Ââåäèòå ÷èñëî (0 < x < 10^9): " << std::endl;
	std::cin >> x;
	std::cout << "Ââåäèòå áèò, êîòîðûé íóæíî çàìåíèòü íà 1 (0 < i < 31): " << std::endl;
	std::cin >> i;

	if (i < 0 || i > 31) {
		std::cout << "Îøèáêà. i äîëæíî áûòü â äèàïîçîíå 0 < i < 31" << std::endl;
		return 1;
	}

	x = x | (1 << i);

	std::cout << "Ðåçóëüòàò: " << x << std::endl;

	return 0;
}