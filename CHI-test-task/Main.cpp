#include <iostream>
#include "windows.h"
#include "TODOItem.h"
#include "TODOList.h"
#include <thread>
#include <future>
#include <chrono>
#include <ctime>
#include <string>
#include <conio.h>

std::chrono::time_point<std::chrono::system_clock> ParseTimeString(std::string str)
{
	int h = std::stoi(str.substr(0, 2));
	int m = std::stoi(str.substr(3, 2));

	struct tm newTime;
	auto nowTP = std::chrono::system_clock::now();
	time_t now = std::chrono::system_clock::to_time_t(nowTP);
	localtime_s(&newTime, &now);

	int h_now = newTime.tm_hour;
	int m_now = newTime.tm_min;
	int s_now = newTime.tm_sec;

	if (h > h_now)
	{
		h -= h_now;
		if (m >= m_now)
		{
			m -= m_now;
		}
		else
		{
			h--;
			m = m - m_now + 60;
		}
	}
	else if (h == h_now)
	{
		h = 0;
		if (m >= m_now)
		{
			m -= m_now;
		}
		else
		{
			m = m - m_now + 1440;
		}
	}
	else
	{
		h = h - h_now + 24;
		if (m >= m_now)
		{
			m -= m_now;
		}
		else
		{
			h--;
			m = m - m_now + 60;
		}
	}

	return std::chrono::system_clock::now() + std::chrono::hours(h) + std::chrono::minutes(m) - std::chrono::seconds(s_now);
}


int main(int argc, wchar_t* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TODOList todoList;
	todoList.LoadFromFile();

	std::string message;
	std::string time;

	while (true)
	{
		system("cls");
		std::cout << "1. Добавить дела." << std::endl;
		std::cout << "2. Показать список дел." << std::endl;
		std::cout << "3. Сохранить список дел в файл." << std::endl;
		std::cout << "0. Выход." << std::endl;

		int c;
		c = _getch();

		if (c == 48)
			break;

		switch (c)
		{
		case 49:
			system("cls");
			std::cout << "Для возвращения в меню введите quit." << std::endl;
			
			while (true)
			{
				std::cout << "Введите название события: \n";
				std::getline(std::cin, message);

				if (message == "quit")
				{
					break;
				}

				std::cout << "Введите время напоминания (в формате HH:MM): \n";
				std::getline(std::cin, time);

				TODOItem todoItem(message, ParseTimeString(time));
				todoList.AddItem(todoItem);
			}
			break;
		case 50:
			todoList.PrintItems();
			std::cout << "Для возвращения в меню нажмите Enter...\n";
			system("pause");
			break;
		case 51:
			todoList.SaveToFile();
			std::cout << "Список дел сохранён в файл.\n";
			std::cout << "Для возвращения в меню нажмите Enter...\n";
			system("pause");
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}
