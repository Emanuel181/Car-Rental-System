#pragma once
#include "EndTime.h"
#include <string>


class RentalEndDate
{
private:
    std::string m_endDay;
    std::string m_endMonth;
    std::string m_endYear;
    EndTime m_EndTime;
public:
    std::string GetRentalEndDay()const;
    std::string GetRentalEndMonth()const;
    std::string GetRentalEndYear()const;
    EndTime GetRentalEndTime()const;
};

