#pragma once
#include <string>


bool InputValid(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (strchr("01234567890", input[i]) == 0)
			return false;
	}
	return true;
}


bool isChar(char c)
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