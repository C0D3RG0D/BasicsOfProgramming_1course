#include "Class_lab1.hpp"
#include <cmath>


namespace myclass {

	//Конструктор
	Parallelepiped::Parallelepiped(float length, float width, float height) : 
		length_(length), width_(width), height_(height) {};

	//Деструктор
	Parallelepiped::~Parallelepiped() {};

	//Сеттер
	void Parallelepiped::setup(float length, float width, float height) {
		this->length_ = length;
		this->width_ = width;
		this->height_ = height;
	};

	//Геттеры

	float Parallelepiped::getLength() {
		return length_;
	}

	float Parallelepiped::getWidth() {
		return width_;
	}

	float Parallelepiped::getHeight() {
		return height_;
	}

	//Методы вычисления

	float Parallelepiped::calculating_the_area() {
		return 2 * (length_ * width_ + length_ * height_ + width_ * height_);
	}

	float Parallelepiped::calculating_the_volume() {
		return length_ * width_ * height_;
	}

	float Parallelepiped::calculating_the_diagonal() {
		return sqrt(length_ * length_ + width_ * width_ + height_ * height_);
	}

}