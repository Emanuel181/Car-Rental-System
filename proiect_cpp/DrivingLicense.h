#pragma once
#include "DrivingLicenseStartDay.h"
#include "DrivingLicenseEndDay.h"


class DrivingLicense
{
private:
    DrivingLicenseStartDay m_drivingLicenseStartDay;
    DrivingLicenseEndDay m_drivingLicenseEndDay;
    std::string m_isAbleToDrive;
public:
    DrivingLicenseStartDay GetDrivingLicenseStartDay()const;
    DrivingLicenseEndDay GetDrivingLicenseEndDay()const;
    std::string GetIsAbleToDrive()const;
};

