#include "CustomerHomeAdress.h"


CustomerHomeAdress::CustomerHomeAdress(const std::string customerCountry, const std::string customerCity, const std::string customerPostalCode, const std::string customerStreet, const std::string customerStreetNumber)
{
	m_customerCountry = customerCountry;
	m_customerCity = customerCity;
	m_customerPostalCode = customerPostalCode;
	m_customerStreet = customerStreet;
	m_customerStreetNumber = customerStreetNumber;
}


CustomerHomeAdress::CustomerHomeAdress()
	:m_customerCountry{"\0"}, m_customerCity{"\0"}, m_customerPostalCode{"\0"},
	m_customerStreet{"\0"}, m_customerStreetNumber{"\0"}
{}


// Getters


std::string CustomerHomeAdress::GetCustomerCountry()const { return m_customerCountry; }


std::string CustomerHomeAdress::GetCustomerCity()const { return m_customerCity; }


std::string CustomerHomeAdress::GetCustomerPostalCode()const { return m_customerPostalCode; }


std::string CustomerHomeAdress::GetCustomerStreet()const { return m_customerStreet; }


std::string CustomerHomeAdress::GetCustomerStreetNumber()const { return m_customerStreetNumber; }


//-------------------------------------------------------------------------------------------------


// Setters


void CustomerHomeAdress::SetCustomerCountry(const std::string init) { m_customerCountry = init; }


void CustomerHomeAdress::SetCustomerCity(const std::string init) { m_customerCity = init; }


void CustomerHomeAdress::SetCustomerPostalCode(const std::string init) { m_customerPostalCode = init; }


void CustomerHomeAdress::SetCustomerStreet(const std::string init) { m_customerStreet = init; }


void CustomerHomeAdress::setCustomerStreetNumber(const std::string init) { m_customerStreetNumber = init; }


//--------------------------------------------------------------------------------------------------