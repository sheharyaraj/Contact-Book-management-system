#include "ContactsBook.h"

void ContactsBook::add_contact(Contact& contact)
{
	if (full() == true)
	{
		resize_list();
		this->contacts_list[contacts_count] = contact;
		this->contacts_count++;
	}
	else
	{
		this->contacts_list[contacts_count] = contact;
		this->contacts_count++;
	}


	
}

int ContactsBook::total_contacts()
{
	
	return contacts_count;
}

bool ContactsBook::full()
{
	if (this->size_of_contacts == this->contacts_count)
		return true;
	else
		return false;
}

void ContactsBook::resize_list()
{
	Contact *temp = new Contact[size_of_contacts * 2];
	for (int i = 0; i < size_of_contacts; i++)
	{
		temp[i] = contacts_list[i];
	}

	this->contacts_list = new Contact[size_of_contacts * 2];
	for(int i=0;i<size_of_contacts;i++)
	contacts_list[i] = temp[i];
	delete[]temp;
	this->size_of_contacts = this->size_of_contacts * 2;
}

Contact *ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	

	for (int i = 0; i < contacts_count; i++)
	{
		if (first_name == contacts_list[i].get_first_name() && last_name == contacts_list[i].get_last_name())
			return &contacts_list[i];
	}

	return nullptr;
}

Contact *ContactsBook::search_contact(std::string phone)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (phone == contacts_list[i].get_mobile_number())
			return &contacts_list[i];
	}
	return nullptr;
}

Contact* ContactsBook::search_contact(Address address)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (address.get_house() == contacts_list[i].get_address()->get_house() && address.get_street() == contacts_list[i].get_address()->get_street()
			&& address.get_city() == contacts_list[i].get_address()->get_city() && address.get_country() == contacts_list[i].get_address()->get_country())
			return &contacts_list[i];
	}

	return nullptr;
}

ContactsBook::ContactsBook(int size_of_list)
{
	this->contacts_count = 0;
	this->size_of_contacts = size_of_list;
	this->contacts_list = new Contact[size_of_list];
}

void ContactsBook::print_contacts_sorted(std::string choice)
{
	Contact *copy = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		copy[i] = contacts_list[i];
	}
	sort_contacts_list(copy, choice);
	
}

void ContactsBook::sort_contacts_list(Contact contacts_list[], std::string choice)
{
	/*std::string temp = "\0";*/

	Contact temp;
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = 1; j < contacts_count; j++)
		{
			if ((contacts_list[j].get_first_name()[0] < contacts_list[j - 1].get_first_name()[0] && choice == "First Name") || (contacts_list[j].get_last_name()[0] < contacts_list[j - 1].get_last_name()[0] && choice == "Last Name"))
			{

				temp = contacts_list[j];
				contacts_list[j] = contacts_list[j - 1];
				contacts_list[j - 1] = temp;
			}
		}
	}


	//printing
	std::cout << "\n\nAfter Sorting\n\n";
	for (int i = 0; i < this->contacts_count; i++)
	{
		contacts_list[i].print_contacts();
	}
}

void ContactsBook::merge_duplicates()
{
	bool check = false;
	int n = this->contacts_count;
	
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			Contact temp;
			temp = contacts_list[j];
			if (this->contacts_list[i].equals(temp) == true)
			{
				check = true;
				for (k = j; k < n-1; k++)
				{
					this->contacts_list[k] = this->contacts_list[k + 1];
				}
				n--;
				this->size_of_contacts--;
				this->contacts_count--;
				j--;
			}
		}
	}
	if (check == false)
	{
		std::cout << "\n\nNo Duplicates Found";
		return;
	}
	ContactsBook::print_contacts_list();
}


ContactsBook *ContactsBook::load_from_file(std::string file_name)
{
	int unique_id;
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	//address
	std::string house;
	std::string street;
	std::string city;
	std::string country;

	std::string space;
	int size_of_contacts;
	int contacts_count;
	std::fstream myfile;

	myfile.open(file_name, std::ios::in);
	
	myfile >> size_of_contacts;
	myfile >> contacts_count;

	ContactsBook *contactbook=new ContactsBook(size_of_contacts);
	

	
	
	
	
	for (int i = 0; i < contacts_count; i++)
	{
		myfile >> unique_id;
		getline(myfile, space, ' ');
		getline(myfile, first_name, ',');

		getline(myfile, space, ' ');
		getline(myfile, last_name, ',');

		getline(myfile, space, ' ');
		getline(myfile, mobile_number, ',');

		getline(myfile, space, ' ');
		getline(myfile, email_address);

		//address

		getline(myfile, house, ',');

		getline(myfile, space, ' ');
		getline(myfile, street, ',');

		getline(myfile, space, ' ');
		getline(myfile, city, ',');

		getline(myfile, space, ' ');
		getline(myfile, country);

		Address address(house, street, city, country);
		Contact contact(first_name,last_name,mobile_number,email_address,address);
		contact.set_unique_id(unique_id);
		contactbook->add_contact(contact);
		
	}

	return contactbook;
}


