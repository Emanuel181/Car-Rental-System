#pragma once
#include "Customer.h"
#include "LocationAddress.h"
#include "ContactClass.h"
#include "Car.h"


class CompanyBranches
{
private:
    std::string m_branchName;
    std::string m_countryName;
    std::string m_cityName;
    std::string m_reviews;
    unsigned long long m_numberOfCarsAvaible;
    double m_branchMark;
    std::vector <Customer> m_branchCustomers;
    LocationAddress m_locationAddress;
    std::vector <Car> m_branchCars;
    ContactClass m_contactClass;
public:
    CompanyBranches();
    std::string GetBranchName()const;
    std::string GetCountryName()const;
    std::string GetCityName()const;
    std::string GetReviews()const;
    unsigned long long GetNumberOfCarsAvaible()const;
    double GetBranchMark()const;
    std::vector <Customer> GetBranchCustomers()const;
    LocationAddress GetLocationAddress() const;
    std::vector <Car> GetBranchCars() const;
    ContactClass GetContactClass() const;
};

