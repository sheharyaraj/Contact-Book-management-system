#include"Group.h"
#include<iostream>
#include<cstring>
#include<string>
void Group::Create_Group()
{
	std::cout << "Enter Group Name : ";
	
	getline(std::cin>>std::ws,group_name);
}

void Group::Show_Group()
{
		std::cout << "Group Name : " << group_name;
		std::cout << "\n";
}

std::string Group::get_group_name()
{
	return group_name;
}

void Group::set_unique_id(int id)
{
	if (id_count == 0)
	{
		this->Ids = new int;
		*this->Ids = id;
	}
	
	if (id_count != 0)
	{
		Resize_Unique_Id();

		this->Ids[id_count] = id;
		
	}

	this->id_count++;
}

void Group::Resize_Unique_Id()
{
	int* temp = new int[id_count];

	for (int i = 0; i < id_count; i++)
	{
		temp[i] = Ids[i];
	}

	Ids = new int[id_count + 1];

	for (int i = 0; i < id_count; i++)
	{
		Ids[i] = temp[i];
	}
}

void Group::Remove_Contact_From_Group(int unique_id)
{
	for (int i = 0; i < id_count; i++)
	{
		if (unique_id == Ids[i])
		{
			for (int j = i; j < id_count - 1; j++)
			{
				Ids[j] = Ids[j + 1];
			}

			break;
		}
	}

	this->id_count--;
	int* temp = new int[id_count];

	for (int i = 0; i < id_count; i++)
	{
		temp[i] = Ids[i];
	}

	Ids = new int[id_count];

	for (int i = 0; i < id_count; i++)
	{
		Ids[i] = temp[i];
	}
}

int *Group::get_Ids()
{
	return Ids;
}

int Group::get_id_count()
{
	return id_count;
}