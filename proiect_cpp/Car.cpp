#include "Car.h"

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

int Car::GetCarEngineType() const {
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