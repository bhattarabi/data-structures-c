#include <iostream>
#include "array.h"
using namespace std;
using namespace ArrayNameSpace;
const int endindex=3;
const int startindex=-3;

void func1(Array<int> n)
{
  // for (int i=startindex; i<=endindex; i++)
    //  cout << "n[" << i << "] = " << n[i] << endl;
}

Array<int> func2(Array<int> n)
{
   return n;
}

int main()
{	
	cout << "\nImplemented using array of pointers for extra bonus.\n\n";
	
	// *************** 20 points for int indices **************************
   Array<int> numbers(startindex,endindex);
   for (int i=startindex; i<=endindex; i++)
      numbers[i] = i*10;
   for (int i=startindex; i<=endindex; i++)
      cout << "numbers[" << i << "] = " << numbers[i] << endl;
   cout << "-------------\n";

   func1(numbers);
   cout << "-------------\n";

   Array<int> numbers2;  // the array has no locations
   try
   {
      numbers2[0] = 88;
   }
   catch (out_of_range error)
   {
      cout << error.what() << endl;
   }
   numbers2.Resize(10);
   cout << "-------------\n";
   numbers2[0] = 88;

   numbers2 = numbers;
   for (int i=startindex; i<endindex; i++)
      cout << "numbers2[" << i << "] = " << numbers2[i] << endl;
   cout << "-------------\n";

   Array<int> numbers3;
   numbers3 = func2(numbers);
   for (int i=startindex; i<endindex; i++)
      cout << "numbers3[" << i << "] = " << numbers3[i] << endl;
   cout << "-------------\n";

   if (numbers == numbers2)
      cout << "Equal!\n";
   else
      cout << "If you see this, your program has problems!!!\n";

   numbers2[startindex]=-99;
   if (numbers >= numbers2)
      cout << "Less Than!\n";
   else
      cout << "If you see this, your program has problems!!!\n";
// obviously you are to overload all the relational operators


// *************** 5 points for char indices **************************
   Array<char> array('J','N');
   array['J'] = 'H';
   array['K'] = 'E';
   array['L'] = 'L';
   array['M'] = 'L';
   array['N'] = 'O';
   for (char c='J'; c<='N'; c++)
      cout << array[c];
   cout << endl;
   cout << "-------------\n";
   try
   {
      array['Z'] = 'X';      
   }
   catch (out_of_range e)
   {
      cout << e.what() << endl;
   }
   
   cout << "-------------\n";

// *************** 2 bonus points for enum indices **************************
// uncomment if you get it to work

   enum DaysOfWeek {Mon, Tue, Wed, Thu, Fri, Sat, Sun};

   Array<double> hoursWorked(Mon,Fri);
   //cout << "main address: " << &hoursWorked << endl;
		
   hoursWorked[Mon] = 8;
   hoursWorked[Tue] = 8;
   hoursWorked[Wed] = 10;
   hoursWorked[Thu] = 10;
   hoursWorked[Fri] = 8;
   int total=0;
   for (DaysOfWeek day=Mon; day<=Fri; day=static_cast<DaysOfWeek>(day+1))
      total += hoursWorked[day];
   cout << "You worked " << total << " hours this week.  Good job!!!\n";
   cout << endl;

   return 0;
}
