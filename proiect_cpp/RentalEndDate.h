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
    RentalEndDate(const std::string, const std::string, const std::string, EndTime);
    RentalEndDate();
    std::string GetRentalEndDay()const;
    std::string GetRentalEndMonth()const;
    std::string GetRentalEndYear()const;
    EndTime GetRentalEndTime()const;
    void SetEndDay(const std::string);
    void SetEndMonth(const std::string);
    void SetEndYear(const std::string);
};

