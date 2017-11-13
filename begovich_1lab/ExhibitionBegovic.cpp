#include "stdafx.h"
#include "ExhibitionBegovic.h"
#include "libraries.h"
#include "DogBegovic.h"
#include "LabradorBegovic.h"

ExhibitionBegovic::ExhibitionBegovic()
{
	std::shared_ptr <LabradorBegovic> lab = std::make_shared<LabradorBegovic>();

	m_container.push_back(lab);
}

void ExhibitionBegovic::elementAddition()
{
	std::shared_ptr <DogBegovic> dog = std::make_shared<DogBegovic>();
	dog->getProperties();
	m_container.push_back(dog);
}

void ExhibitionBegovic::labradorAddition() {

}

void ExhibitionBegovic::seeContainer()
{
	for (int i=0; i < m_container.size(); i++)
	{
		std::cout << "New dog!" << std::endl;
		m_container[i]->seeProperties();
	}
}

void ExhibitionBegovic::readContainer(std::ifstream &file)
{
	DogBegovic* dog = new DogBegovic;

	std::string flag;
	
	while(1)
	{
		file >> flag;
			if (file.eof())
				break;
			dog->readProperties(file);
			m_container.push_back(dog);
			flag = "";
	}
}

void ExhibitionBegovic::writeContainer(std::ostream &file)
{
	for(auto n : m_container)
	{
		file << 'd' << "\n";
		n->writeProperties(file);
	}
}

void ExhibitionBegovic::deleteContainer()
{
	for(auto it = m_container.begin(); it != m_container.end(); it++)
		delete *it;
	m_container.clear();
}

ExhibitionBegovic::~ExhibitionBegovic()
{
	if (m_container.size() > 0)
		deleteContainer();

}