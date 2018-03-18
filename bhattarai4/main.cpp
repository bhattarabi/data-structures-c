// BONUS - I wrote the methods without any assistance

// File:      main.cpp
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 4
// Date:      3/10/2016

// This file contains tests for destructor, copy constructor
// and copy assignment operator for class linkedQueueType.

#include <iostream>
#include "linkedQueue.h"
using namespace std;

//Display and delete elements of q
void showQueue(linkedQueueType<int>& q)
{
	while (!q.isEmptyQueue())
	{
		cout << q.front() << " ";
		q.deleteQueue();
	}
	cout << endl;
}

//Function to test the copy constructor for linkedQueueType.
//Elements are deleted from and added to the queue. 
//The test is passed if the object which was passed as argument 
//remains intact in the caller's scope
void passByVal(linkedQueueType<int> q)
{
	cout << "deleting queue and adding new elements...\n";
	// delete all elements from the queue
	while (!q.isEmptyQueue())
		q.deleteQueue();
	
	for (int i=1; i<1000; i *= 2)
		q.addQueue(i);
	
	cout << "Queue contains:  ";
	showQueue(q);
}

void testAssign(linkedQueueType<int>& q)
{
	cout <<	"\nassigning queue to temp...\n";
	linkedQueueType<int> temp = q;
		
	cout << "deleting temp and adding new elements...\n";
	while (!temp.isEmptyQueue())
		temp.deleteQueue();
	
	for (int i=0; i<70; i += 5)
		temp.addQueue(i);
	
	cout << "temp contains:  ";
	showQueue(temp);
	
	cout << "Queue still contains:  ";
	showQueue(q);
}

//Function to test the destructor for linkedQueueType.
//In this test, a linkedQueueType onject is created, and an int pointer
//is allocated memory in the heap. We can tell that the destructor is 
//functioning because the address allocated to the int pointer alternates
//between the same two values no matter how many times the funciton is 
//called, which shows that there are no memory leaks.
void testDestructor()
{
	int* p = new int;	
	cout << "address pointed to in heap: " << p << endl;
	linkedQueueType<int> temp;	
	for (int i=0; i<10; i++)
		temp.addQueue(i);
	delete p;
}


int main()
{	
	//testing destructor
	for (int i=0; i< 10; i++)
		testDestructor();
	linkedQueueType<int> queue1;
	
	
	//testing copy constructor
	cout << "\nadding ints 0 to 9 to queue...\n";
	// add ints 0...10 to queue
	for (int i=0; i < 10; i++)
		queue1.addQueue(i);
	
	cout << "passing queue to function by value...\n";
	
	passByVal(queue1);
	
	cout << "back in main:\nQueue contains:  ";
	showQueue(queue1);
	
	cout << "****************************************\n";
	
	//testing operator=
	cout << "\nadding ints 10 to 19 to queue...";
	// add ints 0...10 to queue
	for (int i=0; i < 10; i++)
		queue1.addQueue(10+i);
	
	testAssign(queue1);
	
	return 0;
}