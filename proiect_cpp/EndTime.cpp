#include "EndTime.h"


EndTime::EndTime(const std::string endHour, const std::string endMinutes)
{
	m_endHour = endHour;
	m_endMinutes = endMinutes;
}
 

EndTime::EndTime()
	:m_endHour{"17"}, m_endMinutes{"0"}
{}


// Getters

std::string EndTime::GetEndHour()const { return m_endHour; }


std::string EndTime::GetEndMinutes()const { return m_endMinutes; }


//----------------------------------------------------------------


//Setters


void EndTime::SetEndHour(const std::string init) { m_endHour = init; }


void EndTime::SetEndMinutes(const std::string init) { m_endMinutes = init; }


//-------------------------------------------------------