//
// Created by George Welson on 08-Nov-22.
//
//
//  Queue.hpp
//  StaticQueue
//
//  Created by Ashraf AbdelRaouf on 11/6/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.

/* Queue.h contains the declaration of class Queue.
 Basic operations:
 Constructor: Constructs an empty queue
 empty:       Checks if a queue is empty
 enqueue:     Modifies a queue by adding a value at the back
 front:       Accesses the front queue value; leaves queue unchanged
 dequeue:     Modifies a queue by removing the value at the front
 display:     Displays the queue elements from front to back
 Class Invariant:
 1. The queue elements (if any) are stored in consecutive positions
 in myArray, beginning at position myFront.
 2. 0 <= myFront, myBack < QUEUE_CAPACITY
 3. Queue's size < QUEUE_CAPACITY
 -------------------------------------------------------------------------*/
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 8;
typedef int QueueElement;
class Queue
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    Queue();
    /*-----------------------------------------------------------------------
     Construct a Queue object.

     Precondition:  None.
     Postcondition: An empty Queue object has been constructed; myFront
     and myBack are initialized to -1 and myArray is an array with
     QUEUE_CAPACITY elements of type QueueElement.
     ----------------------------------------------------------------------*/

    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.

     Precondition: None.
     Postcondition: True is returned if the queue is empty and false is
     returned otherwise.
     ----------------------------------------------------------------------*/
    bool full() const;
    void enqueue(const QueueElement & value);
    /*-----------------------------------------------------------------------
     Add a value to a queue.

     Precondition:  value is to be added to this queue.
     Postcondition: value is added to back of queue provided there is space;
     otherwise, a queue-full message is displayed and execution is
     terminated.
     -----------------------------------------------------------------------*/

    void display(ostream & out) const;
    /*-----------------------------------------------------------------------
     Output the values stored in the queue.

     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been output
     to out.
     -----------------------------------------------------------------------*/

    QueueElement front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless queue is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     ----------------------------------------------------------------------*/

    void dequeue();

    QueueElement back() const;
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless queue
     is empty; in that case, an error message is displayed and
     execution is terminated.
     ----------------------------------------------------------------------*/
    void movNthFront(int n);
    void swap(int x,int y);
    int size() const;
private:
    /***** Data Members *****/
    int myFront,
            myBack,mySize;
    QueueElement myArray[QUEUE_CAPACITY];

}; // end of class declaration


//------ Prototype of output operator
ostream & operator<< (ostream & out, const Queue & aList);




#endif /* Queue_hpp */

