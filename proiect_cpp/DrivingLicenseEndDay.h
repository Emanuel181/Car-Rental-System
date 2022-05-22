#pragma once
#include <string>


class DrivingLicenseEndDay
{
private:
    std::string m_endDay;
    std::string m_endMonth;
    std::string m_endYear;
public:
    std::string GetEndDay()const;
    std::string GetEndMonth()const;
    std::string GetEndYear()const;
};

