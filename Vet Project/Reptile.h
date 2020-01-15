#pragma once
#include "Pet.h"
class Reptile :
	public Pet
{
public:
	Reptile(std::string name, int age, std::string scale_color);
	virtual ~Reptile();
	
protected:
	std::string scale_color_;
};

