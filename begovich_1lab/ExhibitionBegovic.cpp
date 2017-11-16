#include "stdafx.h"
#include "ExhibitionBegovic.h"
#include "libraries.h"
#include "DogBegovic.h"
#include "LabradorBegovic.h"

ExhibitionBegovic::ExhibitionBegovic()
{
}

bool isCFileOpen(CFile &file) {
	return file.m_hFile != CFile::hFileNull;
}

void ExhibitionBegovic::elementAddition()
{
	std::shared_ptr <DogBegovic> dog = std::make_shared<DogBegovic>();
	dog->getProperties();
	m_container.push_back(dog);
	std::cout << "SUCCESS!" << std::endl;
}

void ExhibitionBegovic::labradorAddition() {
	std::shared_ptr <LabradorBegovic> lab = std::make_shared<LabradorBegovic>();
	lab->getProperties();
	m_container.push_back(lab);
	std::cout << "SUCCESS!" << std::endl;
}

void ExhibitionBegovic::seeContainer()
{
	if (m_container.size() > 0) {
		for (int i=0; i < m_container.size(); i++)
			{
				std::cout << "New dog!" << std::endl;
				m_container[i]->seeProperties();
			}
		std::cout << "SUCCESS!" << std::endl;
	}
	else std::cout << "Container is empty!" << std::endl;
}

void ExhibitionBegovic::readContainer()
{
	CFile file;
	file.Open("dogContainer.txt", CFile::modeRead);

	if (isCFileOpen(file)) {
		CArchive archive(&file, CArchive::load);
		int size = 0;
		archive >> size;
		for (int i = 0; i < size; i++)
		{
			DogBegovic* dog;
			archive >> dog;

			std::shared_ptr <DogBegovic> newDog(dog);
			m_container.push_back(newDog);
		}
		archive.Close();
		std::cout << "SUCCESS!" << std::endl;
	}
	else std::cout << "CFile name is wrong!" << std::endl;

	file.Close();
}

void ExhibitionBegovic::writeContainer()
{
	if (m_container.size() > 0) {
		CFile file;
		file.Open("dogContainer.txt", CFile::modeCreate | CFile::modeWrite);

		if (isCFileOpen(file)) {
			CArchive archive(&file, CArchive::store);

			archive << m_container.size();
			for (auto dog : m_container)
				archive << dog.get();

			archive.Close();
			std::cout << "SUCCESS!" << std::endl;
		}
		else std::cout << "CFile name is wrong!" << std::endl;

		file.Close();
	}
	else std::cout << "Container is empty!" << std::endl;
}

void ExhibitionBegovic::deleteContainer()
{
	m_container.clear();
}

ExhibitionBegovic::~ExhibitionBegovic()
{
	if (m_container.size() > 0) {
		deleteContainer();
		std::cout << "SUCCESS!" << std::endl;
	}
}