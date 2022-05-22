#pragma once
#include <string>


class StartTime
{
private:
    std::string m_startHour;
    std::string m_startMinutes;
public:
    std::string GetStartHour()const;
    std::string GetStartMinutes()const;
};

