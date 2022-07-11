// Lesson 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>

// Exercise 1

class Figure {
protected:
	double width;
	double height;
public:
	Figure(double _width, double _height) : width(_width), height(_height) {}
	virtual double area() = 0;
};
class Parallelogram : public Figure {
public:
	Parallelogram(double width, double height) : Figure(width, height) {}
};
class Circle : public Figure {
public:
	Circle(double radius) : Figure(radius, radius) {}
	double area() override { return 3.1415926 * width * height; }
};
class Rectangle : public Parallelogram {
public:
	Rectangle(double width, double height) : Parallelogram(width, height) {}
	double area() override { return width * height; }
};
class Square : public Parallelogram {
public:
	Square(double width, double height) : Parallelogram(width, height) {}
};
class Rhombus : public Parallelogram {
public:
	Rhombus(double width, double height) : Parallelogram(width, height) {}
	double area() override { return 0.5 * width * height; }
};

// Exercise 2

class Car {
	std::string company;
	std::string model;
public:
	Car(std::string company, std::string model) : company(std::move(company)), model(std::move(model)) {}
	virtual ~Car() {}
};
class PassengerCar : virtual public Car {
public:
	PassengerCar(const std::string &company, const std::string &model) : Car(company, model) {}
};
class Bus : virtual public Car {
public:
	Bus(const std::string &company, const std::string &model) : Car(company, model) {}
};
class Minivan : public Bus, public PassengerCar {
public:
	Minivan(const std::string &company, const std::string &model) :
		Car(company, model), Bus(company, model), PassengerCar(company, model) {}
};

// Exercise 4

enum ECardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
enum ECardValue {
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10
};
class Card {
	ECardSuit suit;
	ECardValue value;
	bool isCoverUp;
public:
	Card(ECardSuit _suit, ECardValue _value) : suit(_suit), value(_value) {
		isCoverUp = true;
	}

	void flip() {
		isCoverUp = !isCoverUp;
	}
	ECardValue getValue() const {
		return value;
	}
};

int main() {
	
	Card c0(SPADES, ACE);
	std::cout << c0.getValue() << std::endl;
}

