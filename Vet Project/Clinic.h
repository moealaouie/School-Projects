#pragma once
#include <string>
#include "Person.h"
// header file containing clinic utility functions

// class for handling service types
struct Service
{
	std::string service_name; // name of service
	double cost;	// cost

	Service();

	Service(std::string name, float s_cost);

	void display() const;  // display data on console
};

// class for handling appointments
struct Appointment
{
	Person* customer; // customer making appointment
	Pet* pet;		// pet for which appointment is required
	Service service;	// reqired service
	bool due;	// has appointment been completed?
	bool paid;	// has payment been made

	Appointment(Person* per, Pet* s_pet, Service ser);

	void display() const; // display data on console
};

Person* get_customer(std::vector<Person*>& customer_list, const std::string& name); // return customer by name from list
Person* select_customer(std::vector<Person*>& customer_list);	// select and return customer from list
void read_customers(const std::string& customer_file_name, std::vector<Person*>& customer_list); // read customers from file
void read_pets(const std::string& pet_file_name, std::vector<Person*>& customer_list);	// read pets from file
void write_customers(const std::string& customer_file_name, std::vector<Person*>& customer_list);	// write customers to file
void write_pets(const std::string& pet_file_name, std::vector<Person*>& customer_list);	// write pets to file
void schedule_appointment(std::vector<Person*>& customers, std::vector<Service>& services, std::vector<Appointment*>& appointments); // schedule an appointment
void add_pets(Person* customer);	// add a pet to a customer
void add_customer(std::vector<Person*>& customers);	// add a customer to the list
void manage_appointments(std::vector<Appointment*>& appointments);	// manange appointments in list
void edit_customer(std::vector<Person*>& customers);	// edit customer in list
size_t count_pets(std::vector<Person*>& customers);	// count total number of pets 
void main_menu(std::vector<Person*>& customers, std::vector<Service>& services, std::vector<Appointment*>& appointments); // display main menu
void clear_customers(std::vector<Person*>& customer_list);	// clear all customer data


