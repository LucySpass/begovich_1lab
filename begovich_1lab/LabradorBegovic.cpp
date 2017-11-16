#include "stdafx.h"
#include "LabradorBegovic.h"

IMPLEMENT_SERIAL(LabradorBegovic, DogBegovic, 2)

LabradorBegovic::LabradorBegovic()
{
}

void LabradorBegovic::getProperties() 
{
	DogBegovic::getProperties();
	std::string temp;

	std::cout << "Mass (kg): ";
	std::cin >> _mass;

	std::cout << "Color: ";
	std::cin >> temp;
	_color = temp.c_str();
}

void LabradorBegovic::seeProperties() 
{
	std::cout << "Mass of the labrdor is " << _mass << std::endl;
	std::cout << "Color of the labrador is " << _color << std::endl;
}

void LabradorBegovic::Serialize(CArchive& archive)
{
	DogBegovic::Serialize(archive);

		if (archive.IsStoring())
			archive << _mass << _color;
		else
			archive >> _mass >> _color;
}

LabradorBegovic::~LabradorBegovic()
{
}
