#include "stdafx.h"
#include "DogBegovic.h"
#include "libraries.h"
#include "LabradorBegovic.h"

IMPLEMENT_SERIAL(DogBegovic, CObject, 1)

DogBegovic::DogBegovic()
{
}

void DogBegovic::getProperties()
	{
		std::string temp;
		std::cout << "Age: ";
		std::cin >> _age;
		std::cout << "Dog's nick: ";
		std::cin >> temp;
		_nickname = temp.c_str();
		std::cout << "Dog's breed: ";
		std::cin >> temp;
		_breed = temp.c_str();
		std::cout << "Owner's name: ";
		std::cin >> temp;
		_owner = temp.c_str();
	}

void DogBegovic::seeProperties()
	{
		std::cout << "Age: " << _age << std::endl;
		std::cout << "Nick: " << _nickname << std::endl;
		std::cout << "Breed: " << _breed << std::endl;
		std::cout << "Owner: " << _owner << std::endl;
	}

void DogBegovic::Serialize(CArchive& archive) 
{
	if (archive.IsStoring())
		archive << _age << _nickname << _breed << _owner;
	else
		archive >> _age >> _nickname >> _breed >> _owner;
}

DogBegovic::~DogBegovic()
{
}

