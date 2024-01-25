#pragma once


namespace myclass {

	class Parallelepiped {
	private:

		float length_;
		float width_;
		float height_;

	public:

		//Конструктор
		Parallelepiped(float length, float width, float height);

		//Деструктор
		~Parallelepiped();

		//Сеттер
		void setup(float length, float width, float height);

		//Геттеры

		float getLength();

		float getWidth();

		float getHeight();

		//Методы вычисления

		float calculating_the_area();

		float calculating_the_volume();

		float calculating_the_diagonal();
	};

}