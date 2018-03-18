// File:      currencymain.cpp
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 1
// Date:      1/19/2016

// This file contains tests for the Currency class.

#include <iostream>
#include <iomanip>
#include "currency.h"
using namespace std;

int main()
{
	Currency c1(2342.59);
	Currency c2(2342.515); // there is no half cent coin, round it to 2342.52
	Currency c3(423);
	Currency c4;
	c3 = 12;
	c3 = 4.6;
	c3 = c2;
	cout << "c1 = " << c1 << endl;
	if (c1 == c2)
		cout << "EQUAL\n";
	else
		cout << "NOT EQUAL\n";
	if (c1 < c2)
		cout << "LESS THAN\n";
	else
		cout << "NOT LESS THAN\n";
	if (c1 == 2342)
		cout << "EQUAL\n";
	else
		cout << "NOT EQUAL\n";
	if (c1 < 3000.34)
		cout << "LESS THAN\n";
	else
		cout << "NOT LESS THAN\n";
	// and the rest of the relational operators

	cout << "c3 = " << c3 << endl;
	c3 = c3+10;
	c3 = c3+.1;
	c3 = c3-10;
	c3 = c3-.1;
	cout << "c3 = " << c3 << endl;
	c3 = c3*2;
	c3 = c3/2;
	c3 = c3*.5;
	c3 = c3/.5;
	cout << "c3 = " << c3 << endl;
	//   c3 = c3%2;  NO
	c3 = c1+c2;
	cout << c3 << endl;
	c3 = c1-c2;
	cout << "c3 = " << c3 << endl;
	//   c3 = c1*c2;  NO
	//   c3 = c1/c2;  NO
	//   c3 = c1%c2;  NO
	cout << "c1 = " << c1 << "   dollars = " << c1.getDollars() << endl;
	cout << "c2 = " << c2 << "   cents = " << c2.getCents() << endl;

	c2 = 5343.65;
	c3 = 0.82;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	Currency::setFormat(Round); // default is ShowCents
	cout << "Round c2 = " << c2 << endl;
	cout << "Round c3 = " << c3 << endl;
	Currency::setFormat(Truncate);
	cout << "Truncate c2 = " << c2 << endl;
	cout << "Truncate c3 = " << c3 << endl;
	Currency::setFormat(ShowCents);
	cout << "ShowCents c2 = " << c2 << endl;
	cout << "ShowCents c3 = " << c3 << endl;
	Currency::setFormat(NoDollarSign);  // default is ShowDollarSign
	cout << "NoDollarSign c2 = " << c2 << endl;
	cout << "NoDollarSign c3 = " << c3 << endl;
	Currency::setFormat(ShowDollarSign);
	cout << "ShowDollarSign c2 = " << c2 << endl;
	cout << "ShowDollarSign c3 = " << c3 << endl;
	Currency::setFormat(NoDollarSign);
	Currency::setFormat(Round);
	cout << "Round NoDollarSign c2 = " << c2 << endl;
	cout << "Round NoDollarSign c3 = " << c3 << endl;

	return 0;
}
