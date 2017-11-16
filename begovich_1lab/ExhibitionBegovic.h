#pragma once
#include "libraries.h"
#include "DogBegovic.h"

class ExhibitionBegovic
{
private:
	// std::vector <DogBegovic*> m_container;
	std::vector <std::shared_ptr<DogBegovic>> m_container;
public:
	ExhibitionBegovic();
	~ExhibitionBegovic();
	void elementAddition();
	void labradorAddition();
	void seeContainer();
	void readContainer();
	void writeContainer();
	void deleteContainer();
};

