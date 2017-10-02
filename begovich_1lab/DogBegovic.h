#pragma once
#include "libraries.h"
class DogBegovic
{
public:
	int age;
	std::string nickname, breed, owner;
	DogBegovic();
	~DogBegovic();
	void getProperties();
	void seeProperties();
	DogBegovic readProperties(std::ifstream &file);
	void writeProperties(std::ostream &file, DogBegovic dog);

	//переопределение оператора сравнения для сокращения кода
	friend bool operator==(const DogBegovic& left, const DogBegovic& right)
	{
		return left.age == right.age && left.breed == right.breed
			&& left.nickname == right.nickname && left.owner == right.owner;
	};
};
