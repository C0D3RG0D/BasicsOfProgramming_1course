#include <iostream>
#include <cstring>


namespace my_class {

	class String {

	private:
		char* data_;
		size_t len_;

	public:

		//Конструктор
		String() : data_(nullptr), len_(0) {}

		String(const char* str) {
			len_ = strlen(str);
			data_ = new char[len_ + 1];
			strcpy(data_, str);
		}

		//Конструктор копирования
		String(const String& other) : len_(other.len_) {
			data_ = new char[len_ + 1];
			strcpy(data_, other.data_);
		}

		//Деструктор
		~String() {
			delete[] data_;
		}

		//Присваивание копированием
		String& operator=(const String& other) {
			if (this == &other)
				return *this;

			delete[] data_;
			len_ = other.len_;
			data_ = new char[len_ + 1];
			strcpy(data_, other.data_);

		}

		//Операторы + и +=
		String operator+(const String& other) {
			const size_t NewLen = len_ + other.len_;
			char* NewData = new char[NewLen + 1];
			strcpy(NewData, data_);
			strcat(NewData, other.data_);
			return String(NewData);
		}

		String& operator+=(const String& other) {
			*this = *this + other;
			return *this;
		}

		//Оператор []
		char& operator[](size_t index) {
			return data_[index];
		}

		//Операторы > < ==
		bool operator>(const String& other) const {
			return strcmp(data_, other.data_) > 0;
		}

		bool operator<(const String& other) const {
			return strcmp(data_, other.data_) < 0;
		}

		bool operator==(const String& other) const {
			return strcmp(data_, other.data_) == 0;
		}

		//Операторы ввода и вывода в поток
		friend std::ostream& operator<<(std::ostream& os, const String& str);

		friend std::istream& operator>>(std::istream& is, String& str);

		int find(char c) {
			for (size_t i = 0; i < len_; i++) {
				if (data_[i] == c)
					return i;
			}

			return -1;
		}

		size_t length() const {
			return len_;
		}

		const char* c_str() const {
			return data_;
		}

		char& at(size_t index) {
			if ( index < 0 || index >= len_)
				throw std::out_of_range("Выход за пределы строки!");

			return data_[index];
		}

	};

	std::ostream& operator<<(std::ostream& os, const String& str) {
		os << str.data_;
		return os;
	}

	std::istream& operator>>(std::istream& is, String& str) {
		char buffer[1000];
		is >> buffer;
		str = String(buffer);
		return is;
	}



}



int main() {

	setlocale(LC_ALL, "Rus");

	my_class::String s1 = "Hello";
	my_class::String s2("world");

	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;

	my_class::String s3 = s1 + s2;

	std::cout << "s3 = s1 + s2: " << s3 << std::endl;

	s1 += s2;

	std::cout << "s1 += s2: " << s1 << std::endl;

	std::cout << "s3[0]: " << s3[0] << std::endl;

	s3[0] = 'h';

	std::cout << "s3[0] = h: " << s3[0] << std::endl;

	std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
	std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
	std::cout << "s1 == s1: " << (s1 == s1) << std::endl;


	std::cout << "Индекс симола w в s2: " << s2.find('w') << std::endl;
	std::cout << "Длинна строки s2: " << s2.length() << std::endl;
	std::cout << "c_str вызванная от s2: " << s2.c_str() << std::endl;


	try {
		char c = s3.at(10);
		std::cout << "Символ с индексом 10 в s3: " << c << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "Исключение: " << e.what() << std::endl;
	}


	return 0;
}