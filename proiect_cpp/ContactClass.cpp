#include "ContactClass.h"
#include <iostream>

ContactClass::ContactClass(const std::string phoneNumber, const std::string email, const std::string managerName)
{
	m_phoneNumber = phoneNumber;
	m_email = email;
	m_managerName = managerName;
}

ContactClass::ContactClass() {
	m_phoneNumber = "\0";
	m_email = "\0";
	m_managerName = "\0";
}


std::ostream& operator << (std::ostream& COUT, const ContactClass& obj)
{
	COUT << "CONTACT:\n";
	COUT << "Phone number: " << obj.GetPhoneNumber();
	COUT << "Email: " << obj.GetEmail();
	COUT << "Manager name: " << obj.GetManagerName();

	return COUT;
}


// Getters

std::string ContactClass::GetPhoneNumber() const {
	return m_phoneNumber;
}

std::string ContactClass::GetEmail() const {
	return m_email;
}

std::string ContactClass::GetManagerName() const {
	return m_managerName;
}


//---------------------------------------------------------------


// Setters

void ContactClass::SetPhoneNumber(const std::string Init) { m_phoneNumber = Init; }


void ContactClass::SetEmail(const std::string Init) { m_email = Init; }


void ContactClass::SetManagerName(const std::string Init) { m_managerName = Init; }


//-------------------------------------------------------------------
