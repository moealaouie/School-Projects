#pragma once
#include "Pet.h"
class Mammal :
	public Pet
{
public:
	Mammal(std::string name, int age, std::string fur_color);
	virtual ~Mammal();
protected:
	std::string fur_color_;
};

