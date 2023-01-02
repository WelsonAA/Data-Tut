//
// Created by George Welson on 08-Nov-22.
//
//
//  queueType.hpp
//  StaticQueue
//
//  Created by Ashraf AbdelRaouf on 11/6/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.

/* queueType.h contains the declaration of class queueType.
 Basic operations:
 Constructor: Constructs an empty queueType
 empty:       Checks if a queueType is empty
 enqueue:     Modifies a queueType by adding a value at the back
 front:       Accesses the front queueType value; leaves queueType unchanged
 dequeue:     Modifies a queueType by removing the value at the front
 display:     Displays the queueType elements from front to back
 Class Invariant:
 1. The queueType elements (if any) are stored in consecutive positions
 in myArray, beginning at position myFront.
 2. 0 <= myFront, myBack < QUEUE_CAPACITY
 3. queueType's size < QUEUE_CAPACITY
 -------------------------------------------------------------------------*/
//

#ifndef DATA_TUT_QUEUETYPE_H
#define DATA_TUT_QUEUETYPE_H

#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 8;
typedef int QueueElement;
class queueType
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    queueType();
    /*-----------------------------------------------------------------------
     Construct a queueType object.

     Precondition:  None.
     Postcondition: An empty queueType object has been constructed; myFront
     and myBack are initialized to -1 and myArray is an array with
     QUEUE_CAPACITY elements of type QueueElement.
     ----------------------------------------------------------------------*/

    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queueType is empty.

     Precondition: None.
     Postcondition: True is returned if the queueType is empty and false is
     returned otherwise.
     ----------------------------------------------------------------------*/
    bool full() const;
    void enqueue(const QueueElement & value);
    /*-----------------------------------------------------------------------
     Add a value to a queueType.

     Precondition:  value is to be added to this queueType.
     Postcondition: value is added to back of queueType provided there is space;
     otherwise, a queueType-full message is displayed and execution is
     terminated.
     -----------------------------------------------------------------------*/

    void display(ostream & out) const;
    /*-----------------------------------------------------------------------
     Output the values stored in the queueType.

     Precondition:  ostream out is open.
     Postcondition: queueType's contents, from front to back, have been output
     to out.
     -----------------------------------------------------------------------*/

    QueueElement front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queueType (if any).

     Precondition:  queueType is nonempty.
     Postcondition: Value at front of queueType is returned, unless queueType is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     ----------------------------------------------------------------------*/

    void dequeue();

    QueueElement back() const;
    /*-----------------------------------------------------------------------
     Remove value at front of queueType (if any).

     Precondition:  queueType is nonempty.
     Postcondition: Value at front of queueType has been removed, unless queueType
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
ostream & operator<< (ostream & out, const queueType & aList);




#endif /* Queue_hpp */

