// File:      date.cpp
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 2
// Date:      2/13/2016

// This file contains implementation of the Date class

#include <sstream>
#include <ctime>
#include "date.h"

using namespace std;

namespace DateNameSpace
{
	// check if the given year is a leap year
	bool leapYear(int year)
	{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	if (year % 400 == 0)
		return true;
	return false;
	}

	// set static members of Date class to default values
	DateOutput Date::outputState = NUMERIC;
	DateArith Date::arithState = DAYS;

	// assign value of d to static member outputState
	void Date::outputFormat(DateOutput d)
	{
		outputState = d;
	}

	// assign value of a to static member arithState
	void Date::Arithmetic(DateArith a)
	{
		arithState = a;
	}

	// current state of static member outputState
	DateOutput Date::getOutputState()
	{
		return Date::outputState;
	}

	// current state of static member arithState
	DateArith Date::getArithState()
	{
		return Date::arithState;
	}
	
	// return current system date
	Date Date::Today()
	{
		return Date();
	}

	// getters for instance members
	int Date::getDay() const
	{
		return day;
	}

	int Date::getMonth() const
	{
		return month;
	}

	int Date::getYear() const
	{
		return year;
	}// end instance member getters

	// get the day of the week
	// source: ~/home/remote/brekke/CSIS352/datestuff.cpp
	string Date::getDayOfWeek() const
	{
		int centuries;
		int months;
		int dayofweek;
		centuries = (3-year/100%4)*2;
		switch (month)
		{
			case 1  : if (leapYear(year))
						months = 6;
						else
						months = 0; break;
			case 2  : if (leapYear(year))
						months = 2;
						else
						months = 3; break;
			case 3  : months = 3; break;
			case 4  : months = 6; break;
			case 5  : months = 1; break;
			case 6  : months = 4; break;
			case 7  : months = 6; break;
			case 8  : months = 2; break;
			case 9  : months = 5; break;
			case 10 : months = 0; break;
			case 11 : months = 3; break;
			case 12 : months = 5; break;
		}
		dayofweek = (centuries+year%100+year%100/4+months+day)%7;

		switch (dayofweek)
		{
			case 0 : return "Sunday";
			case 1 : return "Monday";
			case 2 : return "Tuesday";
			case 3 : return "Wednesday";
			case 4 : return "Thursday";
			case 5 : return "Friday";
			case 6 : return "Saturday";
		}
	}

	// set date to current system date
	// source: ~/home/remote/brekke/CSIS352/datestuff.cpp
	void Date::setToday()
	{
		tm *current;
		time_t lt;
		lt = time('\0');
		current = localtime(&lt);
		year = current->tm_year + 1900;
		month = current->tm_mon+1;
		day = current->tm_mday;
	}

	// parameterless constructor
	Date::Date()
	{
		setToday();
	}

	// constructor that takes int arguments for the month, day and year
	Date::Date(int m, int d, int y) throw (DateException)
	{
		try{
			setDate(m, d, y);
		}
		catch (DateException d)
		{
			throw;
		}
	}

	// set the date to month, day, year provided in arguments
	void Date::setDate(int m, int d, int y) throw (DateException)
	{
		stringstream ss;
		ss << "DateException: ";
		
		if (m < 1 || m > 12){
			ss << "invalid month, month = " << m;
			throw DateException(ss.str());
		}
		else if ((d < 1 || d > 31) 
			||
			((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || 
			m == 10 || m == 12) && (d < 1 || d >31))
			||
			((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30))
			||
			(m == 2 && leapYear(y) && d > 29)
			||
			(m == 2 && !leapYear(y) && d > 28)){
			ss << "invalid day, day = " << d << ", month = " << m << ", year = " << y;
			throw DateException(ss.str());
		}
		else{
			month = m;
			day = d;
			year = y;
		}
	}
	
	// assignment operator copies all attributes from d to this date
	const Date Date::operator=(const Date& d)
	{
		setDate(d.getMonth(), d.getDay(), d.getYear());
	}
	
	//relational operators
	bool Date::operator==(const Date& d) const
	{
		if (month == d.getMonth() && 
			day == d.getDay() &&
			year == d.getYear())
			return true;
		
		return false;
	}	
	
	bool Date::operator!=(const Date& d) const
	{
		return !(*this == d);
	}
	
	bool Date::operator<(const Date& d) const
	{
		if (year < d.getYear() ||
			(year == d.getYear() && month < d.getMonth()) ||
			(year == d.getYear() && month == d.getMonth() 	
			&& day < d.getDay()))
			return true;
		
		return false;
	}
	
	bool Date::operator<=(const Date& d) const
	{
		return *this == d || *this < d;
	}
	
	bool Date::operator>(const Date& d) const
	{
		return *this != d && !(*this < d);
	}
	
	bool Date::operator>=(const Date& d) const
	{
		return *this > d || *this == d;
	} // end relational operators
	
