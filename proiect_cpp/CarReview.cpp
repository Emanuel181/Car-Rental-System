#include "CarReview.h"

CarReview::CarReview(double value, double cleanliness, double comfort, double carCondition, double overallMark, const std::string review)
{
	m_value = value;
	m_cleanliness = cleanliness;
	m_comfort = comfort;
	m_carCondition = carCondition;
	m_overallMark = overallMark;
	m_review = review;
}

CarReview::CarReview()
{
	m_value = 10;
	m_cleanliness = 10;
	m_comfort = 10;
	m_carCondition = 10;
	m_overallMark = 10;
	m_review = "very good";
}

double CarReview::GetCarValue() const {
	return m_value;
}

double CarReview::GetCarCleanliness() const {
	return m_cleanliness;
}

double CarReview::GetCarComfort() const {
	return m_comfort;
}

double CarReview::GetCarCondition() const {
	return m_comfort;
}

double CarReview::GetCarOverallMark() const {
	return m_overallMark;
}

std::string CarReview::GetCarReview() const {
	return m_review;
}