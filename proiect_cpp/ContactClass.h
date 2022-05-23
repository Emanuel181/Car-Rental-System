#pragma once
#include <string>

class ContactClass {

private:
	std::string m_phoneNumber;
	std::string m_email;
	std::string m_managerName;

public:
	ContactClass(const std::string, const std::string, const std::string);
	ContactClass();
	std::string GetPhoneNumber() const;
	std::string GetEmail() const;
	std::string GetManagerName() const;
	void SetPhoneNumber(const std::string);
	void SetEmail(const std::string);
	void SetManagerName(const std::string);
};

