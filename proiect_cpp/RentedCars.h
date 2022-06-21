#pragma once


void ViewRentedCars(SystemClass mainOBJ,Customer customer,std::vector<std::string>branchesList)
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
			if (option <= 2)
			{
				if (option == 1)
				{
					Sleep(0.016);
					system("cls");
					DropCar(customer);
					break;
				}
				if (option == 2)
				{
					ViewCars(customer);
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


void DropCar(Customer customer)
{
	Sleep(0.2);
	system("cls");
    int lineIndex = 0;
	std::cout << "\tWhich of the following cars would you like to drop?\n";
    std::string make = "", color = "", transmission = "", type = "", engineType = "", review = "";
    int bhp = 0, numberDoors = 0, numberSeats = 0, pricePerDay = 0, deposit = 0, advancePayment = 0;
    double consumption = 0, value = 0, overallMark = 0, cleanliness = 0, comfort = 0, condition = 0;
    bool availability = false;
    std::ifstream fileCars("RentedCars.txt");
    char* line = new char[500];
    int count = 1;
    while (fileCars >> line)
    {
        line[0] = 0;
        char* p = strtok(line, ";");
        int nr = 0;
        std::string firstname = p;
        std::string lastname = p;
        if (firstname == customer.GetCustomerIdentificationInfos().GetCustomerFirstName() && lastname == customer.GetCustomerIdentificationInfos().GetCustomerLastName())
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
                    bhp = CreateNumber(p);
                    break;
                case 5:
                    engineType = p;
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
            std::cout << "\tCar number: " << count << "\n";
            std::cout << car << "\n";
            count++;
        }
    }
    std::string userInput = "";
    int option = 0;
    while (1)
    {
        std::cout << "\t";
        std::cin >> userInput;
        if (containsOnlyDigits(userInput) == true)
        {
            option = std::stoi(userInput);
            if (option > count)
            {
                std::cout << "\n";
                std::cout << "\tThe option introduced is not valid.\n";
                std::cout << "\tTry again.\n";
            }
            else
            {
                break;
            }
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
    while (fileCars >> line)
    {
        if (nr != lineIndex)
            linesList.push_back(line);
        nr++;
    }
    std::ofstream rentedCarsFile;
    rentedCarsFile.open("RentedCars.txt", std::ios::app);
    for (int i = 0; i < linesList.size(); i++)
    {
        rentedCarsFile << linesList[i] << "\n";
    }
    rentedCarsFile.close();
    delete[] line;
}


void ViewCars(Customer customer)
{
	std::string firstname = "", lastname = "";

}