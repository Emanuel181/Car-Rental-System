#include "RentalSchedule.h"


RentalSchedule::RentalSchedule(RentalStartDate rentalStartDate, RentalEndDate rentalEndDate)
{
	m_rentalStartDate = rentalStartDate;
	m_rentalEndDate = rentalEndDate;
}


RentalSchedule::RentalSchedule()
{
	m_rentalStartDate.SetStartDay("\0");
	m_rentalStartDate.SetStartMonth("\0");
	m_rentalStartDate.SetStartYear("\0");
	m_rentalStartDate.GetStartTime().SetStartHour("\0");
	m_rentalStartDate.GetStartTime().SetStartMinutes("\0");

	m_rentalEndDate.SetEndDay("\0");
	m_rentalEndDate.SetEndMonth("\0");
	m_rentalEndDate.SetEndYear("\0");
	m_rentalEndDate.GetRentalEndTime().SetEndHour("\0");
	m_rentalEndDate.GetRentalEndTime().SetEndMinutes("\0");
}


// Getters

RentalStartDate RentalSchedule::GetRentalStartDate()const { return m_rentalStartDate; }


RentalEndDate RentalSchedule::GetRentalEndDate()const { return m_rentalEndDate; }


//----------------------------------------------------------------------------------------