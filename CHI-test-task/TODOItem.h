#include <iostream>
#include <chrono>
#include <string>

#pragma once
class TODOItem
{
public:
	TODOItem(std::string m, std::chrono::time_point<std::chrono::system_clock> tp);
	TODOItem();
	std::chrono::time_point<std::chrono::system_clock> GetTimePoint() const;
	std::string GetMessage() const;
private:
	std::string message;
	std::chrono::time_point<std::chrono::system_clock> timePoint;
};

