#include "TODOItem.h"

TODOItem::TODOItem(std::string m, std::chrono::time_point<std::chrono::system_clock> tp)
{
	message = m;
	timePoint = tp;
}

TODOItem::TODOItem()
{
}


std::string TODOItem::GetMessage() const
{
	return message;
}

std::chrono::time_point<std::chrono::system_clock> TODOItem::GetTimePoint() const
{
	return timePoint;
}

