#pragma once
#include "Mammal.h"
class Cat :
	public Mammal
{
public:
	enum breed
	{
		PERSIAN,
		BENGAL,
		SIAMESE,
		BURMESE,
		MIXED
	};
	Cat(std::string name, int age, std::string fur_color, breed c_breed);
	virtual ~Cat();
	void display() override;

	std::string getFileStr() override;
	static void listBreeds();
private:
	breed cat_breed_;
	static const int num_breeds = 5;
	std::string getBreedStr() const;
};

