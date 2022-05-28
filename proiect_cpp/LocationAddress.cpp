#include "LocationAddress.h"
#include <iostream>

LocationAddress::LocationAddress(const std::string streetName, const std::string streetNumber, const std::string streetPostalCode)
{
	m_streetName = streetName;
	m_streetNumber = m_streetNumber;
	m_streetPostalCode = m_streetPostalCode;
}

LocationAddress::LocationAddress()
{
	m_streetName = "\0";
	m_streetNumber = "\0";
	m_streetPostalCode = "\0";
}


std::ostream& operator << (std::ostream& COUT, const LocationAddress& obj)
{
	COUT << "Location: \n";
	COUT << "Street name: " << obj.GetStreetName() << '\n';
	COUT << "Street number: " << obj.GetStreetNumber() << '\n';
	COUT << "Postal code: " << obj.GetStreetPostalCode() << '\n';

	return COUT;
}


// Getters

std::string LocationAddress::GetStreetName() const {
	return m_streetName;
}

std::string LocationAddress::GetStreetNumber() const {
	return m_streetNumber;
}

std::string LocationAddress::GetStreetPostalCode() const {
	return m_streetPostalCode;
}


//------------------------------------------------------------------