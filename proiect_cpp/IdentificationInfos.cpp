#include "IdentificationInfos.h"


IdentificationInfos::IdentificationInfos(const std::string customerFirstName, const std::string customerLastName, const std::string customerEmail, const std::string customerTelephone, const std::string customerCNP, const std::string customerIDSeries, const std::string customerIDCardNumber,const std::string customerPassword)
{
    m_customerFirstName = customerFirstName;
    m_customerLastName = customerLastName;
    m_customerEmail = customerEmail;
    m_customerTelephone = customerTelephone;
    m_customerCNP = customerCNP;
    m_customerIDSeries = customerIDSeries;
    m_customerIDCardNumber = customerIDCardNumber;
    m_customerPassword = customerPassword;
}


IdentificationInfos::IdentificationInfos()
    :m_customerFirstName{ "\0" }, m_customerLastName{ "\0" },
    m_customerEmail{ "\0" }, m_customerTelephone{ "\0" }, m_customerCNP{ "\0" },
    m_customerIDSeries{ "\0" }, m_customerIDCardNumber{ "\0" }, m_customerPassword{ "\0" }
{}


// Getters


std::string IdentificationInfos::GetCustomerFirstName()const { return m_customerFirstName; }


std::string IdentificationInfos::GetCustomerLastName()const { return m_customerLastName; }


std::string IdentificationInfos::GetCustomerEmail()const { return m_customerEmail; }


std::string IdentificationInfos::GetCustomerTelephone()const { return m_customerTelephone; }


std::string IdentificationInfos::GetCustomerCNP()const { return m_customerCNP; }


std::string IdentificationInfos::GetCustomerIDSeries()const { return m_customerIDSeries; }


std::string IdentificationInfos::GetCustomerIDCardNumber()const { return m_customerIDCardNumber; }


std::string IdentificationInfos::GetCustomerPassword()const { return m_customerPassword; }


//-----------------------------------------------------------------------------------------------------


// Setters


void IdentificationInfos::SetCustomerFirstName(const std::string init) { m_customerFirstName = init; }


void IdentificationInfos::SetCustomerLastName(const std::string init) { m_customerLastName = init; }


void IdentificationInfos::SetCustomerEmail(const std::string init) { m_customerEmail = init; }


void IdentificationInfos::SetCustomerTelephone(const std::string init) { m_customerTelephone = init; }


void IdentificationInfos::SetCustomerCNP(const std::string init) { m_customerCNP = init; }


void IdentificationInfos::SetCustomerIDSeries(const std::string init) { m_customerIDSeries = init; }


void IdentificationInfos::SetCustomerIDCardNumber(const std::string init) { m_customerIDCardNumber = init; }


void IdentificationInfos::SetCustomerPassword(const std::string init) { m_customerPassword = init; }


//----------------------------------------------------------------------------------------------------------------------
