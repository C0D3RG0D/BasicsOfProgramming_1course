#pragma once
#include <iostream>

const int MAX_DIGITS = 1000;

namespace my_class {

	class BigInt {
	private:

		char number_[MAX_DIGITS];
		int digits_;

	public:
		
		//Constr
		BigInt() : digits_(0) {
			for (int i = 0; i < MAX_DIGITS; i++)
				number_[i] = '0';
		}

		//Copy constr
		BigInt(const BigInt& other) : digits_(other.digits_) {
			for (int i = 0; i < MAX_DIGITS; i++)
				number_[i] = other.number_[i];
		}

		//Assignment by copying
		BigInt& operator=(const BigInt& other) {
			if (this != &other) {
				digits_ = other.digits_;

				for (int i = 0; i < MAX_DIGITS; i++)
					number_[i] = other.number_[i];

			}
			return *this;
		}

		//operator +
		BigInt operator+(const BigInt& other) {
			BigInt sum;
			int score = 0;

			for (int i = 0; i < std::max(digits_, other.digits_) || score; i++) {
				int a = i < digits_ ? number_[i] - '0' : 0;
				int b = i < other.digits_ ? other.number_[i] - '0' : 0;

				int s = score + a + b;
				sum.number_[sum.digits_++] = '0' + s % 10;
				score = s / 10;
			}

			return sum;
		}

		// operator +=
		BigInt& operator+=(const BigInt& other) {
			*this = *this + other;
			return *this;
		}

		//operator *
		BigInt operator*(const BigInt& other) {
			BigInt result;
			BigInt temp;
			int score = 0;

			for (int i = 0; i < digits_; i++) {
				temp.digits_ = 0;
				for (int j = 0; j < i; j++) {
					temp.number_[temp.digits_++] = '0';
				}

				for (int j = 0; j < other.digits_ || score; j++) {
					int a = number_[i] - '0';
					int b = j < other.digits_ ? other.number_[j] - '0' : 0;
					int prod = a * b + score;
					temp.number_[temp.digits_++] = '0' + prod % 10;
					score = prod / 10;
				}

				result += temp;
			}

			return result;
		}

		//operator *=
		BigInt& operator*=(const BigInt& other) {
			*this = *this * other;
			return *this;
		}

		//operator > < == !=

		bool operator<(const BigInt& other) {
			if (digits_ != other.digits_)
				return digits_ < other.digits_;

			for (int i = digits_ - 1; i >= 0; i--) {
				if (number_[i] != other.number_[i])
					return number_[i] < other.number_[i];
			}

			return false;
		}

		bool operator>(const BigInt &other) {
			if (digits_ != other.digits_)
				return digits_ > other.digits_;

			for (int i = digits_ - 1; i >= 0; i--) {
				if (number_[i] != other.number_[i])
					return number_[i] > other.number_[i];
			}

			return false;
		}

		bool operator==(const BigInt& other) {
			return !(*this > other|| *this < other);
		}

		bool operator!=(const BigInt& other) {
			return *this < other || *this > other;
		}


		//operator >> <<

		friend std::istream& operator>>(std::istream& in, BigInt& number) {
			std::string input;
			in >> input;

			number.digits_ = input.size();
			for (int i = 0; i < number.digits_; i++)
				number.number_[i] = input[number.digits_ - i - 1];

			return in;
		}

		friend std::ostream& operator<<(std::ostream& out, const BigInt& number) {

			if (number.digits_ == 0)
				out << "0";
			else {
				
				for (int i = number.digits_ - 1; i >= 0; i--)
					out << number.number_[i];

			}

			return out;
		}
	};

}