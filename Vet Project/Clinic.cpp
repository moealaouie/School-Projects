#include "Clinic.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Cat.h"
#include "Lizard.h"
#include "Dog.h"
using namespace std;
Service::Service()
{
	service_name = "";
	cost = 0.0f;
}

Service::Service(string name, float s_cost)
{
	service_name = name;
	cost = s_cost;
}

void Service::display() const
{
	cout << "Service name: " << service_name << " Cost: $" << cost;
}

Appointment::Appointment(Person* per, Pet* s_pet, Service ser)
{
	customer = per;
	pet = s_pet;
	service = ser;
	due = true;
	paid = false;
}

void Appointment::display() const
{
	cout << customer->getName() << ' ' << pet->getName();
	cout << ' ';
	service.display();
	cout << "Appointment ";
	if (due)
	{
		cout << " Due ";
	}
	else
	{
		cout << " Complete ";
	}
	cout << "Status: ";
	if (paid)
	{
		cout << " Paid";
	}
	else
	{
		cout << " Pending";
	}
	cout << '\n';
}

Person* get_customer(vector<Person*>& customer_list, const string& name)
{
	for (Person* person : customer_list)
	{
		if (person->getName() == name)
			return person;-
	}
	return nullptr;
}

Person* select_customer(vector<Person*> & customer_list)
{
	{
		int i = 1;
		for (Person* customer : customer_list)
		{
			cout << i << ' ';
			cout << customer->getName() << '\n';
			cout << '\n';
			i++;
		}
	}

	cout << "Enter customer index: ";
	size_t c_idx;
	cin >> c_idx;

	while (c_idx < 1 || c_idx > customer_list.size())
	{
		cout << "Invalid customer index\n";
		cout << "Re-enter customer index: ";
		cin >> c_idx;
	}

	return customer_list[c_idx - 1];
}

void read_customers(const string & customer_file_name, vector<Person*> & customer_list)
{
	// Read customer data from file
	ifstream inputFile;
	try
	{
		inputFile.open(customer_file_name);
		if (!inputFile.is_open())
		{
			throw ios::failure("Error opening customer file " + customer_file_name);
		}
	}
	catch (const exception & e)
	{
		cerr << e.what() << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line))
	{
		stringstream str_stream(line);
		string	name;
		str_stream >> name;
		name.append(" ");
		string	last_name;
		str_stream >> last_name;
		name.append(last_name);
		string address;
		str_stream.ignore();
		getline(str_stream, address);
		Person* person = new Person{ name, address };
		customer_list.push_back(person);
	}

	inputFile.close();
}

void read_pets(const string & pet_file_name, vector<Person*> & customer_list)
{
	// Read pet data from file
	ifstream inputFile;
	try
	{
		inputFile.open(pet_file_name);
		if (!inputFile.is_open())
		{
			throw ios::failure("Error opening pet file " + pet_file_name);
		}
	}
	catch (const exception & e)
	{
		cerr << e.what() << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line))
	{
		stringstream str_stream(line);

		string	customer_name;
		str_stream >> customer_name;
		customer_name.append(" ");
		string	last_name;
		str_stream >> last_name;
		customer_name.append(last_name);
		string address;

		Person* customer = get_customer(customer_list, customer_name);
		try
		{
			if (!customer)
				throw exception("Error: Pet does not belong to customer in list");
		}
		catch (const exception & e)
		{
			cerr << e.what() << endl;
			inputFile.close();
			exit(1);
		}

		string pet_type;
		string pet_name;
		int age;
		string color;
		int enum_choice;

		str_stream >> pet_type;
		str_stream >> pet_name;
		str_stream >> age;
		str_stream >> color;
		str_stream >> enum_choice;

		Pet* pet;
		if (pet_type == "C")
			pet = new Cat{ pet_name, age, color, static_cast<Cat::breed>(enum_choice) };
		else if (pet_type == "L")
			pet = new Lizard{ pet_name, age, color, static_cast<Lizard::species>(enum_choice) };
		else if (pet_type == "D")
			pet = new Dog{ pet_name, age, color, static_cast<Dog::breed>(enum_choice) };
		else
			pet = nullptr;
		try
		{
			if (!pet)
				throw exception("Error: Unknown pet type in data file");
		}
		catch (const exception & e)
		{
			cerr << e.what() << endl;
			inputFile.close();
			exit(1);
		}
		customer->addPet(pet);
	}
	inputFile.close();
}

