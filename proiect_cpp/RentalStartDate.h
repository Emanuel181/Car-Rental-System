#pragma once
#include "StartTime.h"

class RentalStartDate
{
private:
    std::string m_startDay;
    std::string m_startMonth;
    std::string m_startYear;
    StartTime m_startTime;
public:
    std::string GetStartDay()const;
    std::string GetStartMonth()const;
    std::string GetStartYear()const;
    StartTime GetStartTime()const;
};

