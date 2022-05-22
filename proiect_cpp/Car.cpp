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
	m_availability = availability;
	m_pricePerDay = pricePerDay;
	m_deposit = deposit;
	m_advancePayment = advancePayment;
	m_carReview = carReview;
}

Car::Car()
{
	m_make = "Dacia";
	m_color = "black";
	m_transmission = "manual";
	m_type = "economy";
	m_engineType = "petrol";
	m_bhp = 100;
	m_numberDoors = 5;
	m_numberSeats = 5;
	m_availability = true;
	m_pricePerDay = 100;
	m_deposit = 500;
	m_advancePayment = 0;
	m_carReview = nullptr;
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