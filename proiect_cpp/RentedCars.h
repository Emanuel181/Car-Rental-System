#pragma once


void ViewRentedCars(SystemClass mainOBJ, Customer customer, std::vector<std::string>branchesList)
{
    Sleep(0.016);
    system("cls");
    std::cout << "\t[1] Drop a car\n";
    std::cout << "\t[2] View rented cars at the moment\n";
    std::cout << "\t[3] Go to main menu\n";
    std::cout << "\tYour option:\n";
    std::string input;
    while (1)
    {
        std::cout << "\t";
        std::cin >> input;
        std::cin.ignore();
        if (InputValid(input))
        {
            int option = stoi(input);
            Customer customer;
            if (option <= 3)
            {
                if (option == 1)
                {
                    Sleep(0.016);
                    system("cls");
                    DropCar(mainOBJ, branchesList);
                    ClientOptions(mainOBJ, branchesList);
                    break;
                }
                if (option == 2)
                {
                    ViewCars(mainOBJ, branchesList);

                    ClientOptions(mainOBJ, branchesList);
                    break;
                }
                if (option == 3)
                {
                    Sleep(0.016);
                    system("cls");
                    ClientOptions(mainOBJ, branchesList);
                    break;
                }
            }
            else
            {
                std::cout << "\tYour option is invalid\n";
                std::cout << "\tTry again\n";
            }
        }
        else
        {
            std::cout << "\tYour option is invalid\n";
            std::cout << "\tTry again\n";
        }
    }
}

void CollectData(std::string& firstname, std::string& lastname, std::string& companyName, std::vector<std::string>branchesList)
{
    std::cout << "\tFirstname: ";
    while (1)
    {
        std::getline(std::cin, firstname);
        std::cout << "\n\t";
        if (validWord(firstname) == true)
            break;
        else
        {
            std::cout << "The name introduced is not valid.\n";
            std::cout << "\tTry again.\n\n\t";
        }
    }

    std::cout << "Lastame: ";
    while (1)
    {
        std::getline(std::cin, lastname);
        std::cout << "\n\t";
        if (validWord(lastname) == true)
            break;
        else
        {
            std::cout << "The name introduced is not valid.\n";
            std::cout << "\tTry again.\n\n\t";
        }
    }

    std::cout << "Company name: ";
    while (1)
    {
        std::getline(std::cin, companyName);
        std::cout << "\n\t";
        if (FirmExists(branchesList, companyName) == true)
            break;
        else
        {
            std::cout << "The company name introduced does not exist.\n";
            std::cout << "\tTry again.\n\n\t";
        }
    }
}


void GetCarData(std::string& make, std::string& color, std::string& transmission, std::string& type, std::string& engineType)
{
    std::ifstream fileCars("RentedCars.txt");
    char* line = new char[500];
    int count = 0;
    while (fileCars >> line)
    {
        char* p = strtok(line, ";");
        int nr = 0;
        std::string fname = p;
        p = strtok(NULL, ";");
        std::string lname = p;
        p = strtok(NULL, ";");
        std::string cname = p;
        p = strtok(NULL, ";");
        while (p)
        {
            switch (nr)
            {
            case 0:
                make = p;
                break;
            case 1:
                color = p;
                break;
            case 2:
                transmission = p;
                break;
            case 3:
                type = p;
                break;
            case 4:
                engineType = p;
                break;
            }
            p = strtok(NULL, ";");
            nr++;
        }
    }
}


