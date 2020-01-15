#pragma once
#include "Mammal.h"
class Dog :
	public Mammal
{
public:
	enum breed
	{
		LABRADOR,
		GERMAN_SHEPHERD,
		HUSKY,
		BULLDOG,
		MIXED
	};

	Dog(std::string name, int age, std::string fur_color, breed d_breed);
	virtual ~Dog();
	void display() override;
	std::string getFileStr() override;
	static void listBreeds();
private:
	breed dog_breed_;
	std::string getBreedStr() const;
};