void ContactsBook::save_to_file(std::string file_name)
{

	std::fstream myfile;
	
	myfile.open(file_name, std::ios::out);

	myfile << this->size_of_contacts;
	myfile << std::endl;
	myfile << this->contacts_count<<std::endl;
	for (int i = 0; i < this->contacts_count; i++)
	{
		myfile<< i + 1 << ". " << contacts_list[i].get_first_name();
		myfile << ", ";

		myfile << contacts_list[i].get_last_name();
		myfile << ", ";

		myfile << contacts_list[i].get_mobile_number();
		myfile << ", ";

		myfile << contacts_list[i].get_email_address();

		myfile << std::endl;
		
		//address
		myfile << contacts_list[i].get_address()->get_house();
		myfile<< ", " << contacts_list[i].get_address()->get_street();
		myfile<< ", " << contacts_list[i].get_address()->get_city() << ", " << contacts_list[i].get_address()->get_country();
		myfile << std::endl << std::endl;
	}
	
	myfile.close();
}

void ContactsBook::print_contacts_list()
{
	std::cout << "                                Here is the List of Total Contacts" << std::endl << std::endl;
	for (int i = 0; i < this->contacts_count; i++)
	{
		std::cout << contacts_list[i].get_unique_id() << ". " << contacts_list[i].get_first_name();
		std::cout << '\t';

		std::cout << contacts_list[i].get_last_name();
		std::cout << '\t';

		std::cout << contacts_list[i].get_mobile_number();
		std::cout << '\t';

		std::cout << contacts_list[i].get_email_address();
		std::cout << '\t';
		std::cout << std::endl;
		contacts_list[i].get_address()->print_address();
		std::cout << std::endl << std::endl;
	}
}

void ContactsBook::advance_search(std::string word)
{
	int count = 0;
	bool check = false;
	for (int i = 0; i < contacts_count; i++)
	{
		advance_search_attribues(word, contacts_list[i].get_first_name(), count);
		advance_search_attribues(word, contacts_list[i].get_last_name(), count);
		advance_search_attribues(word, contacts_list[i].get_mobile_number(), count);
		advance_search_attribues(word, contacts_list[i].get_email_address(), count);
		//address

		advance_search_attribues(word, contacts_list[i].get_address()->get_house(), count);
		advance_search_attribues(word, contacts_list[i].get_address()->get_street(), count);
		advance_search_attribues(word, contacts_list[i].get_address()->get_city(), count);
		advance_search_attribues(word, contacts_list[i].get_address()->get_country(), count);
		

		if (count >= word.length())
		{
			std::cout << i + 1 << ". ";
			contacts_list[i].print_contacts();
		}
			
		if (count > 0)
			check = true;
		count = 0;
	}
	if (check == false)
		std::cout << "No Results Found";
}
void ContactsBook::advance_search_attribues(std::string word, std::string attribute,int &count)
{
	for (int i = 0; i < attribute.length(); i++)
	{
		if (word[count] == attribute[i] || word[count] == attribute[i] + 32 || word[count] == attribute[i] - 32 && word[count] < 48 && word[count] > 57)
			count++;
		else if (word[count] == attribute[i])
			count++;
	}
}



Contact *ContactsBook::get_contact()
{
	return contacts_list;
}

void ContactsBook::Delete_Contact(int index)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (index - 1 == i)
		{
			for (int j = i; j < contacts_count - 1; j++)
			{
				contacts_list[j] = contacts_list[j + 1];
			}
		}
	}

	Contact* temp = new Contact[contacts_count];

	for (int i = 0; i < contacts_count - 1; i++)
	{
		temp[i] = contacts_list[i];
	}
	
	contacts_count--;

	for (int i = 0; i < contacts_count; i++)
	{
		contacts_list[i] = temp[i];
	}

}

void ContactsBook::Display_By_Unique_Id(int unique_id[])
{
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = 0; j < contacts_count; j++)
		{
			if (unique_id[i] == contacts_list[j].get_unique_id())
			{
				contacts_list[j].print_contacts();
			}
		}
		
	}
}