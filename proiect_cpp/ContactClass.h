#pragma once
#include <string>

class ContactClass {

private:
	std::string m_phoneNumber;
	std::string m_email;
	std::string m_managerName;

public:
	std::string GetPhoneNumber() const;
	std::string GetEmail() const;
	std::string GetManagerName() const;
};
