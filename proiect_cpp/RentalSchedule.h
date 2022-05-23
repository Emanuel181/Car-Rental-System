#pragma once
#include "RentalStartDate.h"
#include "RentalEndDate.h"


class RentalSchedule
{
private:
    RentalStartDate m_rentalStartDate;
    RentalEndDate m_rentalEndDate;
public:
    RentalSchedule(RentalStartDate,RentalEndDate);
    RentalSchedule();
    RentalStartDate GetRentalStartDate()const;
    RentalEndDate GetRentalEndDate()const;
};

