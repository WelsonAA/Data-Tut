//
// Created by George Welson on 29-Oct-22.
//
#include "LList.h"
List::List():mySize(0),first(NULL){

}
List::List(const List & origList):mySize(origList.getMySize()),first(NULL){
    this->first=new (nothrow)Node(origList.first->data);
}

int List::getMySize() const {
    return mySize;
}
