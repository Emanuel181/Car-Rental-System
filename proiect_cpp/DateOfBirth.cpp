#include "DateOfBirth.h"

DateOfBirth::DateOfBirth(const std::string customerBirthDay, const std::string customerBirthMonth, const std::string customerBirthYear)
{
	m_customerBirthDay = customerBirthDay;
	m_customerBirthMonth = customerBirthMonth;
	m_customerBirthYear = customerBirthYear;
}

DateOfBirth::DateOfBirth()
{
	m_customerBirthDay = "\0";
	m_customerBirthMonth = "\0";
	m_customerBirthYear = "\0";
}

// Getters

std::string DateOfBirth::GetCustomerBirthDay()const { return m_customerBirthDay; }


std::string DateOfBirth::GetCustomerBirthMonth()const { return m_customerBirthMonth; }


std::string DateOfBirth::GetCustomerBirthYear()const { return m_customerBirthYear; }


//---------------------------------------------------------------------------------------