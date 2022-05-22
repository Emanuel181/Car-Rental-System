#pragma once
#include <string>

class LocationAddress {

private:
	std::string m_streetName;
	std::string m_streetNumber;
	std::string m_streetPostalCode;

public:
	LocationAddress(const std::string, const std::string, const std::string);
	LocationAddress();
	std::string GetStreetName() const;
	std::string GetStreetNumber() const;
	std::string GetStreetPostalCode() const;

};