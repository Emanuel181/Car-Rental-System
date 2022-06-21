#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class CarReview {
	
private:
	double m_value;
	double m_overallMark;
	double m_cleanliness;
	double m_comfort;
	double m_carCondition;
	/*
	awful/ good/ very good
	*/
	std::string m_review;

public:
	CarReview(double, double, double, double, double, const std::string);
	CarReview();
	double GetCarValue() const;
	double GetCarCleanliness() const;
	double GetCarComfort() const;
	double GetCarCondition() const;
	double GetCarOverallMark() const;
	std::string GetCarReview() const;

	void SetValue(const double);
	void SetOverallMark(const double);
	void SetCleanliness(const double);
	void SetComfort(const double);
	void SetCarCondition(const double);
	void SetCarReview(const std::string);

	void DisplayReviewDetails();
};