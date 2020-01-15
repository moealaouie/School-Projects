#pragma once
#include <string>
// Base virtual pet class
class Pet
{
public:
	Pet(std::string name, int age);
	virtual void display() = 0;	// display pet data
	virtual ~Pet();
	virtual std::string getFileStr() = 0;	// get pet data to write to file
	std::string getName() const;
	void changeName(std::string new_name);
	void changeAge(int new_age);
protected:
	std::string name_;
	int age_;
};

