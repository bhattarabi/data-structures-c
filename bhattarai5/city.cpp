#include <iostream>
#include <string>
#include "city.h"
using namespace std;

City::City(const string& str)
{
	name = str;
}

string City::getName() const
{
	return name;
}

bool City::operator==(const City& c) const
{
    return getName()==c.getName();
}

bool City::operator!=(const City& c) const
{
    return getName()!=c.getName();
}

bool City::operator<(const City& c) const
{
    return getName()<c.getName();
}

bool City::operator<=(const City& c) const
{
    return getName()<=c.getName();
}

bool City::operator>(const City& c) const
{
    return getName()>c.getName();
}

bool City::operator>=(const City& c) const
{
    return getName()>=c.getName();
}

ostream& operator << (ostream& out,const City& c)
{
    out << c.getName();
    return out;
}
