//
// Created by George Welson on 29-Oct-22.
//
#include "LList.h"
LList::LList():mySize(0),first(NULL){

}
LList::LList(const LList & origList):mySize(origList.getMySize()),first(NULL){
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
LList::~LList(){
    NodePointer oldptr=this->first;
    NodePointer newptr=oldptr->next;
    while(newptr!=NULL){
        delete oldptr;
        oldptr=newptr;
        newptr=newptr->next;
    }
}

bool LList::operator==(const LList &rightSide) const {
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
const LList &LList::operator=(const LList &rightSide) {
    this->mySize=rightSide.mySize;
    this->first=rightSide.first;
}

int LList::getMySize() const {
    return mySize;
}
bool LList::empty() const {
    if(mySize==0)return true;
    else return false;
}

void LList::insert(ElementType dataVal, int index) {
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
void LList::erase(int index){
    if (index < 0 || index >= mySize)
    {
        cerr << "Illegal location to delete -- " << index << endl;
        return; }
    mySize--;
    LList::NodePointer ptr,
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
int LList::nodeCount() {
    int i=0;
    for(NodePointer tmp=this->first;tmp!=NULL;tmp=tmp->next){
        ++i;
    }
    return i+1;
}
bool LList::ascendingOrder() {
    bool flag=true;
    for(NodePointer tmp=this->first;tmp!=NULL;tmp=tmp->next){
        if(tmp->data>tmp->next->data){
            flag=false;
            return flag;
        }
    }
    return flag;
}
void LList::reverse() {

}
void LList::display(ostream & out) const{
    if(this->empty()==true){
        cout<<"Empty LList\n";
        return;
    }else{
        for(NodePointer tmp=this->first;tmp!=NULL;tmp=tmp->next){
            out<<tmp->data<<'\t';
        }
    }
}
void LList::selectionSort()
{
    Node* temp = this->first;

    // Traverse the LList
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
//void LList::selectionSort() {
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

//void LList::swapNodes(LList::Node *n1, LList::Node *n2) {
//    Node tmp;
//    tmp.data=n2->data;
//    //tmp.next=n2->next;
//    n2->data=n1->data;
//    //n2->next=n1->next;
//    n1->data=tmp.data;
//    //n1->next=tmp.next;
//}

ostream &operator<<(ostream & out, const LList & aList){
    aList.display(out);
    return out;
}