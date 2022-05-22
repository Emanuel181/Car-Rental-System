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
    RentalStartDate(const std::string, const std::string, const std::string, StartTime);
    RentalStartDate();
    std::string GetStartDay()const;
    std::string GetStartMonth()const;
    std::string GetStartYear()const;
    StartTime GetStartTime()const;
};

