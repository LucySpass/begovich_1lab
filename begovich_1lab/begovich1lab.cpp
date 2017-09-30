// begovic.lab1.classes.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "libraries.h"
#include "ExhibitionBegovic.h"
#include "DogBegovic.h"

void readFromFile()
{
	DogBegovic dog;
	std::string fileName;
	std::cout << "Write down the name of the file: ";
	std::cin >> fileName;
	std::ofstream file(fileName);
    dog.writeProperties(file, dog);
	file.close();
}

void printoutMenu()
{
	std::cout << "Avaliable commands: " << std::endl;
	std::cout << "-cgp - get properties from console" << std::endl;
	std::cout << "-csp - write properties to console" << std::endl;
	std::cout << "-frp - read properties from file" << std::endl;
	std::cout << "-fwp - write properties to file" << std::endl;
	std::cout << "-exit" << std::endl;
}

int main(int argc, char* argv[])
{
	for(int i=0;i<argc-1;i++)
	{
		std::cout << argv[i+1] << std::endl;
		if(std::strcmp(argv[i + 1], "-help "))
		{
			printoutMenu();
		}
	}

	return 0;
}
