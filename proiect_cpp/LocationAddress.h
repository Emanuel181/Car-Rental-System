#pragma once
#include <string>

class LocationAddress {

private:
	std::string m_streetName;
	int m_streetNumber;
	int m_streetPostalCode;

public:
	std::string GetStreetName() const;
	int GetStreetNumber() const;
	int GetStreetPostalCode() const;

};