#include "Contact.h"


Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address address)
{
	set_first_name(first_name);
	set_last_name(last_name);
	set_mobile_number(mobile_number);
	set_email_address(email_address);
	this->address = new Address;
	*this->address = address;
}
void Contact::set_unique_id(int unique_id)
{
	this->unique_id = unique_id;
}
void Contact::set_first_name(std::string first_name)
{
	if(first_name!="")
	this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	if (last_name != "")
	this->last_name = last_name;
}

void Contact::set_mobile_number(std::string mobile_number)
{
	if(mobile_number.length()==11)
	this->mobile_number = mobile_number;
}

void Contact::set_email_address(std::string email_address)
{
	if (email_address != "")
	this->email_address = email_address;
}

void Contact::set_address(Address address)
{

	*this->address = address;
	
}
//getters

std::string Contact::get_first_name()
{
	return first_name;
}

std::string Contact::get_last_name()
{
	return last_name;
}

std::string Contact::get_mobile_number()
{
	return mobile_number;
}

std::string Contact::get_email_address()
{
	return email_address;
}

int Contact::get_unique_id()
{
	return unique_id;
}

Address *Contact::get_address()
{
	return address;
}


bool Contact::equals(Contact &contact)
{
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number && this->email_address == contact.email_address)
	{
		if (this->address->equals(*contact.address) == true)
			return true;
	}
	else
		return false;
}

void Contact::print_contacts()
{
	std::cout << this->unique_id;
	std::cout << ". ";
	std::cout << this->first_name;
	std::cout << '\t';

	std::cout << this->last_name;
	std::cout << '\t';

	std::cout << this->mobile_number;
	std::cout << '\t';

	std::cout << this->email_address;
	std::cout << '\t';
	std::cout << std::endl;
	this->address->print_address();
	std::cout << std::endl << std::endl;
}

std::istream& operator>>(std::istream& input, Contact &contact)
{
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;

	std::cout << "Enter First Name : ";
	input >> first_name;
	contact.set_first_name(first_name);

	std::cout << "Enter Last Name : ";
	input >> last_name;
	contact.set_last_name(last_name);

	std::cout << "Enter Mobile Number : ";
	input >> mobile_number;
	contact.set_mobile_number(mobile_number);

	std::cout << "Enter Email Address : ";
	input >> email_address;
	contact.set_email_address(email_address);
	return input;
}
