#pragma once
#include "DogBegovic.h"


class LabradorBegovic: public DogBegovic
{
	DECLARE_SERIAL(LabradorBegovic)
	int _mass;
	CString _color;
public:
	LabradorBegovic();
	~LabradorBegovic();
	void getProperties();
	void seeProperties();
	void Serialize(CArchive&);
};

