#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

class DateTime
{

private:

	std::string timeToStr(tm* time);

	time_t seconds;
	tm* time_structure;

	const std::string weekDays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

	const std::string months[12] = { "january","february","march","april","may","june","july","august",
									   "september","october","november","december" };

public:

	DateTime(int day, int month, int year);
	DateTime();
	DateTime(DateTime&);
	~DateTime();

	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(unsigned int N);
	std::string getPast(unsigned int N);

	int getDifference(DateTime&);
};