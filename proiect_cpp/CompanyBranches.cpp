#include "CompanyBranches.h"
#include <iostream>
#include <string>


CompanyBranches::CompanyBranches(const std::string branchName, const std::string countryName, const std::string cityName,
                const std::string reviews, const std::string OBS, const unsigned long long numberOfCarsAvaible, const double branchMark, 
                const std::string streetName, const std::string streetNumber, const std::string streetPostalCode, 
                const std::string phoneNumber, const std::string email, const std::string managerName)
    :m_administratorOBS{"\0"}
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


std::ostream& operator << (std::ostream& COUT, const CompanyBranches& obj)
{
    COUT << "Company name: " << obj.GetBranchName() << '\n';
    COUT << "Country: " << obj.GetCountryName() << '\n';
    COUT << "City: " << obj.GetCityName() << '\n';
    COUT << "Reviews: \n";
    for (auto review : obj.GetReviews())
    {
        COUT << review << '\n';
    }
    COUT << "Observations from administrator: " << obj.GetAdministratorOBS() << '\n';
    COUT << "Number of cars avaible: " << obj.GetNumberOfCarsAvaible();
    COUT << "Branch mark: " << obj.GetBranchMark();
    COUT << obj.GetLocationAddress() << '\n';
    COUT << obj.GetContactClass() << '\n';

    return COUT;
}


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


std::string CompanyBranches::GetAdministratorOBS() const {return m_administratorOBS;}

//-----------------------------------------------------------------------------------------------


void CompanyBranches::setCarList(std::vector<Car>arrCars)
{
    m_branchCars = arrCars;
}


void CompanyBranches::setCustomerList(std::vector<Customer>arrCustomers)
{
    m_branchCustomers = arrCustomers;
}


void CompanyBranches::SetOBS(std::string OBS) { m_administratorOBS = OBS; }


