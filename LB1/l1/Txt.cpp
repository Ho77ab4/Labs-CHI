#include "pch.h"
#include "Txt.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace l1
{
	// Base constructor
	Txt::Txt()
	{
		length = 0;
		buffer = new char[0];
	}

	// One parameter constructor
	Txt::Txt(const char& filePath)
	{
		fstream f;
		f.open(&filePath, ios::in);
		f.seekg(0, f.end);
		length = f.tellg();
		f.seekg(0, f.beg);

		buffer = new char[length];
		
		f.read(buffer, length);
		f.close();
	}

	// Copy construnctor
	Txt::Txt(const Txt& txt) : length(txt.length)
	{
		buffer = new char[length];
		for (int i = 0; i < length; ++i)
		{
			buffer[i] = txt.buffer[i];
		}
	}

	// Copy assignment operator
	Txt & Txt::operator=(const Txt& txt)
	{
		if (&txt == this)
			return *this;

		delete[] buffer;

		length = txt.length;
		buffer = new char[length];

		for (int i = 0; i < length; ++i)
		{
			buffer[i] = txt.buffer[i];
		}

		return *this;
	}

	// Move constructor
	Txt::Txt(Txt&& txt) : length(txt.length), buffer(txt.buffer)
	{
		txt.length = 0;
		txt.buffer = nullptr;
	}

	// Move assignment operator
	Txt& Txt::operator=(Txt&& txt)
	{
		if (&txt == this)
			return *this;

		delete[] buffer;

		length = txt.length;
		buffer = txt.buffer;
		txt.length = 0;
		txt.buffer = nullptr;

		return *this;
	}

	// Count of strings in buffer
	size_t Txt::size() const
	{
		int stringsCount = 0;

		if (length != 0)
		{
			for (int i = 0; i < length; ++i)
			{
				if (buffer[i] == '\n')
				{
					stringsCount++;
				}
			}
		}
		else
		{
			return size_t(0);
		}

		// made +1 to the final count, because between 2 strings we have only one \n symvol
		stringsCount++;

		return size_t(stringsCount);
	}

	// Destructor
	Txt::~Txt()
	{
		delete[] buffer;
		length = 0;
	};

}
