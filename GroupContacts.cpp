#include"GroupContacts.h"

Group *GroupContacts::get_group()
{
	return group;
}

void GroupContacts::display_groups()
{
	for (int i = 0; i < group_count; i++)
	{
		std::cout << i + 1<<". ";
		group[i].Show_Group();
	}
}

void GroupContacts::add_group(Group& group)
{
	if (group_count == 0)
	{
		this->group = new Group;
		*this->group = group;
	}

	else
	{
		Resize_Groups();
		this->group[group_count] = group;
	}
		
	this->group_count++;
}

void GroupContacts::Resize_Groups()
{
	
	Group* temp = new Group[group_count];

	for (int i = 0; i < group_count; i++)
	{
		temp[i] = group[i];
	}

	group = new Group[group_count + 1];

	for (int i = 0; i < group_count; i++)
	{
		group[i] = temp[i];
	}

}

void GroupContacts::View_Contacts_Group(int unique_id)
{

	int count = 0;
	for (int i = 0; i < group_count; i++)
	{
		for (int j = 0; j < group[i].get_id_count(); j++)
		{
			if (unique_id == group[i].get_Ids()[j])
			{
				std::cout << count + 1 << ". ";
				std::cout << group[i].get_group_name();
				std::cout << std::endl;
				count++;
				break;
			}
		}
		
	}

	if (count == 0)
	{
		std::cout << "\No Groups Found With The Searched Contacts";
	}
}

void GroupContacts::Delete_Group(int group_number)
{
	for (int i = 0; i < group_count; i++)
	{
		if (group_number - 1 == i)
		{
			for (int j = i; j < group_count - 1; j++)
			{
				group[j] = group[j + 1];
			}
		}
	}

	this->group_count--;
	Group* temp = new Group[group_count];

	for (int i = 0; i < group_count; i++)
	{
		temp[i] = group[i];
	}

	group = new Group[group_count];

	for (int i = 0; i < group_count; i++)
	{
		group[i] = temp[i];
	}

}