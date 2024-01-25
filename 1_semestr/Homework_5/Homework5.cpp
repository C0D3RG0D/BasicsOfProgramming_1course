#include <iostream>
#include <algorithm>

const int N = 100;

//Ôóíêöèÿ äëÿ ïðîâåðêè ÷èñëà íà ïðîñòîòó
int isPrime(int n) {
	if (n <= 3) {
		if (n <= 1) {
			return false;
		}

		return true;
	}


	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

//Ôóíêöèÿ äëÿ íàõîæäåíèÿ ïåðâîé öèôðû ÷èñëà
int FirstNumber(int n) {
	while (n >= 9) {
		n /= 10;
	}
	return n;
}

//Ôóíêöèÿ äëÿ íàõîæäåíèÿ íàèìåíüøåé öèôðû ÷èñëà
int minNumber(int num) {
	if (num == 0) {
		return 0;
	}

	int min = 2'000'000'000;
	int n;

	while (num > 0) {
		n = num % 10;
		if (n < min) {
			min = n;
		}
		num /= 10;
	}

	return min;
}

//Ôóíêöèÿ ñîðòèðîâêè
void Sort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (FirstNumber(arr[j]) > FirstNumber(arr[j + 1])) {
				std::swap(arr[j], arr[j + 1]);
			}

			if (FirstNumber(arr[j]) == FirstNumber(arr[j + 1])) {
				if (minNumber(arr[j]) > minNumber(arr[j + 1])) {
					std::swap(arr[j], arr[j + 1]);
				}
			}

			if ((FirstNumber(arr[j]) == FirstNumber(arr[j + 1])) && (minNumber(arr[j]) > minNumber(arr[j + 1]))) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
}

//Ôóíêöèÿ äëÿ ïîäñ÷åòà ìèíèìàëüíîé ñóììû ñòðîêè ìàòðèöû è åå çàìåíû
void MinMatrixSum(int arr[N][N], int n, int m) {
	int min = 2'000'000'000;
	int sum = 0;
	int index = 0;

	for (int i = 0; i < n; ++i) {
		sum = 0;

		for (int j = 0; j < m; ++j) {
			sum += arr[i][j];
		}

		if (sum < min) {
			min = sum;
			index = i;
		}
	}

	for (int j = 0; j < m; ++j) {
		arr[index][j] = min;
	}
}

//Ôóíêöèÿ äëÿ ïðîâåðêè ÷èñåë-ïîëèäðîìîâ
bool isPalindrome(int num) {
	int originalNumber = num;
	int reversedNumber = 0;

	while (num > 0) {
		int digit = num % 10;
		reversedNumber = reversedNumber * 10 + digit;
		num /= 10;
	}

	return originalNumber == reversedNumber;
}

void CopyDel(int arr[], int& j) {
	int p = 0;
	int i = 0;

	for (int i = 0; i < j; ++i) {

		if (isPalindrome(arr[i])) {
			arr[i] = 0;
			p++;
		}
	}

	for (int i = 0; i < j; ++i) {
		for (int n = 0; n < j - 1; ++n) {

			if (arr[n] == 0) {
				std::swap(arr[n], arr[n + 1]);
			}

		}
	}

	j -= p;

	while (i < j) {

		if (isPrime(arr[i])) {

			for (int n = j; n > i; --n) {
				arr[n] = arr[n - 1];
			}
			j++;
			i++;

		}
		i++;
	}

}

int main1() {

	setlocale(LC_ALL, "Rus");


	// Çàäàíèå 2
	/*Ââåñòè ïîñëåäîâàòåëüíîñòü íàòóðàëüíûõ ÷èñåë {Aj}j=1...n (n<=1000).
	Óïîðÿäî÷èòü ïîñëåäîâàòåëüíîñòü ïî íåóáûâàíèþ ïåðâîé öèôðû ÷èñëà,
	÷èñëà ñ îäèíàêîâûìè ïåðâûìè öèôðàìè äîïîëíèòåëüíî óïîðÿäî÷èòü ïî íåóáûâàíèþ íàèìåíüøåé öèôðû ÷èñëà,
	÷èñëà ñ îäèíàêîâûìè ïåðâûìè öèôðàìè è îäèíàêîâûìè íàèìåíüøèìè öèôðàìè äîïîëíèòåëüíî óïîðÿäî÷èòü ïî íåóáûâàíèþ ñàìîãî ÷èñëà*/

	/*const int J = 1000;
	int array[J];
	int j;

	std::cout << "Ââåäèòå êîë-âî ÷ëåíîâ ïîñëåäîâàòåëüíîñòè (0 < j <= 1000): " << std::endl;
	std::cin >> j;

	if (j < 0 || j > 1000) {
		std::cout << "Îøèáêà! Êîë-âî ÷ëåíîâ ïîñëåäîâàòåëüíîñòè äîëæíî áûòü áîëüøå 0 è íå äîëæíî ïðåâûøàòü 1000!!!" << std::endl;
		return -1;
	}

	for (int i = 0; i < j; ++i) {
		std::cin >> array[i];
	}

	Sort(array, j);

	for (int i = 0; i < j; ++i) {
		std::cout << array[i] << " ";
	}*/

	// Çàäàíèå 3
	/*Äàíà öåëî÷èñëåííàÿ ìàòðèöà {Aij}i=1..n,j=1..m (n,m<=100).
	Íàéòè ñòðîêó ñ íàèìåíüøåé ñóììîé ýëåìåíòîâ è çàìåííèòü âñå ýëåìåíòû ýòîé ñòðîêè ýòîé ñóììîé.*/


	/*int matrix[N][N];
	int n;
	int m;

	std::cout << "Ââåäèòå ðàçìåðíîñòü ìàòðèöû (0 < n <= 100; 0 < m <= 100): " << std::endl;
	std::cin >> n;
	std::cin >> m;

	std::cout << "Ââîäèòå ýëåìåíòû: " << std::endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

	MinMatrixSum(matrix, n, m);

	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}*/


	// Çàäàíèå 4
	/*Ñíà÷àëà ââåäèòå ïîñëåäîâàòåëüíîñòü. Çàòåì óäàëèòå è ïðîäóáëèðóéòå ýëåìåíòû.
	Çàòåì âûâåäèòå ïîëó÷åííóþ ïîñëåäîâàòåëüíîñòü (êàæäûé ýëåìåíò ïî îäíîìó ðàçó).
	Èñïîëüçóéòå â ïðîãðàììå òîëüêî îäèí ìàññèâ.

	Äàíà ïîñëåäîâàòåëüíîñòü íàòóðàëüíûõ ÷èñåë {Aj}j=1...n (n<=10000).
	Óäàëèòü èç ïîñëåäîâàòåëüíîñòè ÷èñëà-ïàëèíäðîìû, à ñðåäè îñòàâøèõñÿ ïðîäóáëèðîâàòü ïðîñòûå ÷èñëà.*/

	const int J = 10000;
	int sequence[2 * J];
	int j;

	std::cout << "Ââåäèòå êîë-âî ÷ëåíîâ ïîñëåäîâàòåëüíîñòè: " << std::endl;
	std::cin >> j;

	std::cout << "Ââîäèòå ÷ëåíû ïîñëåäîâàòåëüíîñòè: " << std::endl;

	for (int i = 0; i < j; ++i) {
		std::cin >> sequence[i];
	}

	CopyDel(sequence, j);

	for (int i = 0; i < j; ++i) {
		std::cout << sequence[i] << std::endl;
	}




	return 0;
}