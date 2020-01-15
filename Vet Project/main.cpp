#include "Clinic.h"
using namespace std;
int main()
{
	// delcare filenames
	const string& customer_file_name = "customers.txt";
	const string& pet_file_name = "pets.txt";

	// declare vectors
	vector<Person*> customers;
	vector<Service> services;
	vector<Appointment*> appointments;

	// init services
	services.push_back(Service( "Neutering", 100.0));
	services.push_back(Service("Grooming", 20.0));
	services.push_back(Service("Examination", 40.0));

	// read data
	read_customers(customer_file_name, customers);
	read_pets(pet_file_name, customers);

	// run menu
	main_menu(customers, services, appointments);

	// write data
	write_customers(customer_file_name, customers);
	write_pets(pet_file_name, customers);

	// free memory
	clear_customers(customers);
}
