#pragma once
#include <string>


class DrivingLicenseStartDay
{
private:
    std::string m_startDay;
    std::string m_startMonth;
    std::string m_startYear;
public:
    DrivingLicenseStartDay(const std::string, const std::string, const std::string);
    DrivingLicenseStartDay();
    std::string GetStartDay()const;
    std::string GetStartMonth()const;
    std::string GetStartYear()const;
};