void DropCar(SystemClass mainOBJ, std::vector<std::string>branchesList)
{
    Sleep(0.2);
    system("cls");
    int lineIndex = 0;
    std::string firstname = "", lastname = "", companyName = "";
    CollectData(firstname, lastname, companyName, branchesList);
    std::cout << "Please wait...\n";
    Sleep(2000);
    system("cls");

    std::cout << "\tWhich of the following cars would you like to drop?\n\tYou should introduce the id\n\n";
    std::string make = "", color = "", transmission = "", type = "", engineType = "", review = "", id = "";
    int bhp = 0, numberDoors = 0, numberSeats = 0, pricePerDay = 0, deposit = 0, advancePayment = 0;
    double consumption = 0, value = 0, overallMark = 0, cleanliness = 0, comfort = 0, condition = 0;
    bool availability = false;
    std::ifstream fileCars("RentedCars.txt");
    char* line = new char[500];
    int count = 0;
    while (fileCars >> line)
    {
        char* p = strtok(line, ";");
        int nr = 0;
        id = p;
        p = strtok(NULL, ";");
        std::string fname = p;
        p = strtok(NULL, ";");
        std::string lname = p;
        p = strtok(NULL, ";");
        std::string cname = p;
        p = strtok(NULL, ";");
        if (firstname == fname && lastname == lname && companyName == cname)
        {
            while (p)
            {
                switch (nr)
                {
                case 0:
                    make = p;
                    break;
                case 1:
                    color = p;
                    break;
                case 2:
                    transmission = p;
                    break;
                case 3:
                    type = p;
                    break;
                case 4:
                    engineType = p;
                    break;
                case 5:
                    bhp = CreateNumber(p);
                    break;
                case 6:
                    numberDoors = CreateNumber(p);
                    break;
                case 7:
                    numberSeats = CreateNumber(p);
                    break;
                case 8:
                    consumption = std::stod(p);
                    break;
                case 9:
                    if (p[0] == '0')
                        availability = false;
                    else
                        availability = true;
                    break;
                case 10:
                    pricePerDay = CreateNumber(p);
                    break;
                case 11:
                    deposit = CreateNumber(p);
                    break;
                case 12:
                    advancePayment = CreateNumber(p);
                    break;
                case 13:
                    value = std::stod(p);
                    break;
                case 14:
                    cleanliness = std::stod(p);
                    break;
                case 15:
                    comfort = std::stod(p);
                    break;
                case 16:
                    condition = std::stod(p);
                    break;
                case 17:
                    overallMark = std::stod(p);
                    break;
                case 18:
                    review = p;
                    break;
                }
                p = strtok(NULL, ";");
                nr++;
            }
            CarReview carReview(value, cleanliness, comfort, condition, overallMark, review);
            Car car(make, color, transmission, type, bhp, engineType, numberDoors, numberSeats, consumption, availability, pricePerDay, deposit, advancePayment, carReview);
            std::cout << "\tCar number: " << count + 1 << "\n";
            std::cout << "\tId: " << id << "\n";
            std::cout << car << "\n";
            count++;
        }
    }
    if (count == 0)
    {
        std::cout << "\n\tThere are no cars associated to this name\n\tPlease wait...\n";
        Sleep(4000);
        return;
    }
    std::string userInput = "";
    int option = 0;
    while (1)
    {
        std::cout << "\tIntroduce the id: ";
        std::cin >> userInput;
        if (containsOnlyDigits(userInput) == true)
        {
            break;
        }
        else
        {
            std::cout << "\n";
            std::cout << "\tThe option introduced is not valid.\n";
            std::cout << "\tTry again.\n";
        }
    }

    line[0] = 0;
    std::vector<std::string>linesList;
    int nr = 1;
    std::ifstream fin("RentedCars.txt");
    while (fin >> line)
    {
        char* aux = new char[500];
        strcpy(aux, line);
        char* p = strtok(aux, ";");
        int nr = 0;
        std::string carId = p;
        if (userInput != carId)
            linesList.push_back(line);
        else
        {
            ChangeAvailabilityOfCar(line, mainOBJ);
        }
    }
    std::ofstream rentedCarsFile;
    rentedCarsFile.open("RentedCars.txt", std::ios::out);
    for (int i = 0; i < linesList.size(); i++)
    {
        rentedCarsFile << linesList[i] << "\n";
    }
    rentedCarsFile.close();
    delete[] line;
    system("cls");
    std::cout << "\tThe car has been dropped.\n";
    std::cout << "\tPlease wait...\n";
    Sleep(2000);
}


