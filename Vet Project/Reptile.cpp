#include "Reptile.h"
using namespace std;


Reptile::Reptile(string name, int age, string scale_color) : Pet(name, age), scale_color_(scale_color)
{
}


Reptile::~Reptile()
{
}
