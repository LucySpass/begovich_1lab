#pragma once
#include "libraries.h"


class DogBegovic: public CObject
{
	DECLARE_SERIAL(DogBegovic);

public:
	int _age;
	CString _nickname, _breed, _owner;

	DogBegovic();
	~DogBegovic();
	void getProperties();
	void seeProperties();
	void Serialize(CArchive& archive);

	//переопределение оператора сравнения для сокращения кода
	friend bool operator==(const DogBegovic& left, const DogBegovic& right)
	{
		return left._age == right._age && left._breed == right._breed
			&& left._nickname == right._nickname && left._owner == right._owner;
	};
};
