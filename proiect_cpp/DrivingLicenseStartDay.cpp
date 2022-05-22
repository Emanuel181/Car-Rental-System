#include "DrivingLicenseStartDay.h"


DrivingLicenseStartDay::DrivingLicenseStartDay(const std::string startDay, const std::string startMonth, const std::string startYear)
{
	m_startDay = startDay;
	m_startMonth = startMonth;
	m_startYear = startYear;
}


DrivingLicenseStartDay::DrivingLicenseStartDay()
	:m_startDay{"\0"}, m_startMonth{"\0"}, m_startYear{"\0"}
{}


// Getters

std::string DrivingLicenseStartDay::GetStartDay()const { return m_startDay; }


std::string DrivingLicenseStartDay::GetStartMonth()const { return m_startMonth; }


std::string DrivingLicenseStartDay::GetStartYear()const { return m_startYear; }


//---------------------------------------------------------------------------------