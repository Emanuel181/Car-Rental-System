#pragma once
#include <string>


class EndTime
{
private:
    std::string m_endHour;
    std::string m_endMinutes;
public:
    std::string GetEndHour()const;
    std::string GetEndMinutes()const;
};

