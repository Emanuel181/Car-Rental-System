#pragma once
#include "RentalStartDate.h"
#include "RentalEndDate.h"


class RentalSchedule
{
private:
    RentalStartDate m_rentalStartDate;
    RentalEndDate m_rentalEndDate;
public:
    RentalStartDate GetRentalStartDate()const;
    RentalEndDate GetRentalEndDate()const;
};

