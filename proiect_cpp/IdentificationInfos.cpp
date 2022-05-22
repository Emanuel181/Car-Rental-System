#include "IdentificationInfos.h"


IdentificationInfos::IdentificationInfos(const std::string customerFirstName, const std::string customerLasttName, const std::string customerEmail, const std::string customerTelephone, const std::string customerCNP, const std::string customerIDSeries, const std::string customerIDCardNumber)
{
    m_customerFirstName = customerFirstName;
    m_customerLastName = customerLasttName;
    m_customerEmail = customerEmail;
    m_customerTelephone = customerTelephone;
    m_customerCNP = customerCNP;
    m_customerIDSeries = customerIDSeries;
    m_customerIDCardNumber = customerIDCardNumber;
}


// Getters


std::string IdentificationInfos::GetCustomerFirstName()const { return m_customerFirstName; }


std::string IdentificationInfos::GetCustomerLastName()const { return m_customerLastName; }


std::string IdentificationInfos::GetCustomerEmail()const { return m_customerEmail; }


std::string IdentificationInfos::GetCustomerTelephone()const { return m_customerTelephone; }


std::string IdentificationInfos::GetCustomerCNP()const { return m_customerCNP; }


std::string IdentificationInfos::GetCustomerIDSeries()const { return m_customerIDSeries; }


std::string IdentificationInfos::GetCustomerIDCardNumber()const { return m_customerIDCardNumber; }


//-----------------------------------------------------------------------------------------------------
