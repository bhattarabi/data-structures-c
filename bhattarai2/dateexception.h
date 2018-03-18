 // File:      dateexception.h
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 2
// Date:      2/13/2016

// This file contains declaration of exception DateException.

#include <string>

using namespace std;

namespace DateNameSpace
{
	class DateException
	{
	public:
		DateException(const string& m)
		{	
			msg = m;
		}

		string what()
		{
			return msg;
		}

	private:
		string msg;
	};
}
