#pragma once
#include "CompanyBranches.h"


class SystemClass
{
private:
    static std::string m_nameOfHeadCompany;
    std::vector <CompanyBranches> m_companyBranches;

public:
    static std::string GetNameOfHeadCompany();
    std::vector <CompanyBranches> GetCompanyBranches()const;
};


std::string SystemClass::m_nameOfHeadCompany;
