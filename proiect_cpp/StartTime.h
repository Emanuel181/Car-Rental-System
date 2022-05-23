#pragma once
#include <string>


class StartTime
{
private:
    std::string m_startHour;
    std::string m_startMinutes;
public:
    StartTime(const std::string, const std::string);
    StartTime();
    std::string GetStartHour()const;
    std::string GetStartMinutes()const;
    void SetStartHour(const std::string);
    void SetStartMinutes(const std::string);
};

