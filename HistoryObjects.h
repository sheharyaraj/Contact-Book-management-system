#pragma once
#include<string>

class HistoryObjects {
private:
	std::string name;
	std::string date_time;
	static int count;
public:
	HistoryObjects();
	void set_name(std::string name);
	void set_date_time(std::string date_time);
	

	std::string get_name();
	std::string get_date_time();
	int get_count();
};
