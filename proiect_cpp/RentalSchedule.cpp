#include "RentalSchedule.h"


RentalSchedule::RentalSchedule(RentalStartDate rentalStartDate, RentalEndDate rentalEndDate)
{
	m_rentalStartDate = rentalStartDate;
	m_rentalEndDate = rentalEndDate;
}


RentalSchedule::RentalSchedule()
{

}

// Getters

RentalStartDate RentalSchedule::GetRentalStartDate()const { return m_rentalStartDate; }


RentalEndDate RentalSchedule::GetRentalEndDate()const { return m_rentalEndDate; }


//----------------------------------------------------------------------------------------