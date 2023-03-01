#pragma once
#include"HistoryObjects.h"

class HistoryList {
private:
	HistoryObjects* Search_list;
	int entry_num;
public:
	HistoryList();
	/*void operator=(HistoryList& obj)
	{
		this->entry_num = obj.entry_num;
		this->Search_list = new HistoryObjects[entry_num];

		for (int i = 0; i < entry_num; i++)
		{
			if (obj.entry_num == 0)
				break;
			Search_list[i] = obj.Search_list[i];
		}
	}*/
	void add_entry(HistoryObjects obj);
	HistoryObjects* get_Search_list();
	void display_sorted();
};