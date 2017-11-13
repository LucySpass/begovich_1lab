#pragma once
#include "libraries.h"

class ExhibitionBegovic
{
private:
	// std::vector <DogBegovic*> m_container;
	std::vector <std::shared_ptr<DogBegovic*>> m_container;
public:
	ExhibitionBegovic();
	~ExhibitionBegovic();
	void elementAddition();
	void labradorAddition();
	void seeContainer();
	void readContainer(std::ifstream &file);
	void writeContainer(std::ostream &file);
	void deleteContainer();
};

