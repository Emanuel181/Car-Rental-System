#include "StartTime.h"


StartTime::StartTime(const std::string startHour, const std::string startMinutes)
{
	m_startHour = startHour;
	m_startMinutes = startMinutes;
}


StartTime::StartTime()
	:m_startHour{"8"}, m_startMinutes{"0"}
{}


// Getters

std::string StartTime::GetStartHour()const { return m_startHour; }


std::string StartTime::GetStartMinutes()const { return m_startMinutes; }


//-------------------------------------------------------------------------------