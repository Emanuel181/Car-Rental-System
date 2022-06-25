#pragma once
#include <fstream>
#include "CompanyBranches.h"
#include "Windows.h"


class SystemClass
{
private:
    static std::string m_nameOfHeadCompany;
    std::vector < std::vector <CompanyBranches> > m_companyBranches;

public:
    static std::string GetNameOfHeadCompany();
    std::vector < std::vector <CompanyBranches> > GetCompanyBranches()const;
    SystemClass();
    SystemClass(const static std::string, std:: vector <CompanyBranches>);
    static void SetNameOfHeadCompany(const std::string);
	void SetAdministratorOBS();
    void Registrate(std::vector<std::string>& branchesList);
    void DeleteBranch();
    void AddCustomerToBranch(Customer , std::string );
};

