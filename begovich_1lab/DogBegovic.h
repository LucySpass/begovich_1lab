#pragma once
#include "libraries.h"


class DogBegovic: public CObject
{
	DECLARE_SERIAL(DogBegovic);
	int _age;
	CString _nickname, _breed, _owner;
public:
	DogBegovic();
	~DogBegovic();
	void getProperties();
	void seeProperties();
	void readProperties(std::ifstream &file);
	void writeProperties(std::ostream &file);

	//переопределение оператора сравнения для сокращения кода
	friend bool operator==(const DogBegovic& left, const DogBegovic& right)
	{
		return left._age == right._age && left._breed == right._breed
			&& left._nickname == right._nickname && left._owner == right._owner;
	};
};
