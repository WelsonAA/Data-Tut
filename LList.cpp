//
// Created by George Welson on 29-Oct-22.
//
#include "LList.h"
List::List():mySize(0),first(NULL){

}
List::List(const List & origList):mySize(origList.getMySize()),first(NULL){
    this->first=new (nothrow)Node(origList.first->data);
    NodePointer newptr=this->first;
    NodePointer oldptr=origList.first;
    for(int i=1;i<mySize;i++){
        newptr->next=new (nothrow) Node(oldptr->data);
        newptr=newptr->next;
        oldptr=oldptr->next;
    }
    newptr=NULL;
    oldptr=NULL;
}
List::~List(){
    NodePointer oldptr=this->first;
    NodePointer newptr=oldptr->next;
    while(newptr!=NULL){
        delete oldptr;
        oldptr=newptr;
        newptr=newptr->next;
    }
}

const List &List::operator=(const List &rightSide) {
    this->mySize=rightSide.mySize;
    this->first=rightSide.first;
}

int List::getMySize() const {
    return mySize;
}
bool List::empty() {
    if(mySize==0)return true;
    else return false;
}
void List::insert(ElementType dataVal, int index) {
    if(0 <= index <= mySize){
        NodePointer newNode=new(nothrow)Node(dataVal);
        if(index==0){
            this->first=newNode;
        }
        NodePointer iPtr=this->first;
        for(int i=0;i<index;i++) {
            if(i==(index-1)){
                NodePointer tmp=iPtr;
                tmp->next=newNode;
                newNode->next=iPtr->next;
            }
            iPtr=iPtr->next;
        }
        ++this->mySize;
    }else{
        cout<<"Invalid Index\n";
    }
}
void List::erase(int index){
    if(0 <= index < mySize){
        NodePointer iPtr=this->first;
        for(int i=0;i<index;i++){
            if(i==(index-1)){
                NodePointer tmp=iPtr->next;
                iPtr=iPtr->next->next;
                delete tmp;
            }
            iPtr=iPtr->next;
        }
        --this->mySize;
    }
    else{
        cout<<"Invalid Index\n";
    }
}
int List::nodeCount() {
    int i=0;
    for(NodePointer tmp=this->first;tmp!=NULL;tmp=tmp->next){
        ++i;
    }
    return i+1;
}
bool List::ascendingOrder() {
    bool flag=true;
    for(NodePointer tmp=this->first;tmp!=NULL;tmp=tmp->next){
        if(tmp->data>tmp->next->data){
            flag=false;
            return flag;
        }
    }
    return flag;
}
void List::reverse() {

}
ostream &operator<<(ostream & out, const List & aList){
    aList.display(out);
    return out;
}