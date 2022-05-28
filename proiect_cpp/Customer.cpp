#include "Customer.h"


Customer::Customer(IdentificationInfos identificationInfos, CustomerHomeAdress customerHomeAdress, DrivingLicense customerDrivingLicense,DateOfBirth customerDateOfBirth,RentalSchedule customerRentalSchedule)
{
	m_identificationInfos = identificationInfos;
	m_customerHomeAddress = customerHomeAdress;
	m_customerDrivingLicense = customerDrivingLicense;
	m_customerDateOfBirth = customerDateOfBirth;
	m_customerRentalSchedule = customerRentalSchedule;
}


Customer::Customer()
{
	m_identificationInfos.SetCustomerCNP("\0");
	m_identificationInfos.SetCustomerEmail("\0");
	m_identificationInfos.SetCustomerFirstName("\0");
	m_identificationInfos.SetCustomerIDCardNumber("\0");
	m_identificationInfos.SetCustomerIDSeries("\0");
	m_identificationInfos.SetCustomerLastName("\0");
	m_identificationInfos.SetCustomerTelephone("\0");
	m_identificationInfos.SetCustomerPassword("\0");

	m_customerHomeAddress.SetCustomerCity("\0");
	m_customerHomeAddress.SetCustomerCountry("\0");
	m_customerHomeAddress.SetCustomerPostalCode("\0");
	m_customerHomeAddress.SetCustomerStreet("\0");
	m_customerHomeAddress.setCustomerStreetNumber("\0");

}



// Getters


IdentificationInfos Customer::GetCustomerIdentificationInfos()const { return m_identificationInfos; }


CustomerHomeAdress Customer::GetCustomerHomeAdress()const { return m_customerHomeAddress; }


DrivingLicense Customer::GetCustomerDrivingLicense()const { return m_customerDrivingLicense; }


DateOfBirth Customer::GetCustomerDateOfBirth()const { return m_customerDateOfBirth; }


RentalSchedule Customer::GetCustomerRentalSchedule()const { return m_customerRentalSchedule; }


//----------------------------------------------------------------------------------------------
