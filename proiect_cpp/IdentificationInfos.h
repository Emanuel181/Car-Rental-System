#pragma once
#include <string>


class IdentificationInfos
{
private:
    std::string m_customerFirstName;
    std::string m_customerLastName;
    std::string m_customerEmail;
    std::string m_customerTelephone;
    std::string m_customerCNP;
    std::string m_customerIDSeries;
    std::string m_customerIDCardNumber;
public:
    std::string GetCustomerFirstName()const;
    std::string GetCustomerLastName()const;
    std::string GetCustomerEmail()const;
    std::string GetCustomerTelephone()const;
    std::string GetCustomerCNP()const;
    std::string GetCustomerIDSeries()const;
    std::string GetCustomerIDCardNumber()const;
    IdentificationInfos(const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string);
};

