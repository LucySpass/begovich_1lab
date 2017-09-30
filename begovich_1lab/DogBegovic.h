#pragma once
#include "libraries.h"
class DogBegovic
{
	int age;
	std::string nickname, breed, owner;
public:
	DogBegovic();
	~DogBegovic();
	void getProperties();
	void seeProperties();
	DogBegovic readProperties(std::ifstream &file);
	void writeProperties(std::ostream &file, DogBegovic dog);
};

