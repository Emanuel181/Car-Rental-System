#pragma once
#include <string>

class CarReview {
	
private:
	double m_value, m_cleanliness, m_comfort, m_carCondition;
	double m_overallMark;
	/*
	awful/ good/ very good
	*/
	std::string review;

public:
	double GetCarValue() const;
	double GetCarCleanliness() const;
	double GetCarComfort() const;
	double GetCarCondition() const;
	double GetCarOverallMark() const;
	std::string GetCarReview() const;
};