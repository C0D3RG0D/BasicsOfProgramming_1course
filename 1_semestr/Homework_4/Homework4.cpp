#include <iostream>

int Lab4() {
	setlocale(LC_ALL, "Rus");

	//Çàäàíèå 1
	
	int j, sum = 0, max = -1, a, k = -1;

	std::cout << "Ââåäèòå êîë-âî ýëåìåíòîâ ïîñëåäîâàòåëüíîñòè" << std::endl;
	std::cin >> j;

	std::cout << "Ââîäèòå ýëåìåíòû ïîñëåäîâàòåëüíîñòè" << std::endl;
	for (int i = 0; i < j; i++) {
		std::cin >> a;

		if (a % 10 == 0 || a % 10 == 7) {
			sum += a;

			max = a > max ? a : max;
			k = a == max ? i : k;
		}
		else {
			continue;
		}
	}

	std::cout << "Ñóììà ÷ëåíîâ ïîñëåäîâàòåëüíîñòè îêàí÷èâàþùèõñÿ íà 0 èëè 7: " << sum << std::endl;
	std::cout << "Ìàêñèìàëüíûé èç ÷ëåíîâ ïîñëåäîâàòåëüíîñòè îêàí÷èâàþùèõñÿ íà 0 èëè 7: " << max << std::endl;
	std::cout << "Èíäåêñ ìàêñèìàëüíîãî ÷èñëà: " << k << std::endl;


	//Çàäàíèå 2

	int n, sum1 = 0;

	std::cout << "Ââåäèòå ÷èñëî (0 < n < 10^9)" << std::endl;
	std::cin >> n;

	if (n > 1000000000) {
		std::cout << "×èñëî n äîëæíî áûòü ìåíüøå 10^9!" << std::endl;
		return 1;
	}

	while (n > 0) {

		int num = n % 10;

		if ((num & 1) == 1) {

			sum1 += num;

		}

		n /= 10;
	}

	std::cout << "Ñóììà íå÷åòíûõ öèôð ÷èñëà: "<< sum1 << std::endl;

	return 0;
}