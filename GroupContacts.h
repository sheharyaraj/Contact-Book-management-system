#pragma once
#include"Group.h"
class GroupContacts
{
	Group* group;
	int group_count;
public:

	GroupContacts()
	{
		this->group_count = 0;
	}

	void operator=(GroupContacts &group_contacts)
	{
		this->group = new Group[group_contacts.group_count];

		for (int i = 0; i < group_contacts.group_count; i++)
		{
			this->group[i] = group_contacts.group[i];
		}

		this->group_count = group_contacts.group_count;
	}
	void add_group(Group& group);
	void View_Contacts_Group(int unique_id);
	void display_groups();
	void Resize_Groups();
	Group* get_group();

	void Delete_Group(int group_number);
};