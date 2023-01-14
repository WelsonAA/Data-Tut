//
// Created by George Welson on 22-Oct-22.
//
/*
#include "DList.h"
SList::SList(int myCapacity) : myCapacity(myCapacity),mySize(INITIALSIZE),myArray(NULL){
    myArray = new (nothrow)ElementType[myCapacity];
}
SList::SListt(){
    delete[] myArray;
    mySize=0;
}
const SList& SList::operator=(const SList &rightHandSide) {
    if (&rightHandSide == this) {
        cout<<"left hand side is the same as right hand side";
        return NULL;
    }
    else {
        this->setMySize(rightHandSide.getMySize());
        this->setMyCapacity(rightHandSide.getMyCapacity());
        this->myArray=rightHandSide.myArray;
    }
}
SList::SList(const SList & origList) {
    myArray = new (nothrow)ElementType[myCapacity];
    this->setMySize(origList.getMySize());
    this->setMyCapacity(origList.getMyCapacity());
    for (int i = 0; i < this->getMySize(); i++) {
        this->myArray[i] = *(origList.getMyArray()+i);
    }
}


bool SList::operator==(const SList &rhs) const {
    bool flag =true;
    for(int i=0;i<rhs.getMySize();i++){
        if(this->myArray[i]!=rhs.myArray[i]) {
            flag = false;
            break;
        }
    }
    return mySize == rhs.mySize &&
           myCapacity == rhs.myCapacity &&
           flag;
}
void SList::insert(ElementType item, int pos){
    if(this->getMySize()<this->getMyCapacity()){
        this->setMySize(getMySize() + 1);
        for (int i = this->getMySize() - 1; i > pos; i--) {
            this->myArray[i] = this->myArray[i - 1];
        }
        this->myArray[pos] = item;
    }else{
        cout<<"SList is already full\n";
        return;
    }
}
void SList::erase(int pos){
    if(this->empty()==true){
        cout<<"SList is Empty\n";
        return;
    }else {
        for(int i=pos;i<this->getMySize()-1;i++){
            this->myArray[i]=this->myArray[i+1];
        }
        this->setMySize(this->getMySize() - 1);
        if(this->empty()== true) delete this;
    }
}
void SList::display(ostream & out) const{
    if(this->empty()==true){
        cout<<"SList is empty\n";
        return;
    }
    else{
        for(int i=0;i<this->getMySize();i++){
            cout<<this->myArray[i]<<endl;
        }
    }
}
bool SList::operator!=(const SList &rhs) const {
    return !(rhs == *this);
}

int SList::getMySize() const {
    return this->mySize;
}
bool SList::empty() const{
    if(this->getMySize()==INITIALSIZE)return true;
    else return false;
}

void SList::setMySize(int mySize) {
    SList::mySize = mySize;
}


void SList::setMyCapacity(int myCapacity) {
    this->myCapacity = myCapacity;
}

int SList::getMyCapacity() const {
    return this->myCapacity;
}
ElementType* SList::getMyArray() const {
    return & this->myArray[0];
}

ostream & operator<< (ostream & out, const SList & aList){
    aList.display(out);
    return out;
}*/