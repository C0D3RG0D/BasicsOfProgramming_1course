#pragma once
#include <algorithm>
#define N 100

namespace mt {

	//Ôóíêöèÿ äëÿ ââîäà ìàòðèöû
	void input_matrix(int arr[N][N], int n, int m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cin >> arr[i][j];
			}
		}
	}

	//Ôóíêöèÿ äëÿ âûâîäà ìàòðèöû
	void out_matrix(int arr[N][N], int n, int m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << arr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	//Ôóíêöèÿ äëÿ ïðîâåðêè ïðîñòîòû ÷èñëà
	bool isPrime(int n) {

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

	//Ôóíêöèÿ äëÿ ïîäñ÷åòà êîëè÷åñòâà ïðîñòûõ ýëåìåíòîâ ìàòðèöû
	int primeMatrixElements(int arr[N][N], int n, int m) {
		int p = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {

				int num = arr[i][j];

				if (isPrime(abs(num))) {
					p++;
				}
			}
		}

		return p;
	}

	//Ôóíêöèÿ äëÿ ïîèñêà ìèíèìàëüíîãî ýëåìåíòà ìàòðèöû.
	int minMatrixElement(int arr[N][N], int n, int m) {
		int min = 1'000'000'000;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] <= min) {
					min = arr[i][j];
				}
			}
		}

		return min;
	}

	bool compositionMatrixElements(int row1[], int row2[], int n) {
		int product1 = 1;
		int product2 = 1;

		for (int i = 0; i < n; ++i) {
			product1 *= row1[i];
			product2 *= row2[i];
		}

		return product1 < product2;
	}

	void Sort(int arr[N][N], int n, int m) {
		int min = minMatrixElement(arr, n, m);
		int k = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == min) {
					k++;
				}
			}
		}

		if ((primeMatrixElements(arr, n, m) >= 2) && k >= 2) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n - 1; ++j) {
					if (compositionMatrixElements(arr[j], arr[j + 1], n)) {
						std::swap(arr[j], arr[j + 1]);
					}
				}
			}
		}

	}

}