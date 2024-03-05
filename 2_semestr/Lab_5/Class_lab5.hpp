#pragma once
#include <iostream>

namespace my_class {

	template <typename T, size_t N, size_t M>
	class Matrix {
	private:
		T data_[N][M];

		void copy(const Matrix& other) {
			for (size_t i = 0; i < N; i++) {
				for (size_t j = 0; j < M; j++) {
					data_[i][j] = other.data_[i][j];
				}
			}
		}

	public:

		Matrix() = default;

		//Конструктор копирования
		Matrix(const Matrix& other) {
			copy(other);
		}

		//Присваивание копированием
		Matrix& operator=(const Matrix& other) {
			copy(other);

			return *this;
		}

		//Оператор ввода и вывода
		friend std::istream& operator>>(std::istream& in, Matrix<T, N, M>& matrix) {

			for (size_t i = 0; i < N; i++) {
				for (size_t j = 0; j < M; j++) {
					in >> matrix(i, j);
				}
			}

			return in;
		}

		friend std::ostream& operator<<(std::ostream& out, Matrix<T, N, M>& matrix) {
			for (size_t i = 0; i < N; i++) {
				for (size_t j = 0; j < M; j++) {
					out << matrix.data_[i][j] << " ";
				}
				out << std::endl;
			}

			return out;
		}

		//Операторы + += * *=

		Matrix& operator+=(Matrix& other) {
			for (size_t i = 0; i < N; i++) {
				for (size_t j = 0; j < M; j++) {
					data_[i][j] += other(i, j);
				}
			}

			return *this;
		}

		Matrix& operator+(Matrix& other) {
			Matrix temp(*this);
			temp += other;
			return temp;
		}

		Matrix& operator*=(T other) {
			for (size_t i = 0; i < N; i++) {
				for (size_t j = 0; j < M; j++) {
					data_[i][j] *= other;
				}
			}

			return *this;
		}

		template<size_t H>
		Matrix<T, N, H> operator*(Matrix<T, M, H>& other) {
			Matrix<T, N, H> result;

			for (size_t i = 0; i < H; i++) {
				for (size_t j = 0; j < N; j++) {
					T temp{};

					for (size_t k = 0; k < M; k++) {
						temp += data_[j][k] * other(k, i);
					}

					result(j, i) = temp;
				}
			}

			return result;
		}

		Matrix& operator*(T& other) {
			Matrix temp(*this);
			temp *= other;
			return temp;
		}

		//Оператор ++

		Matrix& operator++() {
			for (size_t i = 0; i < N; i++) {
				for (size_t j = 0; j < M; j++) {
					++data_[i][j];
				}
			}

			return *this;
		}

		//Оператор ()

		T& operator()(size_t row, size_t column) {
			return data_[row][column];
		}

		//Вычисление определителя

		int determinant() {
			if (N != M || N > 3 || M > 3)
			{
				std::cerr << "Некоректная матрица!!!" << std::endl;
				throw;
			}
			if (N == 1) return data_[0][0];

			if (N == 2)
			{
				return (data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0]);

			}
			if (N == 3)
			{
				return data_[0][0] * data_[1][1] * data_[2][2] +
					data_[0][1] * data_[1][2] * data_[2][0] +
					data_[1][0] * data_[2][1] * data_[0][2] -
					data_[0][2] * data_[1][1] * data_[2][0] -
					data_[0][1] * data_[1][0] * data_[2][2] -
					data_[0][0] * data_[1][2] * data_[2][1];
			}
			return 0;
		}

	};

}