void write_customers(const string & customer_file_name, vector<Person*> & customer_list)
{
	// write customer data to file
	ofstream output_file;
	try
	{
		output_file.open(customer_file_name);
		if (!output_file.is_open())
		{
			throw ios::failure("Error opening customer file " + customer_file_name);
		}
	}
	catch (const exception & e)
	{
		cerr << e.what() << endl;
		exit(1);
	}

	size_t idx = 0;
	for (Person* customer : customer_list)
	{
		output_file << customer->getFileStr();
		idx++;
		if (idx < customer_list.size())
		{
			output_file << '\n';
		}
	}

	output_file.close();
}

void write_pets(const string & pet_file_name, vector<Person*> & customer_list)
{
	// write pet data to file
	ofstream outputFile;
	try
	{
		outputFile.open(pet_file_name);
		if (!outputFile.is_open())
		{
			throw ios::failure("Error opening customer file " + pet_file_name);
		}
	}
	catch (const exception & e)
	{
		cerr << e.what() << endl;
		exit(1);
	}

	for (Person* customer : customer_list)
	{
		size_t idx = 0;
		const size_t pet_count = count_pets(customer_list);
		for (Pet* pet : customer->getPets())
		{
			outputFile << customer->getName() << ' ';
			outputFile << pet->getFileStr();
			idx++;
			if (idx < pet_count)
			{
				outputFile << '\n';
			}
		}
	}
	outputFile.close();;
}

void schedule_appointment(vector<Person*> & customers, vector<Service> & services, vector<Appointment*> & appointments)
{
	Person* customer = select_customer(customers);

	cout << "---Pets---\n";
	customer->displayPets();
	cout << '\n';

	cout << "Enter pet index: ";
	size_t p_idx;
	cin >> p_idx;

	while (p_idx < 1 || p_idx > customer->getNoOfPets())
	{
		cout << "Invalid pet index\n";
		cout << "Re-enter pet index: ";
		cin >> p_idx;
	}

	Pet* pet = customer->getPet(p_idx - 1);

	{
		cout << "Available services\n";
		int i = 1;
		for (const Service& service : services)
		{
			cout << i << ' ';
			service.display();
			cout << '\n';
			i++;
		}
	}

	cout << "Enter service index: ";
	size_t s_idx;
	cin >> s_idx;

	while (s_idx < 1 || s_idx > services.size())
	{
		cout << "Invalid service index\n";
		cout << "Re-enter service index: ";
		cin >> s_idx;
	}

	const Service service = services[s_idx - 1];

	Appointment* appointment = new Appointment{ customer, pet, service };
	appointments.push_back(appointment);

	cout << "Appointment made successfully...\n";
}

void add_pets(Person * customer)
{
	char pet_type = ' ';
	string pet_name;
	int age;
	string color;
	int enum_choice;

	bool invalidChoice = true;

	cout << "Enter pet type (enter respective char)\n===\n";
	cout << "C: Cat\n";
	cout << "D: Dog\n";
	cout << "L: Lizard\n===\n";

	while (invalidChoice)
	{
		cout << "Choice: ";
		string input;
		cin >> input;
		pet_type = tolower(input[0]);
		if (pet_type != 'c' && pet_type != 'd' && pet_type != 'l')
		{
			cout << "Invalid pet type, please re-enter ";
		}
		else
		{
			invalidChoice = false;
		}
	}

	cout << "Enter pet name: ";
	cin >> pet_name;

	cout << "Enter pet age: ";
	cin >> age;

	cout << "Enter pet color: ";
	cin >> color;

	Pet* pet = nullptr;
	if (pet_type == 'c')
	{
		Cat::listBreeds();
		cout << "Enter cat breed index: ";
		cin >> enum_choice;
		pet = new Cat{ pet_name, age, color, static_cast<Cat::breed>(enum_choice) };
	}
	else if (pet_type == 'd')
	{
		Dog::listBreeds();
		cout << "Enter dog breed index: ";
		cin >> enum_choice;
		pet = new Dog{ pet_name, age, color, static_cast<Dog::breed>(enum_choice) };
	}
	else if (pet_type == 'l')
	{
		Lizard::listSpecies();
		cout << "Enter lizard species index: ";
		cin >> enum_choice;
		pet = new Lizard{ pet_name, age, color, static_cast<Lizard::species>(enum_choice) };
	}
	customer->addPet(pet);
}

