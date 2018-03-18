//File:      sortedlist.h
//Name:      Binaya Bhattarai
//Class:     CSIS 352
//Program:   assignment 6
//Date:      4/7/2016

//This file contains declaration and implementation of the SortedList class.
//SortedList inherits publicly from the STL container class list, and provides
//some added functionalities.

#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <list>
using namespace std;

enum listOrder {ASCENDING, DESCENDING};

template <class T>
class SortedList : public list<T>
{
public:
	//constuctor that takes one argument for the sort order (ascending or descending)
	//if no argument is provided, the default is used, which is ascending
	//creates an empty list and sets the private iterator member to beginning of list
	explicit SortedList(listOrder = ASCENDING);
	
	//resets the private iterator instance to the beginning of the list
	//precondition: none
	//postcondition: iter points to the first element in the list
	void reset();
	
	//returns the current value pointed to by iter
	T current() const;
	
	//if iter is not already at the end of the list, increments it to point to the 
	//next value in the list, else throws an range_error 
	//precondition: none
	//postcondition: iter is incremented if not already at the end of the list
	void next();
	
	//if iter is not already at the beginning of the list, decrements it to point to 
	//the previous value in the list, else throws an range_error 
	//precondition: none
	//postcondition: iter is decremented if not already at the beginning of the list
	void prev();
	
	//return true if iter points to the end of the list
	bool endOfList() const;
	
	//inserts new element to the list such that the original sort order is maintained
	//precondition: relational operators are overloaded for the templated type
	//postcondition: new element is added to the list into its proper position 
	void insert(const T&);
		
	//returns true if the parameter element is in the list
	bool inList(const T&) const;
	
	//returns the number of occurances of the parameter element in the list
	int count(const T&) const;
	
	//removes the first occurance of the parameter element from the list
	//precondition: none
	//postcondition: if element was found, list has one less element than before
	void erase(const T&);
	
	//passes every element in the list to the function f
	//precondition: f in a function that takes one reference parameter of the template type
	//postcondition: none
	void traverse(void (*f)(const T&));
	
private:
	//sort order of the list. one of two types specified by enum listOrder
	//default is ASCENDING
	listOrder order;
	
	//an instance of the list iterator
	typename list<T>::iterator iter;
};

//constuctor that takes one argument for the sort order (ascending or descending)
template <class T>
SortedList<T>::SortedList(listOrder ord) : list<T>()
{
	order = ord;
	reset();
}

//insert new element to the list such that the original sort order is maintained
template <class T>
void SortedList<T>::insert(const T& item)
{
	typename list<T>::iterator i = list<T>::begin();
	while (i != list<T>::end())
	{
		if ( (order == ASCENDING && *i > item) ||
			 (order == DESCENDING && *i < item) )
			break;
		i++;
	}		
	list<T>::insert(i, item);
}

//pass every element in the list to the function f
template <class T>
void SortedList<T>::traverse(void (*f)(const T&))
{
	for (typename list<T>::iterator i = list<T>::begin(); 
		 i!=list<T>::end(); i++)
	{
		f(*i);
	}
}

//point the private iterator instance to the beginning of the list
template <class T>
void SortedList<T>::reset()
{
	iter = list<T>::begin();
}

//increment private iterator instance
template <class T>
void SortedList<T>::next()
{
	if (iter == list<T>::end())
		throw range_error("attempted next already past end of the list");
	
	iter++;
}

//decrement private iterator instance
template <class T>
void SortedList<T>::prev()
{
	if (iter == list<T>::begin())
		throw range_error("attempt to move before the beginning of the list");
	
	iter--;
}

//return the current value pointed to by iter
template <class T>
T SortedList<T>::current() const
{
	if (iter == list<T>::end())
		throw range_error("attempt to access past end of list");
	
	return *iter;
}

//return true if iter points to the end of the list
template <class T>
bool SortedList<T>::endOfList() const
{
	return (iter == list<T>::end());
}

//return true if the parameter key is in the list
template <class T>
bool SortedList<T>::inList(const T& key) const
{
	for (typename list<T>::const_iterator i = list<T>::begin(); 
		 i!=list<T>::end(); i++)
	{
		if (*i == key)
			return true;
	}
	return false;
}

//return the number of occurances of the parameter key
template <class T>
int SortedList<T>::count(const T& key) const
{
	int ct=0;
	
	for (typename list<T>::const_iterator i = list<T>::begin(); 
		 i!=list<T>::end(); i++)
	{
		if (*i == key)
			ct++;
	}
	return ct;
}

//remove first occurance of key from list
template <class T>
void SortedList<T>::erase(const T& key)
{
	for (typename list<T>::iterator i = list<T>::begin(); 
		 i!=list<T>::end(); i++)
	{
		if (*i == key)
		{
			list<T>::erase(i);
			return;
		}
	}
}
#endif