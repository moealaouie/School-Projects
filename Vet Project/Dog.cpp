#include "Dog.h"
#include <iostream>
using namespace std;
Dog::Dog(string name, int age, string fur_color, breed d_breed) : Mammal(name, age, fur_color), dog_breed_(d_breed)
{
}

Dog::~Dog()
{
}

void Dog::display()
{
	cout << 
		"Dog\nName: " << name_ << 
		"\nAge: " << age_ << 
		"\nFur color: " << fur_color_ << 
		"\nBreed: " << getBreedStr() << 
		'\n';
}

string Dog::getFileStr()
{
	string str;
	str += "D ";
	str += name_ + ' ';
	str += to_string(age_) + ' ';
	str += fur_color_ + ' ';
	str += to_string(static_cast<int>(dog_breed_));
	return str;
}

string to_string(const Dog::breed d_breed)
{
	switch (d_breed)
	{
	case Dog::LABRADOR:
		return "Labrador";
	case Dog::GERMAN_SHEPHERD:
		return "German Shepherd";
	case Dog::HUSKY:
		return "Husky";
	case Dog::BULLDOG:
		return "Bulldog";
	case Dog::MIXED:
		return "Mixed";
	default:
		return "Unknown";
	}
}

void Dog::listBreeds()
{
	cout << "Dog breeds...\n";
	const unsigned int num_breeds = 5;
	for (unsigned i = 0; i < num_breeds; i++)
	{
		cout << i + 1 << " : " << to_string(static_cast<breed>(i)) << '\n';
	}
}

string Dog::getBreedStr() const
{
	switch (dog_breed_)
	{
	case LABRADOR:
		return "Labrador";
	case GERMAN_SHEPHERD:
		return "German Shepherd";
	case HUSKY:
		return "Husky";
	case BULLDOG:
		return "Bulldog";
	case MIXED:
		return "Mixed";
	default:
		return "Unknown";
	}
}
