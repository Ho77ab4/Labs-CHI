#include "TODOList.h"

TODOList::TODOList()
{
	
}

void TODOList::AddItem(TODOItem item)
{
	items.push_back(item);
	SetTimer(item);
}

void TODOList::PrintItems()
{
	std::cout << "\nList items:\n";
	if (items.size() > 0)
	{
		for (int i = 0; i < items.size(); i++)
		{
			std::cout << items[i].GetMessage() << std::endl;
		}
	}
}

void TODOList::SaveToFile()
{
	std::ofstream offile;
	offile.open("Settings.dat", std::ios::binary);

	if (!offile.is_open())
	{
		return;
	}
	int size = items.size();
	offile.write((char*)&size, sizeof(size));

	for (int i = 0; i < items.size(); i++)
	{
		auto const time = std::chrono::system_clock::to_time_t(items[i].GetTimePoint());
		offile.write(reinterpret_cast<char const*>(&time), sizeof(time));

		size_t len = items[i].GetMessage().length() + 1;
		offile.write((char*)&len, sizeof(len));
		offile.write((char*)items[i].GetMessage().c_str(), len);
	}

	offile.close();
}

void TODOList::LoadFromFile()
{
	std::ifstream iffile("Settings.dat", std::ios::binary);

	if (!iffile.is_open())
	{
		return;
	}

	int size = 0;
	iffile.read((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		std::chrono::system_clock::rep file_time_rep;
		if (!iffile.read(reinterpret_cast<char*>(&file_time_rep), sizeof file_time_rep))
		{
			return;
		}
		const std::chrono::time_point<std::chrono::system_clock> cache_valid_time{ std::chrono::duration<long>{file_time_rep} };

		std::cout << "now time " << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << std::endl;
		std::cout << "valid time " << std::chrono::system_clock::to_time_t(cache_valid_time) << std::endl;
		system("pause");

		std::string msg;
		size_t len;
		iffile.read((char*)&len, sizeof(len));
		char *buf = new char[len];
		iffile.read(buf, len);
		msg = buf;
		delete[] buf;

		TODOItem item(msg, cache_valid_time);
		AddItem(item);
	}

	iffile.close();
}

void TODOList::SetTimer(TODOItem item)
{
	std::chrono::time_point<std::chrono::system_clock> nowTP = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(item.GetTimePoint() - nowTP);

	std::thread([=]() {
		std::this_thread::sleep_for(duration);
		
		system("cls");
		std::cout << item.GetMessage() << std::endl;
		std::cout << "Для возвращения в меню нажмите Enter...\n";
		system("pause");
		system("cls");

	}).detach();
}

