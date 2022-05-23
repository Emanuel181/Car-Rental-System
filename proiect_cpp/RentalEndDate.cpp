#include "RentalEndDate.h"


RentalEndDate::RentalEndDate(const std::string endDay, const std::string endMonth, const std::string endYear, EndTime endTime)
{
	m_endDay = endDay;
	m_endMonth = endMonth;
	m_endYear = endYear;
	m_EndTime = endTime;
}


RentalEndDate::RentalEndDate()
	:m_endDay{"\0"}, m_endMonth{"\0"}, m_endYear{"\0"}
{}


// Getters

std::string RentalEndDate::GetRentalEndDay()const { return m_endDay; }


std::string RentalEndDate::GetRentalEndMonth()const { return m_endMonth; }


std::string RentalEndDate::GetRentalEndYear()const { return m_endYear; }


EndTime RentalEndDate::GetRentalEndTime()const { return m_EndTime; }


//--------------------------------------------------------------------------