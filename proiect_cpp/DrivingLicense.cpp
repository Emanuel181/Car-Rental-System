#include "DrivingLicense.h"


DrivingLicense::DrivingLicense(DrivingLicenseStartDay drivingLicenseStartDay, DrivingLicenseEndDay drivingLicenseEndDay, const std::string isAbleToDrive)
{
	m_drivingLicenseStartDay = drivingLicenseStartDay;
	m_drivingLicenseEndDay = drivingLicenseEndDay;
	m_isAbleToDrive = isAbleToDrive;
}


DrivingLicense::DrivingLicense()
	: m_isAbleToDrive{"pending"}
{}


// Getters

DrivingLicenseStartDay DrivingLicense::GetDrivingLicenseStartDay()const { return m_drivingLicenseStartDay; }


DrivingLicenseEndDay DrivingLicense::GetDrivingLicenseEndDay()const { return m_drivingLicenseEndDay; }


std::string DrivingLicense::GetIsAbleToDrive()const { return m_isAbleToDrive; }


//---------------------------------------------------------------