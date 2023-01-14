//
//  DList.hpp
//  DynamicList
//
//  Created by Ashraf AbdelRaouf on 9/22/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.
//
/*-- DList.h --------------------------------------------------------------

 This header file defines the data type SList for processing lists.
 Basic operations are:
 Constructor
 Destructor
 Copy constructor
 Assignment operator
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list
 << :      Output operator
 -------------------------------------------------------------------------*/

#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef DList_hpp
#define DList_hpp
const int CAPACITY=1024;
const int INITIALSIZE=0;
typedef int ElementType;
class SList
{
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    SList(int maxSize = 1024);
    /*----------------------------------------------------------------------
     Construct a SList object.

     Precondition:  maxSize is a positive integer with default value 1024.
     Postcondition: An empty SList object is constructed; myCapacity ==
     maxSize (default value 1024); myArray points to a dynamic
     array with myCapacity as its capacity; and mySize is 0.
     -----------------------------------------------------------------------*/

    /***** Class destructor *****/
    ~SList();
    /*----------------------------------------------------------------------
     Destroys a SList object.

     Precondition:  The life of a SList object is over.
     Postcondition: The memory dynamically allocated by the constructor
     for the array pointed to by myArray has been returned to the heap.
     -----------------------------------------------------------------------*/

    /***** Copy constructor *****/
    SList(const SList & origList);


    /*----------------------------------------------------------------------
     Construct a copy of a SList object.

     Precondition:  A copy of origList is needed; origList is a const
     reference parameter.
     Postcondition: A copy of origList has been constructed.
     -----------------------------------------------------------------------*/

    /***** Assignment operator *****/
    const SList & operator=(const SList & rightHandSide);
    /*----------------------------------------------------------------------
     Assign a copy of a SList object to the current object.

     Precondition: none
     Postcondition: A copy of rightHandSide has been assigned to this
     object. A const reference to this list is returned.
     -----------------------------------------------------------------------*/

    /***** empty operation *****/
    bool empty() const;
    //--- See Figure 6.1 for documentation

    /***** insert and erase *****/
    void insert(ElementType item, int pos);
    //--- See Figure 6.1 for documentation (replace CAPACITY with myCapacity)

    void erase(int pos);
    //--- See Figure 6.1 for documentation

    /***** output *****/
    void display(ostream & out) const;
    //--- See Figure 6.1 for documentation
    int getMySize() const;

    void setMySize(int mySize);

    void setMyCapacity(int myCapacity);

    int getMyCapacity() const;

    ElementType* getMyArray() const;

    bool operator==(const SList &rhs) const;

    bool operator!=(const SList &rhs) const;

    void setMyArray(ElementType *myArray);


private:
     /******** Data Members ********/
    int mySize;                // current size of list
    int myCapacity;            // capacity of array
    ElementType * myArray;     // pointer to dynamic array


}; //--- end of SList class

//------ Prototype of output operator
ostream & operator<< (ostream & out, const SList & aList);

#endif /* DList_hpp */
