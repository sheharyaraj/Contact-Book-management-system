
#include<iostream>
#include<string>
#include<cstring>
#include"HistoryObjects.h"
#include"HistoryList.h"
#include<stdio.h>
#include<time.h>
#pragma warning(disable : 4996)

void Print_Menu()
{
	std::cout << "1. Create a contacts list form given size (input size from user)" << std::endl << std::endl;

	std::cout << "2. Merge Duplicates" << std::endl << std::endl;

	std::cout << "3. Store To File(input file name)" << std::endl << std::endl;

	std::cout << "4. Load From File(input file name)" << std::endl << std::endl;

	std::cout << "5. Print Contacts Sorted(input choice, fist_name or last_name)" << std::endl << std::endl;

	std::cout << "6. Print Contacts" << std::endl << std::endl;

	std::cout << "7. Search contacts(all three choices)" << std::endl << std::endl;

	std::cout << "8. Display Count of Contacts" << std::endl << std::endl;

	std::cout << "9. Advance Search" << std::endl << std::endl;

	std::cout << "10. Groups" << std::endl << std::endl;

	std::cout << "11. Manage Contacts" << std::endl << std::endl;

	std::cout << "12. Search History" << std::endl << std::endl;

	std::cout << "13. Exit Program" << std::endl << std::endl;

	std::cout << "Press The Desired Option : ";
}

void Enter_Address_Data(std::string &house,std::string &street,std::string &city,std::string &country, HistoryList&history)
{
	std::cout << "Enter House : ";
	std::cin >> house;
	std::cout << "Enter Street : ";
	getline(std::cin >>std::ws, street);
	std::cout << "Enter City : ";
	std::cin >> city;
	std::cout << "Enter Country : ";
	std::cin >> country;

	HistoryObjects obj;
	time_t timetoday;
	std::string date_time;
	time(&timetoday);
	date_time = asctime(localtime(&timetoday));


	obj.set_name(house+" "+street+" "+city+" "+country);
	obj.set_date_time(date_time);
	history.add_entry(obj);
}

bool No_contacts_added(bool forward)
{
	char key;
	if (forward == false)
	{
		std::cout << "\n\nNo Contact Has Been Added Yet\n\n";
		std::cout << "Press Any key To  Return To Main Menu: ";
		std::cin >> key;
	}
	return forward;
}

void Search_Menu()
{
	std::cout << "1. Search By First Name And Last Name\n\n";
	std::cout << "2. Search By Phone Number\n\n";
	std::cout << "3. Search By Address\n\n";
	std::cout << "Press The Desired Option : ";
}

void Back_To_Main()
{
	char key;
	std::cout << "\n\nPress Any Key To Return To Main Menu : ";
	std::cin >> key;
}

void Display_Group()
{
	std::cout << "1. Create A Group\n\n";
	std::cout << "2. Add A Contact To A Group\n\n";
	std::cout << "3. Remove A Contact From A Group\n\n";
	std::cout << "4. View A Contact's Group\n\n";
	std::cout << "5. Delete A Group\n\n";
	std::cout << "6. Display Groups\n\n";
}

void Manage_Contacts()
{
	std::cout << "1. View Details Of Single Contact\n\n";
	std::cout << "2. Update Details Of Single Contact\n\n";
	std::cout << "3. Delete The Contact\n\n";
}