#pragma once
#include "Address.h"
#include "Contact.h"
#include<fstream>
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class ContactsBook {
private:
	Contact* contacts_list;// array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
							// stored at this count plus 1 index

public:

	void operator=(ContactsBook &CB)
	{
		this->size_of_contacts = CB.size_of_contacts;
		this->contacts_count = CB.contacts_count;

		this->contacts_list = new Contact[size_of_contacts];
		for (int i = 0; i < contacts_count; i++)
		{
			this->contacts_list[i] = CB.contacts_list[i];
		}
	}
	ContactsBook()
	{
		this->size_of_contacts = 0;
		this->contacts_count = 0;
		contacts_list = NULL;
	}

	void add_contact(Contact& contact);
	int total_contacts();

	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(Address address);
	Contact *get_contact();
	ContactsBook(int size_of_list);
	void Delete_Contact(int index);
	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
							 // Duplicate means exact equal, this means if
	
	/* 
	*  This function loads contacts from the given file (see details in ContactsBook.cpp)
	*/
	ContactsBook *load_from_file(std::string file_name);
	void save_to_file(std::string file_name);

	void print_contacts_list();

	//advance search

	void advance_search(std::string);
	void advance_search_attribues(std::string, std::string,int &count);
	void Display_By_Unique_Id(int unique_id[]);
	~ContactsBook()
	{
		delete[]contacts_list;
	}
	private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, std::string choice);
	
};
