#pragma once
#include "CarReview.h"
#include <string>

class Car {

private:
	std::string m_make, m_color,m_transmission,m_type, m_engineType;
	int m_bhp, m_numberDoors, m_numberSeats;
	double m_consumption;
	bool m_availability;
	int m_pricePerDay, m_deposit, m_advancePayment;
	CarReview m_carReview;
public:
	Car(const std::string, const std::string, const std::string, const std::string, int, const std::string , int, int, double, bool, int, int, int, CarReview);
	Car();
	std::string GetCarMake() const;
	std::string GetCarColor() const;
	std::string GetCarTransmission() const;
	std::string GetCarType() const;
	int GetCarHorsepower() const;
	std::string GetCarEngineType() const;
	int GetCarNumberOfDoors() const;
	int GetCarNumberOfSeats() const;
	double GetCarConsumption() const;
	bool GetCarAvailability() const;
	int GetCarPrice() const;
	int GetCarDeposit() const;
	int GetCarAdvancePayment() const;
	CarReview GetCarReview() const;
	friend std::ostream& operator << (std::ostream&, const Car&);

};