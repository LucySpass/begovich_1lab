#include "stdafx.h"
#include "ExhibitionBegovic.h"
#include "libraries.h"


ExhibitionBegovic::ExhibitionBegovic()
{
}

void ExhibitionBegovic::elementAddition()
{
	DogBegovic dog;
	dog.getProperties();
	m_container.push_back(&dog);
}

void ExhibitionBegovic::seeContainer()
{
	for (int i=0; i<m_container.size(); i++)
	{
		std::cout << "New dog!" << std::endl;
		m_container[i]->seeProperties();
	}
}

void ExhibitionBegovic::readContainer(std::ifstream &file)
{
	DogBegovic dog;

	std::string flag;
	file >> flag;

	while(!file.eof())
	{
		if (flag == "d")
		{
			dog.readProperties(file);
			m_container.push_back(&dog);
			flag = "";
		}
	}
}

void ExhibitionBegovic::writeContainer(std::ostream &file)
{
	DogBegovic dog;
	for(int i=0; i<m_container.size(); i++)
	{
		file << 'd' << "\n";
		dog.writeProperties(file, *m_container[i]);
	}
}

void ExhibitionBegovic::deleteContainer()
{
	for(auto it = m_container.begin(); it != m_container.end(); it++)
		delete *it;
}

ExhibitionBegovic::~ExhibitionBegovic()
{
}