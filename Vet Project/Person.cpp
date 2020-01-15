#include "Person.h"
#include <iostream>

using namespace std;
Person::Person(string name, string address) : name_(name), address_(address)
{
}

string Person::getName() const
{
	return name_;
}

void Person::changeName(string new_name)
{
	name_ = new_name;
}

void Person::addPet(Pet* pet)
{
	pets_.push_back(pet);
}

Pet* Person::getPet(int index)
{
	return pets_[index];
}

int Person::getPetIndex(const string& name)
{
	int idx = 0;
	for (Pet* p : pets_)
	{
		if (p->getName() == name)
		{
			return idx;
		}
		idx++;
	}
	return -1;
}

void Person::removePet(int index)
{
	pets_.erase(pets_.begin() + index);
}

void Person::displayPets()
{
	int i = 1;
	for (Pet* p : pets_)
	{
		cout << '(' << i << ") ";
		p->display();
		cout << "----------\n";
		i++;
	}
}

const vector<Pet*>& Person::getPets() const
{
	return pets_;
}

size_t Person::getNoOfPets() const
{
	return pets_.size();
}

string Person::getFileStr() const
{
	string str;
	str += name_ + ' ';
	str += address_;
	return str;
}

Person::~Person()
{
	for (Pet* p : pets_)
	{
		delete p;
	}
	pets_.clear();
}
