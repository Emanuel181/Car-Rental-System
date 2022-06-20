#include "SystemClass.h"


std::string SystemClass::m_nameOfHeadCompany;


// Getters

std::string SystemClass::GetNameOfHeadCompany() { return m_nameOfHeadCompany; }


std::vector <std::vector <CompanyBranches>> SystemClass::GetCompanyBranches()const { return m_companyBranches; }


//-----------------------------------------------------------------------------------------------------------


SystemClass::SystemClass(const static std::string nameOfHeadCompany, std::vector <CompanyBranches> obj)
{

    m_nameOfHeadCompany = nameOfHeadCompany;
    m_companyBranches.push_back(obj);
}


SystemClass::SystemClass()
{
    SetNameOfHeadCompany("\0");
}


void SystemClass::SetNameOfHeadCompany(const std::string Init) { m_nameOfHeadCompany = Init; }
