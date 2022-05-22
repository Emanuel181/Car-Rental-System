#pragma once
#include "CarReview.h"
#include <string>

class Car {

private:
	std::string m_make, m_color,m_transmission,m_type;
	int m_bhp, m_engineType, m_numberDoors, m_numberSeats;
	double m_consumption;
	bool m_availability;
	int m_pricePerDay, m_deposit, m_advancePayment;
	CarReview m_carReview;
public:
	std::string GetCarMake() const;
	std::string GetCarColor() const;
	std::string GetCarTransmission() const;
	std::string GetCarType() const;
	int GetCarHorsepower() const;
	int GetCarEngineType() const;
	int GetCarNumberOfDoors() const;
	int GetCarNumberOfSeats() const;
	double GetCarConsumption() const;
	bool GetCarAvailability() const;
	int GetCarPrice() const;
	int GetCarDeposit() const;
	int GetCarAdvancePayment() const;
	CarReview GetCarReview() const;
};