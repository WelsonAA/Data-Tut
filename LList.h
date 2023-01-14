//
// Created by George Welson on 29-Oct-22.
//

#ifndef DATA_TUT_LLIST_H
#define DATA_TUT_LLIST_H
//
//  SList.hpp
//  LinkedList
//
//  Created by Ashraf AbdelRaouf on 9/23/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.
//



#include <stdio.h>
#include <iostream>
using namespace std;
typedef int ElementType;

class LList
{
private:

    class Node {
    public:

        //------ Node DATA MEMBERS
        ElementType data;
        Node *  next;

        //------ Node OPERATIONS
        //-- Default constrctor: initializes next member to Node()
        Node(): next(0){}

        //-- Explicit-value constructor:  initializes data member to dataValue
        //--                             and next member to 0
        Node(ElementType dataValue): data(dataValue), next(0){}
    }; //--- end of Node class

    typedef Node * NodePointer;

public:
    //------ LList OPERATIONS
    LList();
    /*--------------------------------------------------------------------
     Default constructor: builds an empty LList object.
     Precondition:  None
     Postcondition: first is 0 and mySize is 0.
     --------------------------------------------------------------------*/
    LList(const LList & origList);
    /*--------------------------------------------------------------------
     Copy constructor
     Precondition:  A copy of origList is needed.
     Postcondition: A distincr copy of origList has been constructed.
     --------------------------------------------------------------------*/
    ~LList();
    /*--------------------------------------------------------------------
     Destructor
     Precondition:  This LList's lifetime is over.
     Postcondition: This LList has been destroyed.
     --------------------------------------------------------------------*/
    const LList & operator=(const LList & rightSide);
    /*--------------------------------------------------------------------
     Assignment operator
     Precondition:  This LList must be assigned a value.
     Postcondition: A copy of rightSide has been assigned to this LList.
     --------------------------------------------------------------------*/
    bool operator==(const LList & rightSide ) const;
    bool empty() const;
    /*--------------------------------------------------------------------
     Check if this LList is empty
     Precondition:  None.
     Postcondition: true is returned if this LList is empty, false if not.
     --------------------------------------------------------------------*/
    void insert(ElementType dataVal, int index);
    /*--------------------------------------------------------------------
     Insert a value into a LList at a given index.
     Precondition:  index is a valid LList index: 0 <= index <= mySize,
     Postcondition: dataVal has been inserted into the LList at position
     index, provided index is valid..
     --------------------------------------------------------------------*/
    void erase(int index);
    /*--------------------------------------------------------------------
     Remove a value from a LList at a given index.
     Precondition:  index is a valid LList index:  0 <= index < mySize
     Postcondition: dataVal at LList position index has been removed,
     provided index is valid.
     --------------------------------------------------------------------*/
    int search(ElementType dataVal);
    /*--------------------------------------------------------------------
     Search for an data value in this LList.
     Precondition:  None
     Postcondition: Index of node containing dataVal is returned
     if such a node is found, -1r if not.
     --------------------------------------------------------------------*/
    void display(ostream & out) const;
    /*--------------------------------------------------------------------
     Display the contensts of this LList.
     Precondition:  ostream out is open
     Postcondition: Elements of this LList have been output to out.
     --------------------------------------------------------------------*/
    int nodeCount();
    /*--------------------------------------------------------------------
     Count the elements of this LList.
     Precondition:  None
     Postcondition: Number of elements in this LList is returned.
     --------------------------------------------------------------------*/
    void reverse();
    /*--------------------------------------------------------------------
     Reverse this LList.
     Precondition:  None
     Postcondition: Elements in this LList have been reversed.
     --------------------------------------------------------------------*/
    bool ascendingOrder();

    int getMySize() const;
    /*--------------------------------------------------------------------
     Check if the elements of this LList are in ascending order.
     Precondition:  None
     Postcondition: true is returned if the LList elements are in
     ascending order, false if not.
     --------------------------------------------------------------------*/
    void selectionSort();
private:
    //------ DATA MEMBERS
    NodePointer first;
    int mySize;


}; //--- end of LList class

ostream & operator<<(ostream & out, const LList & aList);
istream & operator>>(istream & in, LList & aList);



#endif //DATA_TUT_LLIST_H
