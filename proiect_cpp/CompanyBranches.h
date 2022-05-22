#pragma once
#include "Customer.h"


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
public:
    std::string GetBranchName()const;
    std::string GetCountryName()const;
    std::string GetCityName()const;
    std::string GetReviews()const;
    unsigned long long GetNumberOfCarsAvaible()const;
    double GetBranchMark()const;
    std::vector <Customer> GetBranchCustomers()const;
};

