#pragma once
#include "Reptile.h"
class Lizard :
	public Reptile
{
public:
	enum species
	{
		GECKO,
		CHAMELEON,
		MONITOR,
		IGUANA
	};
	Lizard(std::string name, int age, std::string scale_color, species l_species);
	virtual ~Lizard();
	void display() override;
	std::string getFileStr() override;
	static void listSpecies();
private:
	species lizard_species_;
	std::string getSpeciesStr() const;
};

