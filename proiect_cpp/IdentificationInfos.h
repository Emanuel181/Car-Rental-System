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
    std::string m_customerPassword;
public:
    IdentificationInfos(const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string);
    IdentificationInfos();
    std::string GetCustomerFirstName()const;
    std::string GetCustomerLastName()const;
    std::string GetCustomerEmail()const;
    std::string GetCustomerTelephone()const;
    std::string GetCustomerCNP()const;
    std::string GetCustomerIDSeries()const;
    std::string GetCustomerIDCardNumber()const;
    std::string GetCustomerPassword() const;
    void SetCustomerFirstName(const std::string);
    void SetCustomerLastName(const std::string);
    void SetCustomerEmail(const std::string);
    void SetCustomerTelephone(const std::string);
    void SetCustomerCNP(const std::string);
    void SetCustomerIDSeries(const std::string);
    void SetCustomerIDCardNumber(const std::string);
    void SetCustomerPassword(const std::string);
    
};

