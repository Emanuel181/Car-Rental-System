#pragma once
#include <string>

class CustomerHomeAdress
{
private:
    std::string m_costomerCountry;
    std::string m_customerCity;
    std::string m_customerPostalCode;
    std::string m_customerStreet;
    std::string m_customerStreetNumber;
public:
    std::string GetCustomerCountry()const;
    std::string GetCustomerCity()const;
    std::string GetCustomerPostalCode()const;
    std::string GetCustomerStreet()const;
    std::string GetCustomerStreetNumber()const;
};

