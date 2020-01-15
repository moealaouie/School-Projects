#include "Mammal.h"
using namespace std;

Mammal::Mammal(string name, int age, string fur_color) : Pet(name, age), fur_color_(fur_color)
{

}

Mammal::~Mammal()
{
}
