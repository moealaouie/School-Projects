#include "Pet.h"
using namespace std;
Pet::Pet(string name, int age) : name_(name), age_(age)
{
}

Pet::~Pet()
{
}

string Pet::getName() const
{
	return name_;
}

void Pet::changeName(string new_name)
{
	name_ = new_name;
}

void Pet::changeAge(int new_age)
{
	age_ = new_age;
}
