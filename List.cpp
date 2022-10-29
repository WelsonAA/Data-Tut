//
// Created by George Welson on 16-Oct-22.
//
//
//  List.h
//  ArrayList
//
//  Created by Ashraf AbdelRaouf on 9/22/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.
//
/*
#include "List.h"
using namespace std;

    /******** Function Members ********/
    /***** Class constructor *****/
    /*
List::List() {
    mySize = 0;
}
bool List::empty() const {
    if(mySize==0)return true;
    else return false;
}
void List::insert(ElementType item, int pos){
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

void List::erase(int pos){
        if(List::empty()==true)return;
        else if(0 <= pos < mySize){
            for (int i = pos; i < mySize -1; i++) {
                myArray[i] = myArray[i + 1];
            }
        }
        mySize--;
}
void List::display(ostream & out) const{
     if(List::empty()==true) {
         return;
     }
     for(int i=0;i<mySize;i++){
        out<<myArray[i]<<endl;
    }
}
    /*----------------------------------------------------------------------
     Display a list.

     Precondition:  The ostream out is open.
     Postcondition: The list represented by this List object has been
     inserted into out.
     -----------------------------------------------------------------------*/
/*void List::insertEnd(ElementType item){
        if(mySize<CAPACITY)myArray[mySize]=item;
        else return;
        mySize++;
}

int List::getMySize() const {
    return mySize;
}

//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList){
    aList.display(out);
    return out;
}*/

//#endif

