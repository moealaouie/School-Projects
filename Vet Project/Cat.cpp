#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat(string name, int age, string fur_color, breed c_breed) : Mammal(name, age, fur_color), cat_breed_(c_breed)
{
}

Cat::~Cat()
{
}

void Cat::display()
{
	cout <<
		"Cat\nName: " << name_ <<
		"\nAge: " << age_ <<
		"\nFur color: " << fur_color_ <<
		"\nBreed: " << getBreedStr() <<
		'\n';
}

string Cat::getFileStr()
{
	string str;
	str += "C ";
	str += name_ + ' ';
	str += to_string(age_) + ' ';
	str += fur_color_ + ' ';
	str += to_string(static_cast<int>(cat_breed_));
	return str;
}

string to_string(const Cat::breed c_breed) 
{
	switch (c_breed)
	{
	case Cat::PERSIAN: return "Persian";
	case Cat::BENGAL: return "Bengal";
	case Cat::SIAMESE: return "Siamese";
	case Cat::BURMESE: return "Burmese";
	case Cat::MIXED: return "Mixed";
	default:
		return "Unknown";
	}
}

void Cat::listBreeds()
{
	cout << "Cat breeds...\n";
	const unsigned int num_breeds = 5;
	for(unsigned i = 0; i < num_breeds; i++)
	{
		cout << i + 1 << " : " << to_string(static_cast<breed>(i)) << '\n';
	}
}


string Cat::getBreedStr() const
{
	switch (cat_breed_)
	{
	case PERSIAN: return "Persian";
	case BENGAL: return "Bengal";
	case SIAMESE: return "Siamese";
	case BURMESE: return "Burmese";
	case MIXED: return "Mixed";
	default:
		return "Unknown";
	}
}
