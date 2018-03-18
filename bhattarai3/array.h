// File:      array.h
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 3
// Date:      2/20/2016

// This file contains specifications for templated class 
// Array. An Array object behaves like a regular array,
// but with some additional features like size awareness 
// and index validation.

#ifndef _ARRAY_
#define _ARRAY_

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <cmath>

using namespace std;

namespace ArrayNameSpace
{
	template <class T>
	class Array
	{
	public:
		
		// default constructor
		// doesn't allocate storage; Array needs to be resized
		// before items can be added.
		Array ();
		
		// destructor
		~Array();
		
		// constructor that takes one int argument for size. 
		// index of Array will begin from 0
		explicit Array(int) throw (out_of_range);
		
		// constructor that takes two arguments for the starting
		// and ending index. works with ints and char
		Array (int, int) throw (out_of_range);
		Array (char, char) throw (out_of_range);
		
		// copy constructor
		Array (const Array&);
		
		// copy assignment operator
		const Array& operator=(const Array&);
		
		// relational operators
		// two arrays are equal only if they are equal in size and content.
		// For comparing less and greater, arrays can be of different sizes. 
		// For Array A to be less than Array B (A < B), elements are compared
		// starting at the beginning of each array and returned is the result 
		// of comparing A[i] and B[i] as soon as the ith element differs
		bool operator==(const Array&) const;
		bool operator!=(const Array&) const;
		bool operator<(const Array&) const;
		bool operator>(const Array&) const;
		bool operator<=(const Array&) const;
		bool operator>=(const Array&) const;
		
		// int index operators for accessing Array elements
		T& operator[] (int) throw (out_of_range);
		const T& operator[] (int) const throw (out_of_range);
		
		// char index operators for accessing Array elements
		T& operator[] (char) throw (out_of_range);
		const T& operator[] (char) const throw (out_of_range);
		
		void Resize(int) throw (out_of_range);	// resize Array
		int Size() const;	// size of Array
	private:
		T** arr;	// pointer to pointer to first T element
		int begin;	// starting index
		int size;	// maximum capacity
		
		//allocate memory for array and initialize all 
		//pointers to NULL
		void initToNull(); 
		//make copy of array
		void copyArr(const Array<T>&);
		//set array and all pointers to NULL 
		void cleanUp(); 
	};

	//allocate memory for array of pointers
	template <class T>
	void Array<T>::initToNull()
	{
		arr = new T*[size];
		
		for (int i=0; i<size; i++)
			arr[i] = NULL;
	}
	
	//make copy of array
	template <class T>
	void Array<T>::copyArr(const Array<T>& a)
	{
		begin = a.begin;
		size = a.size;
		arr = new T*[size];
		
		for (int i=0; i<size; i++)
			if (a.arr[i] != NULL)
				arr[i] = new T(*a.arr[i]);
			else
				arr[i] = NULL;
	}
	
	//set array and all pointers to NULL
	template <class T>
	void Array<T>::cleanUp()
	{	
		if (arr != NULL)
		{
			for (int i=0; i<size; i++)
				if (arr[i] != NULL)
				{
					delete arr[i];
					arr[i] = NULL;
				}
			
			delete [] arr;
			arr = NULL;
		}
	}
	
	// default constructor
	template <class T>
	Array<T>::Array()
	{
		size = begin = 0;
		initToNull();
	}
	
	// destructor
	template <class T>
	Array<T>::~Array()
	{
		cleanUp();
	}
	
	// create array of size sz
	template <class T>
	Array<T>::Array(int sz) throw (out_of_range)
	{
		if (sz< 0)
			throw out_of_range
			("out of range: size cannot be less than 0");
		
		begin = 0;
		size = sz;
		initToNull();
	}
	
	// create array with integer index range [start, end]
	template <class T>
	Array<T>::Array(int start, int end) throw (out_of_range)
	{
		if (start > end)
			throw out_of_range(
			"out of range: start index cannot be greater than end!");
		else
		{
			begin = start;
			size = end - start + 1;
			initToNull();
		}
	}

	// create array with char index range [start, end]
	template <class T>
	Array<T>::Array(char start, char end) throw (out_of_range)
	{
		if (start > end)
			throw out_of_range(
			"out of range: start index cannot be greater than end!");
		else
		{
			begin = static_cast<int>(start); 
			size = end - start + 1;
			initToNull();
		}
	}

