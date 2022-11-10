//
// Created by George Welson on 08-Nov-22.
//
#include "SQueue.h"
Queue::Queue():myFront(-1),myBack(-1) {

}

bool Queue::empty() const {
    if(this->myBack==-1 && this->myFront==-1)
        return true;
    else
        return false;
}

void Queue::enqueue(const QueueElement &value) {
    if(this->myBack==QUEUE_CAPACITY-1){
        cout<<"This Queue is full\n";
        return;
    }
    if(this->empty()==true){
        ++this->myFront;
        ++myBack;
        this->myArray[this->myFront]=value;
    }else{
        ++this->myBack;
        this->myArray[this->myBack]=value;
    }
}

void Queue::display(ostream &out) const {
    if(this->empty()==true)
        out<<"This Queue is empty\n";
    else {
        for(int i=myFront;i<myBack+1;i++)
            out<<this->myArray[i]<<endl;
    }
}

QueueElement Queue::front() const {
    if(this->empty()==true) {
        cout << "This Queue is empty\n";
        return -1;
    }
    else{
        return this->myArray[this->myFront];
    }
}
QueueElement Queue::back() const {
    if(this->empty()==true) {
        cout << "This Queue is empty\n";
        return -1;
    }
    else{
        return this->myArray[this->myBack];
    }
}
void Queue::dequeue() {
    if(this->empty()==true) {
        cout << "This Queue is empty\n";
    }else if(this->myFront==this->myBack){
        this->myFront=-1;
        this->myBack=-1;
    }else{
        this->myFront++;
    }
}

void Queue::movNthFront(int n) {
    int k=n+(myFront-1);
    if(k>myBack||k<=myFront){
        cout<<"Invalid index\n";
        return;
    }
    else{
        for(int i=k;i>myFront;i--){
            swap(i,i-1);
        }
    }
}

void Queue::swap(int x, int y) {
    if(x>myBack||x<=myFront||y>myBack||y<myFront){
        cout<<"Invalid index at swap\n";
        return;
    }else{
        QueueElement temp= this->myArray[x];
        this->myArray[x]=this->myArray[y];
        this->myArray[y]=temp;
    }
}

ostream &operator<<(ostream &out, const Queue &aList) {
    aList.display(out);
    return out;
}
