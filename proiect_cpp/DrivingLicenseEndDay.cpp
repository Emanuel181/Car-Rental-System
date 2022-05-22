#include "DrivingLicenseEndDay.h"


DrivingLicenseEndDay::DrivingLicenseEndDay(const std::string endDay, const std::string endMonth, const std::string endYear)
{
	m_endDay = endDay;
	m_endMonth = endMonth;
	m_endYear = endYear;
}


DrivingLicenseEndDay::DrivingLicenseEndDay()
{
	m_endDay = "\0";
	m_endMonth = "\0";
	m_endYear = "\0";
}

// Getters

std::string DrivingLicenseEndDay::GetEndDay()const { return m_endDay; }


std::string DrivingLicenseEndDay::GetEndMonth()const { return m_endMonth; }


std::string DrivingLicenseEndDay::GetEndYear()const { return m_endYear; }


//--------------------------------------------