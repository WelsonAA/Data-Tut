//
// Created by George Welson on 29-Oct-22.
//
#include "LList.h"
List::List():mySize(0),first(NULL){

}
List::List(const List & origList):mySize(origList.getMySize()),first(NULL){
    if (mySize == 0) return;
    first = new Node(origList.first->data);
    NodePointer newPtr=first;
    NodePointer oldPtr =origList.first->next;
    while(oldPtr!=NULL){
        newPtr->next=new(nothrow) Node(oldPtr->data);
        newPtr=newPtr->next;
        oldPtr=oldPtr->next;
    }


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

bool List::operator==(const List &rightSide) const {
    bool flag=true;
    NodePointer thisptr=this->first;
    NodePointer otherptr=rightSide.first;
    if(this->getMySize()!=rightSide.getMySize())
        return false;
    else {
        for (int i = 0; i < this->getMySize();i++){
            if(thisptr->data!=otherptr->data)
                return false;
            thisptr=thisptr->next;
            otherptr=otherptr->next;
        }
            return flag;
    }
}
const List &List::operator=(const List &rightSide) {
    this->mySize=rightSide.mySize;
    this->first=rightSide.first;
}

int List::getMySize() const {
    return mySize;
}
bool List::empty() const {
    if(mySize==0)return true;
    else return false;
}

void List::insert(ElementType dataVal, int index) {
    if(0>index || mySize<index){
        cout<<"Invalid Index\n";
        return;
    }else{
        mySize++;
        NodePointer newNode=new(nothrow)Node(dataVal);
        NodePointer tmp=this->first;
        if(index==0){
            newNode->next=this->first;
            this->first=newNode;
        }else{
            for(int i= 1;i<index;i++){
                tmp=tmp->next;
            }
            newNode->next=tmp->next;
            tmp->next=newNode;
        }
    }
}
void List::erase(int index){
    if (index < 0 || index >= mySize)
    {
        cerr << "Illegal location to delete -- " << index << endl;
        return; }
    mySize--;
    List::NodePointer ptr,
            predPtr = first;
    if (index == 0)
    {
        ptr = first;
        first = ptr->next;
        delete ptr;
    }
    else {
        for(int i = 1; i < index; i++)
            predPtr = predPtr->next;
        ptr = predPtr->next;
        predPtr->next = ptr->next;
        delete ptr;
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
void List::display(ostream & out) const{
    if(this->empty()==true){
        cout<<"Empty List\n";
        return;
    }else{
        for(NodePointer tmp=this->first;tmp!=NULL;tmp=tmp->next){
            out<<tmp->data<<endl;
        }
    }
}
void List::selectionSort()
{
    Node* temp = this->first;

    // Traverse the List
    while (temp) {
        Node* min = temp;
        Node* r = temp->next;

        // Traverse the unsorted sublist
        while (r) {
            if (min->data > r->data)
                min = r;

            r = r->next;
        }

        // Swap Data
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}
//void List::selectionSort() {
//    NodePointer currentptr,nextptr;
//    currentptr=this->first;
//    int min=currentptr->data;
//    nextptr=currentptr->next;
//    while(nextptr!=NULL){
//        if(nextptr->data<min){
//            min=nextptr->data;
//            swapNodes(currentptr,nextptr);
//            currentptr=currentptr->next;
//            nextptr=currentptr->next;
//
//        }else{
//            nextptr=nextptr->next;
//        }
//
//    }
//}

//void List::swapNodes(List::Node *n1, List::Node *n2) {
//    Node tmp;
//    tmp.data=n2->data;
//    //tmp.next=n2->next;
//    n2->data=n1->data;
//    //n2->next=n1->next;
//    n1->data=tmp.data;
//    //n1->next=tmp.next;
//}

ostream &operator<<(ostream & out, const List & aList){
    aList.display(out);
    return out;
}