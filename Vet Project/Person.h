#pragma once
#include <string>
#include <vector>
#include "Pet.h"

class Person
{
public:
	Person(std::string name, std::string address);

	std::string getName() const;
	void changeName(std::string new_name);
	void addPet(Pet* pet);
	Pet* getPet(int index);
	int getPetIndex(const std::string& name);
	void removePet(int index);
	void displayPets();
	const std::vector<Pet*>& getPets() const;
	size_t getNoOfPets() const;

	std::string getFileStr() const;

	~Person();
private:
	std::string name_;
	std::string address_;
	std::vector<Pet*> pets_;
};

