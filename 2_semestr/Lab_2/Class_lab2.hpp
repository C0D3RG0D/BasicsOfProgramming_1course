#pragma once


namespace myClass {

	class Matrix {

	private:
		int** matrix_;
		int rows_;
		int cols_;

	public:

		//Конструктор
		Matrix(int rows, int cols);

		//Конструктор копирования
		Matrix(const Matrix& other);

		//Оператор присваивания копированием
		Matrix& operator=(const Matrix& other) {
			//Проверка на самоприсваение
			if (this == &other)
				return *this;

			//Освобождение памяти
			for (int i = 0; i < rows_; i++)
				delete[] matrix_[i];
			delete[] matrix_;

			rows_ = other.rows_;
			cols_ = other.cols_;

			memory_allocation(rows_, cols_);

			for (int i = 0; i < rows_; i++) {
				for (int j = 0; j < cols_; j++) {
					matrix_[i][j] = other.matrix_[i][j];
				}
			}

			return *this;
		}

		//Деструктор
		~Matrix();

		//Выделение памяти
		void memory_allocation(int rows, int cols);

		//Вывод матрицы на экран
		void Print();

		//Заполнение матрицы
		void filling_matrix(int rows, int cols);

	};

}