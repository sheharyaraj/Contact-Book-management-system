#include"HistoryList.h"
#include<iostream>
HistoryList::HistoryList()
{
	Search_list = new HistoryObjects[5];
	entry_num = 0;
}

void HistoryList::add_entry(HistoryObjects obj)
{
	Search_list[entry_num] = obj;
	entry_num++;
}

HistoryObjects* HistoryList::get_Search_list()
{
	return Search_list;
}

void HistoryList::display_sorted()
{
	std::cout << "Search History (Latest First): " << std::endl;
	for (int i = 1; i >= 0; i--)
	{
		std::cout << "Name= " << Search_list[i].get_name() << "   Date= " << Search_list[i].get_date_time();
	}
}