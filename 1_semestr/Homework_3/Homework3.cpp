#include <iostream>

int Lab3() {

	// Çàäàíèå 1

	setlocale(LC_ALL, "Rus");

	int a, b, c;
	
	std::cout << "Ââåäèòå ÷èñëî A: " << std::endl;
	std::cin >> a;

	std::cout << "Ââåäèòå ÷èñëî B: " << std::endl;
	std::cin >> b;

	std::cout << "Ââåäèòå ÷èñëî C: " << std::endl;
	std::cin >> c;

	if ((a + b) % c == 0 && c % b == 0) {
		std::cout << ((a + b) / c) - (c / b) << std::endl;
	}
	else if ((a + b) % c == 0 && c % b != 0) {
		std::cout << (a + b) / c + c * b << std::endl;
	}
	else {
		std::cout << a - b + c << std::endl;
	}

	// Çàäàíèå 2

	short n;

	std::cout << "Ââåäèåò êîä îøèáêè (0, 1, 2, 3): " << std::endl;
	std::cin >> n;

	switch (n) 
	{
		case 0:
			std::cout << "Îøèáîê íåò" << std::endl;
			break;

		case 1:
			std::cout << "Îøèáêà ÷òåíèÿ ôàéëà" << std::endl;
			break;

		case 2:
			std::cout << "Îøèáêà çàïèñè ôàéëà" << std::endl;
			break;

		case 3:
			std::cout << "Íå âñå ïîëÿ îïðåäåëåíû" << std::endl;
			break;

		default:
			std::cout << "Îøèáêà ñ òàêèì êîäîì îòñóòñòâóåò" << std::endl;
			break;
	}

	//Çàäàíèå 3

	short x;

	std::cout << "Ââåäòèå çíà÷åíèå x (1 èëè -1): " << std::endl;
	std::cin >> x;


	std::cout << (x == 1 ? "Positive Number" : (x == -1) ? "Negative Number" : "Îøèáêà! x ïðèíèìàåò òîëüêî çíà÷åíèÿ 1 èëè -1") << std::endl;

	return 0;
}