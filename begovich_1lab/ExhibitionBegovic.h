#pragma once
#include "libraries.h"
#include "DogBegovic.h"

class ExhibitionBegovic
{
private:
	std::vector <DogBegovic*> m_container;
public:
	ExhibitionBegovic();
	~ExhibitionBegovic();
	void elementAddition();
	void seeContainer();
	void readContainer(std::ifstream &file);
	void writeContainer(std::ostream &file);
	void deleteContainer();
};

