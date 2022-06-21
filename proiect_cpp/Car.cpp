#include "Car.h"


Car::Car(const std::string make, const std::string color, const std::string transmission, const std::string type, int bhp, const std::string engineType, int numberDoors, int numberSeats, double consumption, bool availability, int pricePerDay, int deposit, int advancePayment, CarReview carReview)
{
	m_make = make;
	m_color = color;
	m_transmission = transmission;
	m_type = type;
	m_bhp = bhp;
	m_engineType = engineType;
	m_numberDoors = numberDoors;
	m_numberSeats = numberSeats;
	m_consumption = consumption;
	m_availability = availability;
	m_pricePerDay = pricePerDay;
	m_deposit = deposit;
	m_advancePayment = advancePayment;
	m_carReview = carReview;
}


Car::Car()
{
	m_make = "";
	m_color = "";
	m_transmission = "";
	m_type = "";
	m_engineType = "";
	m_bhp = 0;
	m_numberDoors = 0;
	m_numberSeats = 0;
	m_consumption = 0.0;
	m_availability = true;
	m_pricePerDay = 0;
	m_deposit = 0;
	m_advancePayment = 0;
	m_carReview.SetCarCondition(0.0);
	m_carReview.SetCleanliness(0.0);
	m_carReview.SetComfort(0.0);
	m_carReview.SetOverallMark(0.0);
	m_carReview.SetValue(0.0);
	m_carReview.SetCarReview("\0");
}


std::string Car::GetCarMake() const {
	return m_make;
}


std::string Car::GetCarColor() const {
	return m_color;
}


std::string Car::GetCarTransmission() const {
	return m_transmission;
}


std::string Car::GetCarType() const {
	return m_type;
}


int Car::GetCarHorsepower() const {
	return m_bhp;
}


std::string Car::GetCarEngineType() const {
	return m_engineType;
}


int Car::GetCarNumberOfDoors() const {
	return m_numberDoors;
}


int Car::GetCarNumberOfSeats() const {
	return m_numberSeats;
}


double Car::GetCarConsumption() const {
	return m_consumption;
}


bool Car::GetCarAvailability() const {
	return m_availability;
}


int Car::GetCarPrice() const {
	return m_pricePerDay;
}


int Car::GetCarDeposit() const {
	return m_deposit;
}


int Car::GetCarAdvancePayment() const {
	return m_advancePayment;
}


CarReview Car::GetCarReview() const {
	return m_carReview;
}


void Car::SetCarAvailability(bool value)
{
	m_availability = value;
}


std::ostream& operator << (std::ostream& COUT, const Car& p)
{
	COUT << "\tMake: " << p.m_make<<"\n\tColor: "<<p.m_color<<"\n\tTransmission: "<<p.m_transmission<<"\n";
	COUT << "\tType: " << p.m_type << "\n\tEngine type: " << p.m_engineType << "\n\tHorsepower: " << p.m_bhp << "\n";
	COUT << "\tDoors: " << p.m_numberDoors << "\n\tSeats: " << p.m_numberSeats << "\n\tConsumption: " << p.m_consumption << "\n";
	if(p.m_availability==true)
		COUT << "\tAvailability: " << "yes";
	else
		COUT << "\tAvailability: " << "no";
	COUT<< "\n\tPrice per day: " << p.m_pricePerDay << "\n\tDeposit: " << p.m_advancePayment << "\n";
	
	p.GetCarReview().DisplayReviewDetails();
	return COUT;
}