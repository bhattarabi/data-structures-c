// File:      currency.h
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 1
// Date:      1/19/2016

/*
This file contains the specifications for the Currency class.
*/

#ifndef _CURRENCY_H_
#define _CURRENCY_H_

#include <iostream>
#include <string>

using namespace std;

// format specifier for if and how cents are displayed
enum CentsDisplay {ShowCents, Truncate, Round};

// format specifier for if a dollar sign is displayed
enum DollarSignDisplay {ShowDollarSign, NoDollarSign};

/*
 * model a currency value that has a whole part and a fractional part
 */ 
class Currency
{	
public:
	/* contructor that takes a double argument
	 * uses default value 0 if no parameters are given
	 */
	Currency(double = 0);
	
	/* constructor that takes a Currency object argument
	 * copies the attributes of the given Currency into this Currency
	 */
	Currency(const Currency&);
	
	// retrieve the whole part of the currency
	long getDollars() const;
	
	// retrieve the fractional part as an integer
	short getCents() const;	
	
	// retrieve the full value of the currency
	double getValue() const;	
	
	// relational operators
	bool operator==(const Currency&) const;
	bool operator<(const Currency&) const;
	bool operator>(const Currency&) const;
	bool operator<=(const Currency&) const;
	bool operator>=(const Currency&) const;
	bool operator!=(const Currency&) const;
	
	// arithmetic operators
	Currency operator+(const Currency&) const;
	Currency operator-(const Currency&) const;
	Currency operator*(double) const;
	Currency operator/(double) const;
	
	/*
	 * set if and how the cents are displayed according to
	 * value of CentsDisplay
	 * default is ShowCents
	 * post-condition: the value of static member displayCents 
	 * 					is set to that of the given argument
	 * 
	 */
	static void setFormat(CentsDisplay);
	
	/*
	 * show or hide dollar sign, according to the
	 * value of DollarSignDisplay
	 * default is ShowDollarSign
	 * post-condition: the value of static member displaySign 
	 * 					is set to that of the given argument
	 * 
	 */
	static void setFormat(DollarSignDisplay);
	
	// state of static output format specifiers
	static DollarSignDisplay getSignDisplay();
	static CentsDisplay getCentsDisplay();
private:
	long dollars;
	short cents;
	static CentsDisplay displayCents;
	static DollarSignDisplay displaySign;
};

ostream& operator<<(ostream&, const Currency&);

#endif