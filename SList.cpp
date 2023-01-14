//
// Created by George Welson on 16-Oct-22.
//
//
//  SList.h
//  ArrayList
//
//  Created by Ashraf AbdelRaouf on 9/22/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.
//

#include "SList.h"
using namespace std;

    /******** Function Members ********/
    /***** Class constructor *****/

SList::SList() {
    mySize = 0;
}
void SList::heapify( int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && this->myArray[l] > this->myArray[largest])
        largest = l;

    if (r < n && this->myArray[r] > this->myArray[largest])
        largest = r;

    if (largest != i) {
        swap(this->myArray[i], this->myArray[largest]);
        heapify(n, largest);
    }
}

// Function to build the heap
void SList::buildHeap( int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify( n, i);
}


// Function to perform HeapSort on the array
void SList::heapSort() {
    buildHeap(this->mySize);

    for (int i = mySize - 1; i >= 0; i--) {
        swap(myArray[0], myArray[i]);
        heapify( i, 0);
    }
}
bool SList::empty() const {
    if(mySize==0)return true;
    else return false;
}
void SList::insert(ElementType item, int pos){
    if(this->empty()==true) {
        myArray[0] = item;
    }
    else if(0<=pos<mySize && pos<CAPACITY && mySize<CAPACITY) {
        for (int i = mySize;i>pos;i--){
            myArray[i]=myArray[i-1];
        }
        myArray[pos]=item;
    }else if(pos==mySize){
        this->insertEnd(item);
        return;
    }
    else return;
    mySize++;
}

void SList::erase(int pos){
        if(SList::empty() == true)return;
        else if(0 <= pos < mySize){
            for (int i = pos; i < mySize -1; i++) {
                myArray[i] = myArray[i + 1];
            }
        }
        mySize--;
}
void SList::display(ostream & out) const{
     if(SList::empty() == true) {
         return;
     }
     for(int i=0;i<mySize;i++){
        out<<myArray[i]<<'\t';
    }
}
    /*----------------------------------------------------------------------
     Display a list.

     Precondition:  The ostream out is open.
     Postcondition: The list represented by this SList object has been
     inserted into out.
     -----------------------------------------------------------------------*/
void SList::insertEnd(ElementType item){
        if(mySize<CAPACITY)myArray[mySize]=item;
        else return;
        mySize++;
}

int SList::getMySize() const {
    return mySize;
}

//------ Prototype of output operator
ostream & operator<< (ostream & out, const SList & aList){
    aList.display(out);
    return out;
}


