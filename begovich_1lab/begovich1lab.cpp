// begovic.lab1.classes.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "libraries.h"
#include "ExhibitionBegovic.h"

std::string enterFileName() {
	std::string fileName;
	std::cout << "Write down the name of the file: ";
	std::cin >> fileName;
	return fileName;
}

void printoutMenu()
{
	std::cout << "Avaliable commands: " << std::endl;
	std::cout << "-help - see menu" << std::endl;
	std::cout << "-add - add element to container" << std::endl;
	std::cout << "-csc - consoleSeeContainer - write container in console" << std::endl;
	std::cout << "-frc - FileReadConainer - read container from file" << std::endl;
	std::cout << "-fwc - FileWriteContainer - write container to file" << std::endl;
	std::cout << "-del - container deletion" << std::endl;
	std::cout << "-exit" << std::endl;
}

void checkForInput(std::string input, ExhibitionBegovic* container)
{
	if (input == "-add")
	{
		container->elementAddition();
	}
	else if(input == "-csc")
	{
		container->seeContainer();
	}
	else if (input == "-help")
	{
		printoutMenu();
	}
	else if (input == "-frc")
	{
		std::string fileName = enterFileName();
		std::ifstream inputStream = std::ifstream(fileName);
		
		if(inputStream.is_open())
		{
			container->readContainer(inputStream);
		}
		else
		{
			std::cout << "Wrong file name.";
		}

		inputStream.close();

	}
	else if (input == "-fwc")
	{
		std::string fileName = enterFileName();
		std::ofstream file(fileName);

		container->writeContainer(file);

		file.close();
	}
	else if (input == "-del")
	{
		container->deleteContainer();
	}
}

int main()
{
	ExhibitionBegovic container;
	std::string input;
	printoutMenu();
	while(1)
	{
		std::cout << "Your command: ";
		std::cin >> input;
		if (input == "-help")
			printoutMenu();
		if(input == "-exit")
			return 0;
		checkForInput(input, &container);
	}
}
