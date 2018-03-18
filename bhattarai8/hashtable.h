// file: 	hashtable.h
// name: 	Binaya Bhattarai
// class: 	CSIS 352
// program: assignment 8
// date: 	5/4/2016

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

//definition of class HashTable
template <class T>
class HashTable
{
public:
	HashTable(int max, int(*hashfunc)(const T&));
	//Constructor
	//Input: maximum size of the hashtable
	//		pointer to the hash function to be used by the hashtable
	//Output: none
	//Precondition:  size = max 
	//Postcondition: public member hash points to the function hashfunc
	void insert(const T&);
	//Insert new item into the hashtable
	//Input: item of template type to be inserted into hashtable
	//Output: none
	//Precondition:  hashtable is not already full 
	//Postcondition: item is inserted into hashtable if its hash value < size
	//		exception thrown if hash value >= size
	bool search(const T&) const;
	//Search for an item in the hashtable
	//Input: item of template type to be searched for in hashtable
	//Output: true if item is found, false otherwise
	//Precondition:  none 
	//Postcondition: none
	void retrieve(T&) const;
	//Get value of T from the hashtable
	//Input: item of template type which will be assigned the retrieved value
	//Output: reference parameter is assigned the value found in hashtable
	//Precondition:  input item is present in hashtable 
	//Postcondition: none
	int Collisions() const;
	//Number of collisions in the hashtable so far
	//Input: none
	//Output: number of collisions that have occured so far
	//Precondition:  none
	//Postcondition: none
	int (*hash)(const T& item);
	//pointer to the hash function used by the hashtable
private:
	//vector to store the hashed items
	vector<T*> table;
	//maximum size of the hashtable
	int size;
	//number of collisions that have occured so far
	int collisions;
	//initialize vector for use as hashtable
	void initialize();
};

//implementation of class HashTable
template <class T>
int HashTable<T>::Collisions() const
{
	return collisions;
}

template <class T>
void HashTable<T>::initialize()
{
	table.clear();
	table.resize(size);
	for (int i=0; i<size; i++)
		table[i] = NULL;
}

template <class T>
HashTable<T>::HashTable(int max, int (*hashfunc)(const T& item))
{
	collisions = 0;
	size = max;
	hash = hashfunc;
	initialize();
}

template <class T>
bool HashTable<T>::search(const T& item) const
{
	int hashVal = hash(item);
	
	//invalid hash value; item is not found
	if (hashVal >= size)
		return false;
	
	//item found at first location
	if (table[hashVal] != NULL && *(table[hashVal]) == item)
		return true;
	//start linear probing to find value
	else
	{
		int tmpVal = hashVal + 1;
		if (tmpVal == size) 
			tmpVal = 0;

		while ((table[tmpVal] == NULL || 
			(table[tmpVal] != NULL && !(*(table[tmpVal]) == item)))
			&& tmpVal != hashVal)
		{
			tmpVal++;
			if (tmpVal == size) 
				tmpVal = 0;
		}
		
		if (table[tmpVal] != NULL && *(table[tmpVal]) == item)
			return true;
		else
			return false;
	}
}

template <class T>
void HashTable<T>::retrieve(T& item) const
{
	int hashVal = hash(item);
	
	//item found at first location
	if (*(table[hashVal]) == item)
		item = *(table[hashVal]);
	else
	{
		int tmpVal = hashVal + 1;
		if (tmpVal == size) 
			tmpVal = 0;
		
		while (!(*(table[tmpVal]) == item) 
			&& tmpVal != hashVal)
		{
			tmpVal++;
			if (tmpVal == size) 
				tmpVal = 0;
		}
		
		if (*(table[tmpVal]) == item)
			item = *(table[tmpVal]);
	}
}

template <class T>
void HashTable<T>::insert(const T& item)
{
	T* tmp = new T(item);
	int hashVal = hash(item);
	
	if (hashVal >= size)
		throw range_error("Cannot insert! hash value exceeds table size");
	if (search(item))
		throw invalid_argument("Cannot insert! item already in hashtable");
	
	if (table[hashVal] == NULL)
		table[hashVal] = tmp;
	else
	{
		collisions++;
		int tmpVal = hashVal + 1;
		if (tmpVal == size) 
			tmpVal = 0;
		
		while (table[tmpVal] != NULL && tmpVal != hashVal)
		{
			tmpVal++;
			if (tmpVal == size) 
				tmpVal = 0;
		}
		if (table[tmpVal] == NULL)
			table[tmpVal] = tmp;
		else
			throw range_error("Cannot insert! hashtable is full");
	}
}
#endif