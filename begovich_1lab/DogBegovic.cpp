#include "stdafx.h"
#include "DogBegovic.h"
#include "libraries.h"


DogBegovic::DogBegovic()
{
}

void DogBegovic::getProperties()
	{
		std::cout << "Age: ";
		std::cin >> _age;
		std::cout << "Dog's nick: ";
		std::cin >> _nickname;
		std::cout << "Dog's breed: ";
		std::cin >> _breed;
		std::cout << "Owner's name: ";
		std::cin >> _owner;
	}
void DogBegovic::seeProperties()
	{
		std::cout << "Age: " << _age << std::endl;
		std::cout << "Nick: " << _nickname << std::endl;
		std::cout << "Breed: " << _breed << std::endl;
		std::cout << "Owner: " << _owner << std::endl;
	}
void DogBegovic::readProperties(std::ifstream &file)
	{
		file >> _age;
		file >> _nickname;
		file >> _breed;
		file >> _owner;
	}
void DogBegovic::writeProperties(std::ostream &file)
	{
		file << _age << "\n";
		file << _nickname << "\n";
		file << _breed << "\n";
		file << _owner << "\n";
	}

DogBegovic::~DogBegovic()
{
}

