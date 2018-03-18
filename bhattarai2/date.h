// File:      date.h
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 2
// Date:      2/13/2016

// This file contains specifications for class Date.

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include "dateexception.h"

using namespace std;

namespace DateNameSpace 
{	
	// check if the year is a leap year
	bool leapYear(int);

	/* Format specifier for how date objects are displayed.
	* For example, consider the date 2/13/2016(Saturday). 
	* The different output formats would display:
	* NUMERIC	 : 2/13/2016
	* TEXT   	 : February 13, 2016
	* DAYTEXT	 : Saturday, February 13, 2016
	* DAYNUMERIC	 : Saturday, 2/13/2016 
	* **************Default is NUMERIC****************
	*/
	enum DateOutput {NUMERIC, TEXT, DAYTEXT, DAYNUMERIC};

	/* Specifier for the unit used for all date arithmetic operations.
	* **************Default is DAYS********************
	*/
	enum DateArith {DAYS, YEARS};

	// Class that models a Gregorian calendar date.
	class Date{
	public:
		/* Default constructor 
		* Initializes date object with the current system date
		*/
		Date();
		
		/* Constructor that takes 3 int arguments for month, day,
		* and year in that order. 
		* Initializes date object to the date month/day/year.
		* Throws DateException if given arguments do not make up a 
		* valid Gregorian date.
		*/
		Date (int, int, int) throw (DateException);

		/* Set the date to the given arguments in the order mm/dd/yy.
		* Throws DateException if given arguments do not make up a 
		* valid Gregorian date.
		*/
		void setDate(int, int, int) throw (DateException);	
		
		// set the date to the current system date
		void setToday();

		// getters for private attributes
		int getDay() const;
		int getMonth() const;
		int getYear() const;

		// get month in text form
		string getMonthText() const;
		
		// getters for static members
		static DateOutput getOutputState();
		static DateArith getArithState();
		
		// Return the number of days between today's date and this date.
		int daysUntil() const;
		
		// get the day of the week
		string getDayOfWeek() const;

		// assignment operator
		const Date operator=(const Date&);
		
		/* Return the difference between two dates.
		* difference is returned in number of days, or years,
		* depending on the current state of arithState
		*/
		int operator-(const Date&) const;
		
		/* Return the date obtained by adding the period of time given 
		* as the int argument. 
		* The argument will be either number of days, or years, depending 
		* on the current state of arithState
		*/
		const Date operator+(int) const;
		
		/* Return the date obtained by subtracting the period of time given 
		* as the int argument. 
		* The argument will be either number of days, or years, depending 
		* on the current state of arithState
		*/
		const Date operator-(int) const;

		/* Increment this date by a unit of time. The unit can be a day, or
		* a year, depending on the current state of arithState.
		*/
		const Date operator++();	// pre-increment
		const Date operator++(int);	// post-increment
		
		/* Decrement this date by a unit of time. The unit can be a day, or
		* a year, depending on the current state of arithState.
		*/
		const Date operator--();	// pre-decrement
		const Date operator--(int);	// post-decrement
		
		// relational operators
		bool operator==(const Date&) const;
		bool operator!=(const Date&) const;
		bool operator<=(const Date&) const;
		bool operator>=(const Date&) const;
		bool operator<(const Date&) const;
		bool operator>(const Date&) const;

		// change the states of static variables	
		static void outputFormat(DateOutput);
		static void Arithmetic(DateArith);
		
		// return current system date
		static Date Today();
	private:
		int day;
		int month;
		int year;
		
		// methods that add or subtract a single day
		// these methods are called iteratively for larger operations
		void addDay();
		void subtractDay();
		
		// method that adds or subtracts a single year depending on value of arg
		// if arg == 1 : add ; if arg == -1: subtract
		// called iteratively for larger operations
		void addSubYear(int);
		
		// return number of days since beginning of year
		int daysSinceJan1();
		
		static DateOutput outputState;
		static DateArith arithState;
	};

	ostream& operator<<(ostream&, const Date&);
}

#endif