	// copy constructor
	template <class T>
	Array<T>::Array(const Array& a)
	{
		copyArr(a);
	}
	
	// operator=
	template <class T>
	const Array<T>& Array<T>::operator=(const Array<T>& a)
	{
		if (this != &a)
		{			
			cleanUp();
			copyArr(a);
		}
		return *this;
	}

	//int index operations
	template <class T>
	T& Array<T>::operator[] (int index) throw (out_of_range)
	{
		if (arr == NULL)
			throw out_of_range ("out of range: Array is empty!");
			
		else if (index < begin || index >= begin + size)
			throw out_of_range ("out of range: index out of range");
			
		if (arr[index-begin] == NULL)
			arr[index-begin] = new T;
		
		return *arr[index-begin];
	}
	
	template <class T>
	const T& Array<T>::operator[] (int index) const throw (out_of_range)
	{
		if (arr == NULL)
			throw out_of_range ("out of range: Array is empty!");
			
		else if (index < begin || index >= begin + size)
			throw out_of_range ("out of range: index out of range");
		
		else if (arr[index-begin] == NULL)
			throw out_of_range ("out of range: unassigned index");
		
		else
			return *arr[index-begin];
 	}//end int index operations
 	
 	//char index operations
	template <class T>
	T& Array<T>::operator[] (char index) throw (out_of_range)
	{
		int ind = static_cast<int>(index);
		if (arr == NULL)
			throw out_of_range ("out of range: Array is empty!");
			
		else if (ind < begin || ind >= begin + size)
			throw out_of_range ("out of range: index out of range");
			
		if (arr[ind-begin] == NULL)
			arr[ind-begin] = new T();
		
		return *arr[ind-begin];
	}
	
	template <class T>
	const T& Array<T>::operator[] (char index) const throw (out_of_range)
	{
		int ind = static_cast<int>(index);
		if (arr == NULL)
			throw out_of_range ("out of range: Array is empty!");
			
		else if (ind < begin || ind >= begin + size)
			throw out_of_range ("out of range: index out of range");

		else if (arr[ind-begin] == NULL)
			throw out_of_range ("out of range: unassigned index");
		else
			return *arr[ind-begin];
 	}//end char index operations
 	
 	template <class T>
	void Array<T>::Resize(int newSize) throw (out_of_range)
	{
		if (newSize < 0) 
			throw out_of_range
			("out of range: size cannot be less than 0.");
		
		// temporary copy
		T** tmp = new T*[newSize];
		for (int i=0; i<newSize; i++)
			if (i < size && tmp[i] != NULL)
				tmp[i] = new T(*arr[i]);
			else
				tmp[i] = NULL;

		//delete current array and point arr to temporary array
		cleanUp();
		arr = tmp;
		size = newSize;
 	}
 	
 	template <class T>
	int Array<T>::Size() const
	{
		return size;
	}
	
	//relational operators
	template <class T>
	bool Array<T>::operator==(const Array<T>& a) const 
	{
		if (size != a.size)
			return false;
		
		for (int i=0; i<size; i++)
		{
			if (arr[i] == NULL && a.arr[i] == NULL)
				continue;
			
			if (arr[i] == NULL || a.arr[i] == NULL
				|| *arr[i] != *(a.arr[i]))
				return false;
		}
		return true;
	}
	
	template <class T>
	bool Array<T>::operator<(const Array<T>& a) const 
	{
		int lowIndex = min(size, a.size);
		
		for (int i=0; i<lowIndex; i++)
		{
			if (arr[i] == NULL && a.arr[i] == NULL)
				continue;
			
			if (arr[i] == NULL) 
				return true;
			
			if (a.arr[i] == NULL) 
				return false;
			
			if (*arr[i] < *(a.arr[i]))
				return true;
		}
		return (size < a.size);
	}
	
	template <class T>
	bool Array<T>::operator!=(const Array<T>& a) const 
	{
		return !(*this == a);
	}
	
	template <class T>
	bool Array<T>::operator<=(const Array<T>& a) const 
	{
		return *this == a || *this < a;
	}
	
	template <class T>
	bool Array<T>::operator>(const Array<T>& a) const 
	{
		return !(*this <= a);
	}
	
	template <class T>
	bool Array<T>::operator>=(const Array<T>& a) const 
	{
		return *this == a || *this > a;
	}// end relational operators
}
#endif
