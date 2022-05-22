#pragma once
#include <string>


class DateOfBirth
{
private:
    std::string m_customerBirthDay;
    std::string m_customerBirthMonth;
    std::string m_customerBirthYear;
public:
    std::string GetCustomerBirthDay()const;
    std::string GetCustomerBirthMonth()const;
    std::string GetCustomerBirthYear()const;
};

