#include "stdafx.h"
#include "DogBegovic.h"
#include "libraries.h"


DogBegovic::DogBegovic()
{
}

void DogBegovic::getProperties()
	{
		std::cout << "Age: ";
		std::cin >> age;
		std::cout << "Dog's nick: ";
		std::cin >> nickname;
		std::cout << "Dog's breed: ";
		std::cin >> breed;
		std::cout << "Owner's name: ";
		std::cin >> owner;
	}
void DogBegovic::seeProperties()
	{
		std::cout << "Age: " << age << " Nick: " << nickname << " Breed: " << breed << " Owner: " << owner << std::endl;

	}
DogBegovic DogBegovic::readProperties(std::ifstream &file)
	{
		DogBegovic dogFromFile;
		file >> dogFromFile.age;
		file >> dogFromFile.nickname;
		file >> dogFromFile.breed;
		file >> dogFromFile.owner;
		return dogFromFile;
	}
void DogBegovic::writeProperties(std::ostream &file, DogBegovic dog)
	{
		file << dog.age << std::endl;
		file << dog.nickname << std::endl;
		file << dog.breed << std::endl;
		file << dog.owner << std::endl;
	}

DogBegovic::~DogBegovic()
{
}
