/*
*   Include all the needed headers here to run the scenarios
*/
#pragma once
#include"Group.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cstring>
#include"Contact.h"
#include"Address.h"
#include"GroupContacts.h"
#include"ContactsBook.h"
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#pragma warning(disable : 4996)
#include"HistoryObjects.h"
#include"HistoryList.h"



void Create_Contacts();
void Print_Menu();
void Search_Menu();
void Enter_Address_Data(std::string& house, std::string& street, std::string& city, std::string& country,HistoryList&history);
bool No_contacts_added(bool forward);
void Back_To_Main();
void Display_Group();
void Manage_Contacts();
int main()
{
	int i = 0;
	int size_of_contacts = 0;
	bool check = false;
	bool forward = false;
	int increment = 0;

	HistoryList history;

	//contact
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	ContactsBook copycontactbook;
	GroupContacts groupcontacts;
	Group group;

	//address
	int unique_id = 1;
	std::string house;
	std::string street;
	std::string city;
	std::string country;
	char anykey;
	int press = 0;
	std::cout << "\n                                     Welcome To Contact List\n\n";
	std::cout << "Press Any Key For Menu : ";
	std::cin >> anykey;

	system("cls");
	do
	{
		Print_Menu();
		std::cin >> press;
		std::cout << std::endl << std::endl;



		switch (press)
		{
		case 1:
		{
			int choice = 0;

			if (check == false)
			{
				std::cout << "Enter The Number Of Contacts You Want To Enter : ";
				std::cin >> size_of_contacts;
			}
			else
				size_of_contacts = size_of_contacts * 2;

			ContactsBook contactbook(size_of_contacts);


			//contact book
			for (i; i < size_of_contacts; i++)
			{
				std::cout << "\n\nEnter " << i + 1 << " Contact\n\n";
				Contact contact;

				std::cin >> contact;

				contact.set_unique_id(unique_id);
				unique_id++;
				Address address;
				std::cin >> address;
				contact.set_address(address);


				if (check == false)
					contactbook.add_contact(contact);
				else
					copycontactbook.add_contact(contact);



				if (size_of_contacts > 1 && size_of_contacts != i + 1)
				{
					std::cout << "\n\n1. Return To Main Menu\n\n";
					std::cout << "2. Press Any Key To Continue\n\n";
					std::cout << "Enter The Choice : ";
					std::cin >> choice;
					if (choice == 1)
					{
						i++;
						break;
					}
				}
			}

			if (check == false)
				copycontactbook = contactbook;

			check = true;
			forward = true;
			//next portion

			if (choice != 1)
				Back_To_Main();

			break;
		}


		case 2:
		{
			if (No_contacts_added(forward) == false)
				break;
			copycontactbook.merge_duplicates();

			Back_To_Main();
			break;
		}

		case 3:
		{
			if (No_contacts_added(forward) == false)
				break;

			std::string myfile;

			std::cout << "Enter File Name : ";
			std::cin >> myfile;
			copycontactbook.save_to_file(myfile);

			Back_To_Main();
			break;
		}

		case 4:
		{


			std::string myfile;

			std::cout << "Enter File Name : ";
			std::cin >> myfile;
			ContactsBook C;
			copycontactbook = *C.load_from_file(myfile);
			copycontactbook.print_contacts_list();
			forward = true;
			Back_To_Main();
			break;
		}
		case 5:
		{
			if (No_contacts_added(forward) == false)
				break;

			std::string choice;
			std::cout << "1. Sort By First Name\n\n";
			std::cout << "2. Sort By Last Name\n\n";
			std::cout << "Enter Your Choice : ";
			getline(std::cin >> std::ws, choice);

			std::cout << std::endl;
			std::cout << "Sorted By " << choice;

			std::cout << std::endl << std::endl;
			copycontactbook.print_contacts_sorted(choice);

			Back_To_Main();
			break;
		}
		case 6:
		{
			if (No_contacts_added(forward) == false)
				break;

			copycontactbook.print_contacts_list();

			Back_To_Main();
			break;
		}

		case 7:
		{
			if (No_contacts_added(forward) == false)
				break;

			int search_press = 0;
			Search_Menu();
			std::cin >> search_press;
			std::cout << std::endl;
			if (search_press == 1)
			{
				std::cout << "Enter First Name : ";
				std::cin >> first_name;

				std::cout << "Enter Last Name : ";
				std::cin >> last_name;
				std::cout << std::endl;
				Contact* contact;

				HistoryObjects obj;
				time_t timetoday;
				std::string date_time;
				time(&timetoday);
				date_time = asctime(localtime(&timetoday));


				obj.set_name(first_name+" "+last_name);
				obj.set_date_time(date_time);
				history.add_entry(obj);

				contact = copycontactbook.search_contact(first_name, last_name);
				if (contact == nullptr)
				{
					std::cout << "\nNo Contact Found";
				}

				else
				{
					contact->print_contacts();
				}


			}

			else if (search_press == 2)
			{
				std::cout << "Enter Mobile Number : ";
				std::cin >> mobile_number;
				std::cout << std::endl;
				Contact* contact;
				contact = copycontactbook.search_contact(mobile_number);

				HistoryObjects obj;
				time_t timetoday;
				std::string date_time;
				time(&timetoday);
				date_time = asctime(localtime(&timetoday));


				obj.set_name(mobile_number);
				obj.set_date_time(date_time);
				history.add_entry(obj);

				if (contact == nullptr)
				{
					std::cout << "\nNo Contact Found\n";
				}

				else
				{
					contact->print_contacts();
				}
			}

			else
			{
				std::cout << "Enter The Data OF Address\n\n";
				Enter_Address_Data(house, street, city, country,history);
				Address address(house, street, city, country);
				Contact* contact;
				contact = copycontactbook.search_contact(address);
				std::cout << std::endl;


				if (contact == nullptr)
				{
					std::cout << "\nNo Contact Found";
				}

				else
				{
					contact->print_contacts();
				}

			}

			Back_To_Main();
			break;
		}

		case 8:
		{
			if (No_contacts_added(forward) == false)
				break;
			std::cout << "\n\nTotal Contacts Are : " << copycontactbook.total_contacts();

			Back_To_Main();
			break;
		}

		case 9:
		{
			std::string word;
			std::cout << "Enter The Alphabets You Want To Search : ";
			std::cin >> word;
			std::cout << std::endl << std::endl;
			std::cout << "Search Related To : " << word;
			std::cout << "\n\n";
			copycontactbook.advance_search(word);
			Back_To_Main();

			HistoryObjects obj;
			time_t timetoday;
			std::string date_time;
			time(&timetoday);
			date_time = asctime(localtime(&timetoday));

			
			obj.set_name(word);
			obj.set_date_time(date_time);
			history.add_entry(obj);

			break;
		}

		case 10:
		{
			int press = 0;
			Display_Group();
			std::cout << "Select The Desired Option : ";
			std::cin >> press;
			std::cout << std::endl;
			if (press == 1)
			{
				group.Create_Group();

				groupcontacts.add_group(group);
			}

			if (press == 2)
			{
				int id = 0;
				int index = 0;

				std::cout << "                          The Available Groups Are\n\n";
				groupcontacts.display_groups();

				std::cout << "\n\n";

				std::cout << "Choose From Selected Group : ";
				std::cin >> index;

				std::cout << "                          The Availabe Contacts Are\n\n";

				copycontactbook.print_contacts_list();

				std::cout << "\n\n";

				std::cout << "Enter The Unique Id Of The Contact You Want To Add In A Group : ";
				std::cin >> id;

				groupcontacts.get_group()[index - 1].set_unique_id(id);

			}

			if (press == 3)
			{
				std::cout << "                          Here Is The List Of Group\n\n";

				groupcontacts.display_groups();


				int select = 0;

				std::cout << "\nSelect The Group You Want To Remove Any Contact : ";
				std::cin >> select;
				std::cout << std::endl;
				std::cout << "               Here Is The List Of Contacts Included In The Group";
				std::cout << "\n\n";

				/*int* ids = new int[groupcontacts.get_group()[select - 1].get_id_count()];

				for (int i = 0; i < groupcontacts.get_group()[select - 1].get_id_count(); i++)
				{
					ids[i] = groupcontacts.get_group()[select - 1].get_Ids()[i];
				}*/

				copycontactbook.Display_By_Unique_Id(groupcontacts.get_group()[select - 1].get_Ids());
				std::cout << std::endl;
				int unique_id;

				std::cout << "Enter Unique Id Of The Contact You Want To Remove From Group : ";
				std::cin >> unique_id;
				groupcontacts.get_group()[select - 1].Remove_Contact_From_Group(unique_id);

				std::cout << "\nContact Removed Sucessfully. New List Is\n\n";
				copycontactbook.Display_By_Unique_Id(groupcontacts.get_group()[select - 1].get_Ids());

			}

			if (press == 4)
			{
				int unique_id;
				copycontactbook.print_contacts_list();

				std::cout << std::endl;
				std::cout << std::endl;

				std::cout << "Enter The Unique Id To View The Contacts Group : ";
				std::cin >> unique_id;
				std::cout << std::endl;
				groupcontacts.View_Contacts_Group(unique_id);

			}

			if (press == 5)
			{
				int select;
				groupcontacts.display_groups();
				std::cout << "Select the Group You Want To Delete : ";
				std::cin >> select;
				groupcontacts.Delete_Group(select);
			}

			if (press == 6)
			{
				std::cout << std::endl;
				groupcontacts.display_groups();
			}
			Back_To_Main();
			break;
		}

		case 11:
		{
			Manage_Contacts();
			int press = 0;

			std::cout << "Select The Desired Option : ";
			std::cin >> press;

			if (press == 3)
			{
				std::cout << std::endl;
				copycontactbook.print_contacts_list();
				int index = 0;
				std::cout << "\n\nSelect From The Contact You Want To Delete : ";
				std::cin >> index;
				
				copycontactbook.Delete_Contact(index);
			}
			break;
		}
		case 12:
		{
			history.display_sorted();
			Back_To_Main();
			break;
		}
		case 13:
		{
			return 0;
		}
		default:

			std::cout << "\nNot Working\n";
			break;
		}

		std::cout << std::endl << std::endl;
		system("cls");
	} while (press != 13);
	
		
		
		

}