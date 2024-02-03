#include <iostream>
#include "Class_lab2.hpp"

namespace myClass {

	Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
		//Выделение памяти
		memory_allocation(rows, cols);

		//Заполнение матрицы
		filling_matrix(rows, cols);
	}

	Matrix::Matrix(const Matrix& other) {
		rows_ = other.rows_;
		cols_ = other.cols_;

		//Выделение памяти
		memory_allocation(rows_, cols_);


		//Копирование элементов матрицы
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				matrix_[i][j] = other.matrix_[i][j];
			}
		}
	}

	Matrix::~Matrix() {
		for (int i = 0; i < rows_; i++)
			delete[] matrix_[i];
		
		delete[] matrix_;
	}

	void Matrix::memory_allocation(int rows, int cols) {
		matrix_ = new int* [rows];

		for (int i = 0; i < rows; i++)
			matrix_[i] = new int[cols];
	}

	void Matrix::Print() {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				std::cout << matrix_[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void Matrix::filling_matrix(int rows, int cols) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix_[i][j] = std::rand();
			}
		}
	}

}