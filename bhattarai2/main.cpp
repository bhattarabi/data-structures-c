// File:      main.cpp
// Author:    Dan Brekke

// This file contains the main function that shows what should compile
// for program 2.

#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"
using namespace std;
using namespace DateNameSpace;

int main()
{
	Date d1(2,1,1996);
	
	Date d2(2,1,1997);
	
	cout << (d2 == d1+366) << endl;
	
	Date::Arithmetic(YEARS);
	
	cout << d2 << endl;
	
	/*
	for (int i=0; i< 369; i++){
		cout << d1-- << endl;
	}*/
	return 0;
}