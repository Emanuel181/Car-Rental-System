#include "CompanyBranches.h"


CompanyBranches::CompanyBranches(const std::string branchName, const std::string countryName, const std::string cityName,
                const std::string reviews, const unsigned long long numberOfCarsAvaible, const double branchMark, 
                const std::string streetName, const std::string streetNumber, const std::string streetPostalCode, 
                const std::string phoneNumber, const std::string email, const std::string managerName)
{
    m_branchName = branchName;
    m_countryName = countryName;
    m_cityName = cityName;

    m_reviews = reviews;
    m_numberOfCarsAvaible = numberOfCarsAvaible;
    m_branchMark = branchMark;
    LocationAddress m_locationAddress(streetName, streetNumber, streetPostalCode); // ? m_locationAddress(streetName, streetNumber, streetPostalCode); - sa nu stergi
    ContactClass m_contactClass(phoneNumber, email, managerName); // ? m_contactClass(phoneNumber, email, managerName); - sa nu stergi
}


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

