//Header file linkedQueue.h

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedQueueType
{
public:

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty. 
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.
    bool isFullQueue() const;
      //Function to determine whether the queue is full. 
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: queueFront = NULL; queueRear = NULL

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the first 
      //               element of the queue is returned.  
    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the last 
      //               element of the queue is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.

    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first 
      //               element is removed from the queue.

    linkedQueueType(); 
      //default constructor
    
    const linkedQueueType<Type>& operator=
                    (const linkedQueueType<Type>&); 
      //Overload the assignment operator.
                    
    linkedQueueType(const linkedQueueType<Type>& otherQueue); 
      //copy constructor
    
    void destroyQueue();
      //Function to delete all the elements from the queue.
      //Postcondition: queueFront = NULL; queueRear = NULL

    ~linkedQueueType(); //destructor calls destroyQueue

private:
    nodeType<Type> *queueFront; //pointer to the front of 
                                //the queue
    nodeType<Type> *queueRear;  //pointer to the rear of 
                                //the queue
    void makeCopy(const linkedQueueType<Type>& otherQueue);
	  //Function to copy all elements from otherQueue.
      //Postcondition: queue contains all elements of otherQueue
	  //in the same order

};

template<class Type>
linkedQueueType<Type>::linkedQueueType() //default constructor
{
	queueFront = NULL; // set front to null
	queueRear = NULL;  // set rear to null
}


template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return(queueFront == NULL);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
}


template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
     destroyQueue();
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;  //create the node
 	assert(newNode != NULL);

	newNode->info = newElement;    //store the info
    newNode->link = NULL;		//initialize the link field to NULL
	
	if(queueFront == NULL)	      //if initially the queue is empty
    {
	   queueFront = newNode;
	   queueRear = newNode;
    }
    else				//add newNode at the end
    {
	   queueRear->link = newNode;
	   queueRear = queueRear->link;
    }
}//end addQueue

template<class Type>
Type linkedQueueType<Type>::front() const
{
	assert(queueFront != NULL);
   	return queueFront->info; 
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear!= NULL);
   	return queueRear->info;
}

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
   nodeType<Type> *temp;
   
   if(!isEmptyQueue())
   {
   		temp = queueFront;       //make temp point to the first node
   		queueFront = queueFront->link; //advance queueFront 
   		delete temp;                  //delete the first node

   		if(queueFront == NULL)   //if after deletion the queue is empty
			queueRear = NULL;	 //set queueRear to NULL
   }
   else
		cerr<<"Cannot remove from an empty queue"<<endl;
}//end deleteQueue


template<class Type>
linkedQueueType<Type>::~linkedQueueType() //destructor
{
     destroyQueue();  
}

template<class Type>
void linkedQueueType<Type>::destroyQueue()
{
	// write the definition of destroyQueue()
	while (!isEmptyQueue())
		deleteQueue();
}

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
								(const linkedQueueType<Type>& otherQueue)
{	
	//Write the definition of the assignment operator
	if (this != &otherQueue)
	{
		queueFront = NULL;
		queueRear = NULL;
		destroyQueue();
		makeCopy(otherQueue);
	}
}

//copy constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) 
{
	queueFront = NULL;
	queueRear = NULL;
    makeCopy(otherQueue);
}//end copy constructor

//make copy of otherQueue
template<class Type>
void linkedQueueType<Type>::makeCopy(const linkedQueueType<Type>& otherQueue)
{	
	nodeType<Type>* nodeptr = otherQueue.queueFront;
	while (nodeptr != NULL)
	{
		addQueue(nodeptr->info);
		nodeptr = nodeptr->link;
	}
}
#endif
