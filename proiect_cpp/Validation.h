#pragma once
#include <string>
#include <fstream>


bool InputValid(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	return true;
}


bool isChar(const char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}


bool EmailValidation(std::string input)
{
	if (!isChar(input[0]))
		return false;

	int Posa = -1, PosDot = -1;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '@')
			Posa = i;
		else {
			if (input[i] == '.')
				PosDot = i;
		}
	}

	if (Posa == -1 || PosDot == -1)
		return false;
	if (Posa > PosDot)
		return false;
	if (PosDot == input.length() - 1)
		return false;
	return true;
}


bool IDCardSeriesValid(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
			return false;
		if (strchr("0123456789", input[i]))
			return false;
	}
	return true;
}


bool RentalHourValidation(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	int numar = stoi(input);
	if (numar < 8 || numar>17)
		return false;
	return true;
}


bool RentalMinuteValidation(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	int numar = stoi(input);
	if (numar != 0 && numar != 30)
		return false;
	return true;
}


bool AppearOnce(std::string name,std::string email,int value)
{
	std::ifstream fin("Accounts.txt");
	char* line = new char[500];
	std::string emailAddress="", firstName="";
	bool valid = false;
	while (fin >> line)
	{
		char* p = strtok(line, ";");
		int count = 0;
		emailAddress = "";
		while (p)
		{
			if (count == 0)
			{
				firstName = p;
			}
			if (count == 2)
			{
				emailAddress = p;
			}
			if (firstName != "" && firstName == name && value==0)
			{
				delete[] line;
				return false;
			}
			if (emailAddress != "" && emailAddress == email && value==2)
			{
				delete[] line;
				return false;
			}
			count++;
			p = strtok(NULL, ";");
		}
		line = new char[500];
	}
	delete[] line;
	return true;
}