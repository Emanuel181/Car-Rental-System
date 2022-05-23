#include "Customer.h"


Customer::Customer(IdentificationInfos identificationInfos, CustomerHomeAdress customerHomeAdress, DrivingLicense customerDrivingLicense,DateOfBirth customerDateOfBirth,RentalSchedule customerRentalSchedule)
{
	m_identificationInfos = identificationInfos;
	m_customerHomeAddress = customerHomeAdress;
	m_customerDrivingLicense = customerDrivingLicense;
	m_customerDateOfBirth = customerDateOfBirth;
	m_customerRentalSchedule = customerRentalSchedule;
}



// Getters


IdentificationInfos Customer::GetCustomerIdentificationInfos()const { return m_identificationInfos; }


CustomerHomeAdress Customer::GetCustomerHomeAdress()const { return m_customerHomeAddress; }


DrivingLicense Customer::GetCustomerDrivingLicense()const { return m_customerDrivingLicense; }


DateOfBirth Customer::GetCustomerDateOfBirth()const { return m_customerDateOfBirth; }


RentalSchedule Customer::GetCustomerRentalSchedule()const { return m_customerRentalSchedule; }


//----------------------------------------------------------------------------------------------
