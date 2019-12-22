#include "DateTime.h"
#include <string>

DateTime::DateTime()
{
	time(&seconds);
	time_structure = localtime(&seconds);
}

DateTime::~DateTime()
{

}

DateTime::DateTime(int day, int month, int year)
{
	//Создаем структуры
	time(&seconds);
	time_structure = localtime(&seconds);

	//Так как месяц отсчитывается с 1900
	time_structure->tm_year = year - 1900;
	time_structure->tm_mon = month - 1;
	time_structure->tm_mday = day;

	//Приравниваем
	seconds = mktime(time_structure);
	time_structure = localtime(&seconds);
}

DateTime::DateTime(DateTime &from)
{
	seconds = from.seconds;
	time_structure = localtime(&seconds);
}

//Геттеры для определенных дней

std::string DateTime::getFuture(unsigned int N)
{
	time_t temp = seconds + N * 24 * 3600;
	tm* future = localtime(&temp);
	return timeToStr(future);
}

std::string DateTime::getToday()
{
	return timeToStr(time_structure);
}

std::string DateTime::getYesterday()
{
	return getPast(1);
}

std::string DateTime::getTomorrow()
{
	return getFuture(1);
}

std::string DateTime::getPast(unsigned int N)
{
	return getFuture(-1 * N);
}

//Разница в днях

int DateTime::getDifference(DateTime& ref)
{
	return (int)((unsigned long long)(std::abs(ref.seconds - seconds)) / (3600 * 24));
}

std::string DateTime::timeToStr(tm* time)
{
	std::string s;
	if (time->tm_mday < 10)
		s += "0";
	s += std::to_string(time->tm_mday) + " " + months[time->tm_mon] + " " + std::to_string(time->tm_year + 1900) + ", " + weekDays[time->tm_wday];
	return s;
}