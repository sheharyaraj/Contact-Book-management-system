#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include<cstring>
class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	
	/*void operator=(Address &address)
	{
		this->house = address.house;
		this->city = address.city;
		this->country = address.country;
		this->street = address.street;
	}*/
	bool equals(const Address& address);
	void print_address();
	friend std::istream& operator>>(std::istream& input , Address &address);
	

	Address(std::string house, std::string street, std::string city, std::string country);
	Address() 
	{
	}
	//setters
	void set_house(std::string house);
	void set_street(std::string street);
	void set_city(std::string city);
	void set_country(std::string country);

	//getters

	std::string get_house();
	std::string get_street();
	std::string get_city();
	std::string get_country();
};
	