	// add or subtract a single year from this date
	void Date::addSubYear(int which)
	{
		year += which;
		
		if (month == 2 && day == 29)
		{
			month = 3;
			day = 1;
		}
		else if (month == 3 && day == 1 && leapYear(year))
		{
			month = 2; 
			day = 29;
		}
	}

	
	// add a single day to this date
	void Date::addDay(){
		if (month == 12 && day == 31)
		{
			year++;
			month = 1;
			day = 1;
		}
		else if (((month == 1 || month == 3 || month == 5 ||
			month == 7 || month == 8 || month == 10) && day == 31)
			||
			((month == 4 || month == 6 || month == 9 ||
			month == 11) && day == 30)
			||
			(month == 2 && day == 28 && !leapYear(year))
			||
			(month == 2 && day == 29 && leapYear(year)))
		{
			month++;
			day = 1;
		}
		else 
			day++;	
	}
	
	// subtract a single day from this date
	void Date::subtractDay()
	{
		if (day == 1)
		{
			if (month == 1)
			{
				year--;
				month = 12;
				day = 31;
			}
			else
			{
				if (month == 5 || month == 7 ||
				month == 10 || month == 12)
					day = 30;
					
				else if (month == 2 || month == 4 || month == 6 ||
				month == 9 || month == 11 || month == 8)
					day = 31;
				
				else if (month == 3 && leapYear(year))
					day = 29;
				
				else if (month == 3 && !leapYear(year))
					day = 28;
				
				month--;
			}
		}
		else
			day--;
	}
	
	// pre-increment
	const Date Date::operator++()
	{
		if (Date::getArithState() == DAYS)
			addDay();
		else
			addSubYear(1);
		
		return *this;
	}	
	
	// post-increment
	const Date Date::operator++(int dummy)
	{
		Date d = *this;
		
		if (Date::getArithState() == DAYS)
			addDay();
		else
			addSubYear(1);
		
		return d;
	}
	
	// pre-decrement
	const Date Date::operator--()
	{
		if (Date::getArithState() == DAYS)
			subtractDay();
		else
			addSubYear(-1);
		
		return *this;
	}	
	
	// post-decrement
	const Date Date::operator--(int dummy)
	{
		Date d = *this;
		
		if (Date::getArithState() == DAYS)
			subtractDay();
		else
			addSubYear(-1);
		
		return d;
	}
	
	// arithmetic operators
	const Date Date::operator+(int diff) const
	{
		Date tmp = *this;
	
		for (int i = 0; i < diff ; i++)
			tmp++;
		
		return tmp;
	}
	
	const Date Date::operator-(int diff) const
	{
		Date tmp = *this;
	
		for (int i = 0; i < diff ; i++)
			tmp--;
		
		return tmp;
	}
	 
	// difference between this date and Date d
	int Date::operator-(const Date& d) const
	{
		Date d1, d2;
		int diff, n;
		
		if (*this == d) 
			return 0;
			
		if (Date::getArithState() == YEARS)
		{		
			diff = this->getYear() - d.getYear();
			
			if (diff < 0 &&
				(d.getMonth() < this->getMonth() ||
				(d.getMonth() == this->getMonth() &&
				d.getDay() < this->getDay())))
				diff++;
					
			else if (diff > 0 &&
				(this->getMonth() < d.getMonth() ||
				(this->getMonth() == d.getMonth() &&
				this->getDay() < d.getDay())))
				diff--;
			
			return diff;
		}
		
		if (*this > d)
		{
			d1 = d;
			d2 = *this;
			n = 1;
		}
		else
		{
			d1 = *this;
			d2 = d;
			n  = -1;
		}
		
		diff = (leapYear(d1.getYear())? 366: 365) - d1.daysSinceJan1();
		
		for (int i = d1.getYear() + 1; i < d2.getYear(); i++)
			diff += (leapYear(i)? 366: 365);
		
		diff += d2.daysSinceJan1();
		return diff * n;
	}
	
	// return day of the year
	int Date::daysSinceJan1()
	{
		int i=1, elapsed = day;
		
		while (i < month)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 ||
				i == 8 || i == 10 || i == 12)
				elapsed += 31;
			
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				elapsed += 30;
			
			else if (leapYear(year))
				elapsed += 29;
			
			else
				elapsed += 28;
			
			i++;
		}
		
		return elapsed;
	}
	
	// number of days remaining before this date's next occurance
	int Date::daysUntil() const
	{
		Date today;
		int ct = 0;
		
		while (today.getMonth() != month
			|| today.getDay() != day)
		{
			today.addDay();
			ct++;
		}
		return ct;
	}

	// return the month represented by the date in text format
	string Date::getMonthText() const
	{
		switch (month)
		{
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
		}
	}
	
	// overload stream operator 
	ostream& operator<<(ostream& o, const Date& d)
	{	
		// display day of the week
		if (d.getOutputState() == DAYNUMERIC || 
			d.getOutputState() == DAYTEXT)
			o << d.getDayOfWeek() << ", " ;

		// display numeric 
		if (d.getOutputState() == NUMERIC ||
			d.getOutputState() == DAYNUMERIC)
			o << d.getMonth() << "/" << d.getDay() << "/" << d.getYear();
		// display text
		else
			o << d.getMonthText() << " " << d.getDay() << ", " << d.getYear();

		return o;  
	}
}