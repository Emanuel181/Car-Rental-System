#include "CompanyBranches.h"


CompanyBranches::CompanyBranches()
    :m_branchName{"\0"}, m_countryName{"\0"}, m_cityName{"\0"}, m_numberOfCarsAvaible{0}, m_branchMark{0.0}
{}


// Getters

std::string CompanyBranches::GetBranchName()const { return m_branchName; }


std::string CompanyBranches::GetCountryName()const { return m_countryName; }


std::string CompanyBranches::GetCityName()const { return m_cityName; }


std::string CompanyBranches::GetReviews()const { return m_reviews; }


unsigned long long CompanyBranches::GetNumberOfCarsAvaible()const { return m_numberOfCarsAvaible; }


double CompanyBranches::GetBranchMark()const { return m_branchMark; }


std::vector <Customer> CompanyBranches::GetBranchCustomers()const { return m_branchCustomers; }


LocationAddress CompanyBranches::GetLocationAddress() const {return m_locationAddress;}


std::vector <Car> CompanyBranches::GetBranchCars() const {return m_branchCars;}


ContactClass CompanyBranches::GetContactClass() const {return m_contactClass;}

//-----------------------------------------------------------------------------------------------

