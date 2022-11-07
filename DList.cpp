//
// Created by George Welson on 22-Oct-22.
//
/*
#include "DList.h"
List::List(int myCapacity) : myCapacity(myCapacity),mySize(INITIALSIZE),myArray(NULL){
    myArray = new (nothrow)ElementType[myCapacity];
}
List::~List(){
    delete[] myArray;
    mySize=0;
}
const List& List::operator=(const List &rightHandSide) {
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
List::List(const List & origList) {
    myArray = new (nothrow)ElementType[myCapacity];
    this->setMySize(origList.getMySize());
    this->setMyCapacity(origList.getMyCapacity());
    for (int i = 0; i < this->getMySize(); i++) {
        this->myArray[i] = *(origList.getMyArray()+i);
    }
}


bool List::operator==(const List &rhs) const {
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
void List::insert(ElementType item, int pos){
    if(this->getMySize()<this->getMyCapacity()){
        this->setMySize(getMySize() + 1);
        for (int i = this->getMySize() - 1; i > pos; i--) {
            this->myArray[i] = this->myArray[i - 1];
        }
        this->myArray[pos] = item;
    }else{
        cout<<"List is already full\n";
        return;
    }
}
void List::erase(int pos){
    if(this->empty()==true){
        cout<<"List is Empty\n";
        return;
    }else {
        for(int i=pos;i<this->getMySize()-1;i++){
            this->myArray[i]=this->myArray[i+1];
        }
        this->setMySize(this->getMySize() - 1);
        if(this->empty()== true) delete this;
    }
}
void List::display(ostream & out) const{
    if(this->empty()==true){
        cout<<"List is empty\n";
        return;
    }
    else{
        for(int i=0;i<this->getMySize();i++){
            cout<<this->myArray[i]<<endl;
        }
    }
}
bool List::operator!=(const List &rhs) const {
    return !(rhs == *this);
}

int List::getMySize() const {
    return this->mySize;
}
bool List::empty() const{
    if(this->getMySize()==INITIALSIZE)return true;
    else return false;
}

void List::setMySize(int mySize) {
    List::mySize = mySize;
}


void List::setMyCapacity(int myCapacity) {
    this->myCapacity = myCapacity;
}

int List::getMyCapacity() const {
    return this->myCapacity;
}
ElementType* List::getMyArray() const {
    return & this->myArray[0];
}

ostream & operator<< (ostream & out, const List & aList){
    aList.display(out);
    return out;
}*/