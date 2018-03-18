#include <iostream>
#include <stdexcept>
#include "sortedlist.h"
#include "date.h"
using namespace std;
using namespace DateNameSpace;

void func(const int& x)  // function to be passed to the traverse method
                         // note the const since we wouldn't want to allow
                         // an item in the SortedList to be changed
{
   cout << x << ' ';
}

void func1(const Date& x)  // function to be passed to the traverse method
                         // note the const since we wouldn't want to allow
                         // an item in the SortedList to be changed
{
   cout << x << ' ';
}

void passByValue(SortedList<int> a)
{
   cout << "a: ";
   a.traverse(func);
   cout << endl;
   a.clear();
}

int main()
{
	SortedList<int> x; // default is ASCENDING
	x.insert(5); // insert item into the sorted list
   x.insert(7);
   x.insert(9);
   x.insert(7);
   x.insert(12);
   x.insert(7);
   x.insert(3);
   x.insert(7);
   x.insert(9);
   x.insert(17);
   x.insert(2);
   x.insert(9);
   // output list with traverse method
   x.traverse(func);  // pass a pointer to a function to traverse entire list
   cout << endl;
   
   // output list with traversal methods
// reset() - resets the list to the beginning
// current() - returns the current value (standard exception at end)
// next() - moves to next value in list (standard exception if already at end)
// prev() - moves to previous value in list (standard exception if at begin)
// endOfList() - true if at end of list, false otherwise
   x.reset();     // resets the list to begin a traversal
   
   while (!x.endOfList())  // returns true if entire list has been traversed
   {
      cout << x.current() << ' ';  // return next item in the traversal
      x.next();  // move to the next item in the list
   }
   cout << endl;
   
   x.prev(); // was at end, return current to the last item
   cout << x.current() << endl;
   
   x.next(); // x is at the end, not an item in the list
   try
   {
      cout << x.current() << endl;
   }
   catch (range_error e)
   {
      cout << e.what() << endl;
   }
   try
   {
      x.next();  // already at the end of the list
   }
   catch (range_error e)
   {
      cout << e.what() << endl;
   }
   x.reset();
   try
   {
      x.prev();
   }
   catch (range_error e)
   {
      cout << e.what() << endl;
   }

// similar as previous only using a for loop
   for (x.reset(); !x.endOfList(); x.next() )
      cout << x.current() << ' ';
   cout << endl;
   
   if (x.empty())   // check to see if list is empty
      cout << "list is empty\n";
   else
      cout << "list is not empty\n";
   cout << "first: " << x.front() << endl; // return the first in list
   cout << "last: " << x.back() << endl;  // return the last in list
   cout << "size: " << x.size() << endl;  // return the number of items 
   
   int searchKey = 7;
   if (x.inList(searchKey))   // check to see if an item is in the list
      cout << searchKey << " is in the list\n";
   else
      cout << searchKey << " is not in the list\n";
   searchKey = 8;
   if (x.inList(searchKey))   // check to see if an item is in the list
      cout << searchKey << " is in the list\n";
   else
      cout << searchKey << " is not in the list\n";
   searchKey = 9;
   cout << searchKey << " is in the list " << x.count(searchKey) << " times\n";
   cout << 8 << " is in the list " << x.count(8) << " times\n";

   x.erase(7);  // removes the first occurance
   x.remove(9);  // removes all occurances
   x.traverse(func);
   cout << endl;

   x.erase(88);  // no error
   x.remove(88); // no error

   x.clear();
   if (x.empty())   // check to see if list is empty
      cout << "list is empty\n";
   else
      cout << "list is not empty\n";
   
   SortedList<int> y(ASCENDING);
   y.insert(4);
   y.insert(8);
   y.insert(5);
   y.insert(2);
   y.insert(7);
   cout << "y: ";
   y.traverse(func);
   cout << endl;

   SortedList<int> z(DESCENDING);
   z.insert(4);
   z.insert(8);
   z.insert(5);
   z.insert(2);
   z.insert(7);
   cout << "z: ";
   z.traverse(func);
   cout << endl;

   x = y;
   cout << "x: ";
   x.traverse(func);
   cout << endl;
   
   passByValue(x);
   cout << "x: ";
   x.traverse(func);
   cout << endl;
	
	SortedList<Date> listA;
	Date today = Date(4, 12, 2016);
	Date yester = Date(4, 11, 2016);
	Date tomor = Date(4, 13, 2016);
	Date dayb4 = Date(4, 10, 2016);
	
	listA.insert(today);
	listA.insert(today);
	listA.insert(today);
	listA.insert(yester);
	listA.insert(tomor);
	
	listA.traverse(func1);
	cout << endl;
	
	listA.erase(today);
	
	listA.traverse(func1);
	cout << endl;
	
	listA.reset();     // resets the list to begin a traversal
   
   while (!listA.endOfList())  // returns true if entire list has been traversed
   {
      cout << listA.current() << ' ';  // return next item in the traversal
      listA.next();  // move to the next item in the list
   }
   cout << endl;
   
   cout << listA.inList(yester) << endl;
   cout << listA.inList(dayb4) << endl;
   
   
   cout << listA.count(today) << endl;
	return 0;
}