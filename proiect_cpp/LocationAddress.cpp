#include "LocationAddress.h"


std::string LocationAddress::GetStreetName() const {
	return m_streetName;
}

int LocationAddress::GetStreetNumber() const {
	return m_streetNumber;
}

int LocationAddress::GetStreetPostalCode() const {
	return m_streetPostalCode;
}