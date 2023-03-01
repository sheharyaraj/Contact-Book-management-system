#include "Address.h"



Address::Address(std::string house, std::string street, std::string city, std::string country)
{
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}



//setters
void Address::set_house(std::string house)
{
	this->house = house;
}

void Address::set_street(std::string street)
{
	this->street = street;
}

void Address::set_city(std::string city)
{
	this->city = city;
}

void Address::set_country(std::string country)
{
	this->country = country;
}

//getters
std::string Address::get_house()
{
	return house;
}

std::string Address::get_street()
{
	return street;
}

std::string Address::get_city()
{
	return city;
}

std::string Address::get_country()
{
	return country;
}



bool Address::equals(const Address& address)
{
	

	if (this->house != address.house && this->street != street && this->city != city && this->country != country)
		return false;
	else
		return true;
}


void Address::print_address()
{
	

	std::cout << this->house << ", " << this->street << ", " << this->city << ", " << this->country;
}

std::istream &operator >>(std::istream& input, Address& address)
{
	std::cout << "Enter House : ";
	input >> address.house;
	std::cout << "Enter Street : ";
    getline(input >> std::ws, address.street);
    std::cout << "Enter City : ";
	input >> address.city;
	std::cout << "Enter Country : ";
	input >> address.country;
	return input;
}
