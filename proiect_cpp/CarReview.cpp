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


// Getters


double CarReview::GetCarValue() const
{
	return m_value;
}

double CarReview::GetCarCleanliness() const
{
	return m_cleanliness;
}

double CarReview::GetCarComfort() const
{
	return m_comfort;
}

double CarReview::GetCarCondition() const
{
	return m_comfort;
}

double CarReview::GetCarOverallMark() const
{
	return m_overallMark;
}

std::string CarReview::GetCarReview() const
{
	return m_review;

}


//----------------------------------------------------------------------



// Setters


void CarReview::SetValue(const double Init) { m_value = Init; }


void CarReview::SetOverallMark(const double Init) { m_overallMark = Init; }


void CarReview::SetCleanliness(const double Init) { m_cleanliness = Init; }


void CarReview::SetComfort(const double Init) { m_comfort = Init; }


void CarReview::SetCarCondition(const double Init) { m_carCondition = Init; }


void CarReview::SetCarReview(const std::string Init) { m_review = Init; }


//-----------------------------------------------------------------