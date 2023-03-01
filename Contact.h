#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <string>
    #include<fstream>
#endif // !BASIC_LIB

#include "Address.h"


class Contact {
private:
	int unique_id;
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address *address;

public:

	void operator=(Contact &contact)
	{
		this->first_name = contact.first_name;
		this->last_name = contact.last_name;
		this->mobile_number = contact.mobile_number;
		this->email_address = contact.email_address;
		this->unique_id = contact.unique_id;
		this->address = new Address;
		*this->address = *contact.address;
		
	}

	friend std::istream& operator>>(std::istream& input, Contact &contact);
	bool equals(Contact &contact);
	
	Contact() 
	{
		address = new Address;
	}
	
	//setters
	void set_unique_id(int unique_id);
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_mobile_number(std::string mobile_number);
	void set_email_address(std::string email_address);
	void set_address(Address address);
	//getters

	std::string get_first_name();
	std::string get_last_name();
	std::string get_mobile_number();
	std::string get_email_address();
	int get_unique_id();
	Address *get_address();
	
	void print_contacts();

	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address address);
	~Contact()
	{
		delete address;
	}
};
