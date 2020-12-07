#include <iostream>
#include <vector>
#include "TODOItem.h"
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

#pragma once
class TODOList
{
public:
	TODOList();
	void AddItem(TODOItem);
	void SetTimer(TODOItem);
	void PrintItems();
	void SaveToFile();
	void LoadFromFile();
private:
	std::vector<TODOItem> items;

};


