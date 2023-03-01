#pragma once
#include"ContactsBook.h"
class Group
{
	
	std::string group_name;
	int* Ids;
	int id_count;
public:

	Group()
	{
		this->id_count = 0;
	}
	void operator=(Group& group)
	{
		this->Ids = new int[group.id_count];

		
		for (int i = 0; i < group.id_count; i++)
		{
			if (group.id_count == 0)
				break;

			this->Ids[i] = group.Ids[i];
		}

		this->id_count = group.id_count;
		this->group_name = group.group_name;
	}
	void Create_Group();
	void Show_Group();
	void set_unique_id(int);
	void Resize_Unique_Id();
	void Remove_Contact_From_Group(int unique_id);
	int get_id_count();

	int *get_Ids();
	std::string get_group_name();
	

};