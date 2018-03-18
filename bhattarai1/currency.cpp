// File:      currency.cpp
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 1
// Date:      1/19/2016

// This file contains implementation of the Currency class.

#include <cmath>
#include <iomanip>
#include "currency.h"
using namespace std;

// set static members of Currency class to default values
CentsDisplay Currency::displayCents = ShowCents;
DollarSignDisplay Currency::displaySign = ShowDollarSign;

// assign value of c to displayCents
void Currency::setFormat(CentsDisplay c)
{
	displayCents = c;
}

// assign value of d to displaySign
void Currency::setFormat(DollarSignDisplay d)
{
	displaySign = d;
}

// current value of displaySign
DollarSignDisplay Currency::getSignDisplay()
{
	return Currency::displaySign;
}

// current value of displayCents
CentsDisplay Currency::getCentsDisplay()
{
	return Currency::displayCents;
}

/*
 * constructor that takes a double parameter
 * if no parameter is given, amount is assigned default value 0 
 */
Currency::Currency(double amount)
{
	// constructor is called without parameters
	// default value 0 is used for dollars and cents  
	if (amount == 0)
		dollars = cents = 0;
	
	// whole part of amount is assigned to dollars
	// fractional part is rounded and assigned to cents
	else
	{
		dollars = (int)amount;
		cents = roundf((amount - dollars) * 100);
	}
}

/*
 * constructor that takes a Currency object parameter
 * copies values of c's members to members of this object
 */
Currency::Currency(const Currency& c)
{
	dollars = c.getDollars();
	cents = c.getCents();
}

long Currency::getDollars() const
{
	return dollars;
}

short Currency::getCents() const
{
	return cents;
}

// get the full currency value as a double
double Currency::getValue() const
{
	return dollars + cents * .01 ;
}

// relational operators
bool Currency::operator==(const Currency& c) const
{
	return getValue() == c.getValue();
}

bool Currency::operator!=(const Currency& c) const
{
	return !(*this == c);
}

bool Currency::operator<(const Currency& c) const
{
	return getValue() < c.getValue();
}

bool Currency::operator>(const Currency& c) const
{
	return *this != c && *this < c;
}

bool Currency::operator<=(const Currency& c) const
{
	return !(*this > c);
}

bool Currency::operator>=(const Currency& c) const
{
	return !(*this < c);
}
// end relational operators

// arithmetic operators
Currency Currency::operator+(const Currency& c) const
{
	return Currency(getValue() + c.getValue());
}

Currency Currency::operator-(const Currency& c) const
{
	return *this + -(c.getValue());
}

Currency Currency::operator*(double amount) const
{
	return Currency(getValue() * amount);
}

Currency Currency::operator/(double amount) const
{
	return *this * (1 / amount);
}
// end arithmetic operators

// ostream operator
ostream& operator<<(ostream& o, const Currency& c)
{
	if (Currency::getSignDisplay() == ShowDollarSign)
		o << "$";
	
	if (Currency::getCentsDisplay() == ShowCents)
		o << c.getValue();
	else if (Currency::getCentsDisplay() == Round)
		o << roundf(c.getValue());
	else if (Currency::getCentsDisplay() == Truncate)
		o << trunc(c.getValue());
	
	return o;
} 
