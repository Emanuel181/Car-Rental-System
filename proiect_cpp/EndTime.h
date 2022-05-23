#pragma once
#include <string>


class EndTime
{
private:
    std::string m_endHour;
    std::string m_endMinutes;
public:
    EndTime(const std::string, const std::string);
    EndTime();
    std::string GetEndHour()const;
    std::string GetEndMinutes()const;
    void SetEndHour(const std::string);
    void SetEndMinutes(const std::string);
};

