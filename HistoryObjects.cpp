#include"HistoryObjects.h"

HistoryObjects::HistoryObjects()
{
	count++;
}

void HistoryObjects::set_name(std::string name)
{
	this->name = name;
}
void HistoryObjects::set_date_time(std::string date_time)
{
	this->date_time = date_time;
}

std::string HistoryObjects::get_name()
{
	return name;
}
std::string HistoryObjects::get_date_time()
{
	return date_time;
}

int HistoryObjects::get_count()
{
	return count;
}

int HistoryObjects::count = 0;