void ViewCars(SystemClass mainOBJ, std::vector<std::string>branchesList)
{
    Sleep(0.2);
    system("cls");
    std::string firstname = "", lastname = "", companyName = "";
    CollectData(firstname, lastname, companyName, branchesList);
    std::cout << "Please wait...\n";
    Sleep(2000);
    system("cls");
    std::cout << "\tHere are the cars:\n\n";
    std::string make = "", color = "", transmission = "", type = "", engineType = "", review = "", id = "";
    int bhp = 0, numberDoors = 0, numberSeats = 0, pricePerDay = 0, deposit = 0, advancePayment = 0;
    double consumption = 0, value = 0, overallMark = 0, cleanliness = 0, comfort = 0, condition = 0;
    bool availability = false;
    std::ifstream fileCars("RentedCars.txt");
    char* line = new char[500];
    int count = 0;
    while (fileCars >> line)
    {
        char* p = strtok(line, ";");
        int nr = 0;
        id = p;
        p = strtok(NULL, ";");
        std::string fname = p;
        p = strtok(NULL, ";");
        std::string lname = p;
        p = strtok(NULL, ";");
        std::string cname = p;
        p = strtok(NULL, ";");
        if (firstname == fname && lastname == lname && companyName == cname)
        {
            while (p)
            {
                switch (nr)
                {
                case 0:
                    make = p;
                    break;
                case 1:
                    color = p;
                    break;
                case 2:
                    transmission = p;
                    break;
                case 3:
                    type = p;
                    break;
                case 4:
                    engineType = p;
                    break;
                case 5:
                    bhp = CreateNumber(p);
                    break;
                case 6:
                    numberDoors = CreateNumber(p);
                    break;
                case 7:
                    numberSeats = CreateNumber(p);
                    break;
                case 8:
                    consumption = std::stod(p);
                    break;
                case 9:
                    if (p[0] == '0')
                        availability = false;
                    else
                        availability = true;
                    break;
                case 10:
                    pricePerDay = CreateNumber(p);
                    break;
                case 11:
                    deposit = CreateNumber(p);
                    break;
                case 12:
                    advancePayment = CreateNumber(p);
                    break;
                case 13:
                    value = std::stod(p);
                    break;
                case 14:
                    cleanliness = std::stod(p);
                    break;
                case 15:
                    comfort = std::stod(p);
                    break;
                case 16:
                    condition = std::stod(p);
                    break;
                case 17:
                    overallMark = std::stod(p);
                    break;
                case 18:
                    review = p;
                    break;
                }
                p = strtok(NULL, ";");
                nr++;
            }
            CarReview carReview(value, cleanliness, comfort, condition, overallMark, review);
            Car car(make, color, transmission, type, bhp, engineType, numberDoors, numberSeats, consumption, availability, pricePerDay, deposit, advancePayment, carReview);
            std::cout << "\tCar number: " << count + 1 << "\n";
            std::cout << car << "\n";
            count++;
        }
    }
    if (count == 0)
    {
        std::cout << "\n\tThere are no cars associated to this name\n";
        std::cout << "\n\t";
        system("pause");
        return;
    }
    std::cout << "\t";
    system("pause");
}


void ChangeAvailabilityOfCar(char* line, SystemClass mainOBJ)
{
    std::string make = "", color = "", transmission = "", type = "", engineType = "", review = "", id = "";
    int bhp = 0, numberDoors = 0, numberSeats = 0, pricePerDay = 0, deposit = 0, advancePayment = 0, nr = 0;
    double consumption = 0, value = 0, overallMark = 0, cleanliness = 0, comfort = 0, condition = 0;
    bool availability = false;
    char* p = strtok(line, ";");
    id = p;
    p = strtok(NULL, ";");
    std::string fname = p;
    p = strtok(NULL, ";");
    std::string lname = p;
    p = strtok(NULL, ";");
    std::string cname = p;
    p = strtok(NULL, ";");
    while (p)
    {
        switch (nr)
        {
        case 0:
            make = p;
            break;
        case 1:
            color = p;
            break;
        case 2:
            transmission = p;
            break;
        case 3:
            type = p;
            break;
        case 4:
            engineType = p;
            break;
        case 5:
            bhp = CreateNumber(p);
            break;
            /*case 6:
                numberDoors = CreateNumber(p);
                break;
            case 7:
                numberSeats = CreateNumber(p);
                break;
            case 8:
                consumption = std::stod(p);
                break;
            case 9:
                if (p[0] == '0')
                    availability = false;
                else
                    availability = true;
                break;
            case 10:
                pricePerDay = CreateNumber(p);
                break;
            case 11:
                deposit = CreateNumber(p);
                break;
            case 12:
                advancePayment = CreateNumber(p);
                break;
            case 13:
                value = std::stod(p);
                break;
            case 14:
                cleanliness = std::stod(p);
                break;
            case 15:
                comfort = std::stod(p);
                break;
            case 16:
                condition = std::stod(p);
                break;
            case 17:
                overallMark = std::stod(p);
                break;
            case 18:
                review = p;
                break;
            */
        }
        p = strtok(NULL, ";");
        nr++;
    }
    std::vector<std::vector<CompanyBranches>>arr = mainOBJ.GetCompanyBranches();
    std::vector<Car>arrCars;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            std::string name = arr[i][j].GetBranchName();
            if (name == cname)
            {
                arrCars = arr[i][j].GetBranchCars();
                break;
            }
        }
    }
    for (int i = 0; i < arrCars.size(); i++)
    {
        if (arrCars[i].GetCarMake() == make && arrCars[i].GetCarColor() == color && arrCars[i].GetCarTransmission() == transmission
            && arrCars[i].GetCarType() == type && arrCars[i].GetCarEngineType() == engineType && arrCars[i].GetCarHorsepower() == bhp)
        {
            arrCars[i].SetCarAvailability(true);
        }
    }
}