void add_customer(vector<Person*> & customers)
{
	string name;
	string last_name;

	cout << "Enter new customer first name: ";
	cin >> name;

	cout << "Enter new customer last name: ";
	cin >> last_name;

	name += ' ';
	name += last_name;

	cin.clear();

	cout << "Enter new customer address: ";
	string address;
	getline(cin, address);

	Person* person = new Person(name, address);
	cout << "How many pets? ";
	int numPets;
	cin >> numPets;
	for (int i = 0; i < numPets; ++i)
	{
		cout << "Enter data for pet no. " << i + 1 << "...\n";
		add_pets(person);
	}

	customers.push_back(person);
}

void manage_appointments(vector<Appointment*> & appointments)
{
	while (true)
	{
		cout << "---Appointments---\n";
		int idx = 1;
		for (Appointment* appointment : appointments)
		{
			cout << idx << ' ';
			appointment->display();
			idx++;
		}
		cout << "------------------\n";

		cout << "Enter appointment index or enter 0 to go back to main main_menu: ";
		size_t apt_idx;
		cin >> apt_idx;
		if (apt_idx == 0)
			break;

		while (apt_idx < 1 || apt_idx > appointments.size())
		{
			cout << "Invalid appointment index\n";
			cout << "Re-enter appointment index: ";
			cin >> apt_idx;
		}

		Appointment* selected = appointments[apt_idx - 1];

		if (selected->due)
		{
			cout << "Mark as complete? (Y for Yes, other for No) : ";
			string input;
			cin >> input;
			if (tolower(input[0] == 'y'))
			{
				selected->due = false;
				cout << "Appointment no. " << apt_idx << " marked as complete...\n\n";
			}
		}

		if (!selected->due && !selected->paid)
		{
			cout << "Mark as paid? (Y for Yes, other for No) : ";
			string input;
			cin >> input;
			if (tolower(input[0] == 'y'))
			{
				selected->paid = true;
				cout << "Appointment no. " << apt_idx << " marked as paid...\n\n";
			}
		}

		if (!selected->due && selected->paid)
		{
			string input;
			cout << "No available options for this appointment, press enter to continue...\n";
			cin >> input;
		}
	}
}

void edit_customer(vector<Person*> & customers)
{
	Person* customer = select_customer(customers);
	bool editing = true;

	cout << "Pick an option (enter respective char)\n===\n";
	cout << "A: Add a pet\n";
	cout << "R: Remove a pet\n";
	cout << "Other: Go back to main main_menu\n===\n";
	while (editing)
	{
		cout << "Choice: ";
		char input;
		cin >> input;
		input = tolower(input);
		if (input == 'a')
		{
			cout << "Enter data for pet...\n";
			add_pets(customer);
		}
		else if (input == 'r')
		{
			if (customer->getNoOfPets() == 0)
			{
				cout << "Customer has no pets...\n";
				continue;
			}
			cout << "---Pets---\n";
			customer->displayPets();
			cout << '\n';

			cout << "Enter pet index to delete: ";
			size_t p_idx;
			cin >> p_idx;

			while (p_idx < 1 || p_idx > customer->getNoOfPets())
			{
				cout << "Invalid pet index\n";
				cout << "Re-enter pet index: ";
				cin >> p_idx;
			}

			customer->removePet(p_idx - 1);
			cout << "Pet removed...\n";
		}
		else
		{
			editing = false;
		}

	}
}

size_t count_pets(vector<Person*> & customers)
{
	size_t count = 0;
	for (Person* customer : customers)
	{
		count += customer->getNoOfPets();
	}
	return count;
}

void main_menu(vector<Person*> & customers, vector<Service> & services, vector<Appointment*> & appointments)
{
	bool program_run = true;
	while (program_run)
	{
		cout << "Enter number for corresponding option\n";
		cout << "1) Schedule new appointment\n";
		cout << "2) Add customer\n";
		cout << "3) Edit customer\n";
		cout << "4) Manage appointments\n";
		cout << "5) Quit\n\n";
		cout << "Choice: ";

		string input;
		cin >> input;

		try
		{
			const int choice = stoi(input);
			if (choice == 1)
			{
				schedule_appointment(customers, services, appointments);
			}
			else if (choice == 2)
			{
				add_customer(customers);
			}
			else if (choice == 3)
			{
				edit_customer(customers);
			}
			else if (choice == 4)
			{
				manage_appointments(appointments);
			}
			else if (choice == 5)
			{
				program_run = false;
				cout << "Program exiting...\n";
			}
			else
			{
				cout << "Invalid argument, please enter a number between 1 and 5\n";
			}

		}
		catch (exception & e)
		{
			cerr << e.what() << '\n';
			cout << "Invalid argument, please enter a number\n";
		}

	}
}

void clear_customers(vector<Person*> & customer_list)
{
	for (Person* person : customer_list)
	{
		delete person;
	}
}
