#include "Lizard.h"
#include <iostream>

using namespace std;
Lizard::Lizard(string name, int age, string scale_color, species l_species) : Reptile(name, age, scale_color), lizard_species_(l_species)
{
}

void Lizard::display()
{
	cout <<
		"\nName: " << name_ <<
		"\nAge: " << age_ <<
		"\nScale color: " << scale_color_ <<
		"\nSpecies: " << getSpeciesStr() <<
		'\n';
}

string Lizard::getFileStr()
{
	string str;
	str += "L ";
	str += name_ + ' ';
	str += to_string(age_) + ' ';
	str += scale_color_ + ' ';
	str += to_string(static_cast<int>(lizard_species_));
	return str;
}

string to_string(const Lizard::species l_species)
{
	switch (l_species)
	{
	case Lizard::GECKO: return "Gecko";
	case Lizard::CHAMELEON: return "Chameleon";
	case Lizard::MONITOR: return "Monitor";
	case Lizard::IGUANA: return "Iguana";
	default: return "Unknown";
	}
}

void Lizard::listSpecies()
{
	cout << "breeds...\n";
	const unsigned int num_breeds = 4;
	for (unsigned i = 0; i < num_breeds; i++)
	{
		cout << i + 1 << " : " << to_string(static_cast<species>(i)) << '\n';
	}
}

string Lizard::getSpeciesStr() const
{
	switch (lizard_species_)
	{
	case GECKO: return "Gecko";
	case CHAMELEON: return "Chameleon";
	case MONITOR: return "Monitor";
	case IGUANA: return "Iguana";
	default: return "Unknown";
	}
}

Lizard::~Lizard()
{
}
