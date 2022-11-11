//
// Created by George Welson on 08-Nov-22.
//
#include "SQueue.h"
Queue::Queue():myFront(-1),myBack(-1),mySize(0){

}
bool Queue::empty() const {
    if(this->myBack==-1 && this->myFront==-1)
        return true;
    else
        return false;
}
bool Queue::full() const {
    if((myFront==myBack)&&(empty()!=true))
        return true;
    else
        return false;
}
void Queue::enqueue(const QueueElement &value) {
    if(full()==true){
        cout<<"This Queue is full\n";
        return;
    }
    if(this->empty()==true){
        ++this->myFront;
        myBack+=2;
        this->myArray[this->myFront]=value;
    }else{
        this->myArray[this->myBack]=value;
        myBack=(myBack+1)%(QUEUE_CAPACITY);
    }
    mySize++;
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
        return;
    }else if(this->myFront==this->myBack-1){
        this->myFront=-1;
        this->myBack=-1;
    }else{
        this->myFront=(myFront+1)%QUEUE_CAPACITY;
    }
    mySize--;
}
void Queue::movNthFront(int n) {
    //validating user input
    if(n>QUEUE_CAPACITY||n<=1||n>mySize) {
        cout << "Invalid index\n";
        return;
    }
    QueueElement newArray[QUEUE_CAPACITY];
    if(full()==true){
        int j=0;
        for (int i = myFront; j<QUEUE_CAPACITY; i = (i + 1) % (QUEUE_CAPACITY)) {
            newArray[j]= this->myArray[i];
            j++;
        }
        // 0 1 2 3 4 5
    }else{
        int j=0;
        for (int i = myFront; i != myBack; i = (i + 1) % (QUEUE_CAPACITY)) {
            newArray[j]= this->myArray[i];
            j++;
        }
    }
    for(int i=0;i<mySize;i++){
        this->myArray[i]=newArray[i];
    }
    if(full()==true){
        myFront=0;
        myBack=0;
    }else if(empty()==true){
        myFront=-1;
        myBack=-1;
    }else{
        myFront=0;
        myBack=mySize;
    }
    int k=n+(myFront-1);
    if(k<1||k>QUEUE_CAPACITY){
        cout<<"Invalid index\n";
        return;
    }
    else{
        for(int i=k;i>myFront;i--){
            swap(i,(i - 1));
        }
    }
}
void Queue::swap(int x, int y) {
    QueueElement temp= this->myArray[x];
    this->myArray[x]=this->myArray[y];
    this->myArray[y]=temp;
}
void Queue::display(ostream &out) const {
    if(this->empty()==true)
        out<<"This Queue is empty\n";
    else {
        if(full()==true){
            int j=0;
            for (int i = myFront; j<QUEUE_CAPACITY; i = (i + 1) % (QUEUE_CAPACITY)) {
                out << this->myArray[i] << " ";
                j++;
            }
        }else{
            for (int i = myFront; i != myBack; i = (i + 1) % (QUEUE_CAPACITY))
                out << this->myArray[i] << " ";
        }
        out<<endl;
    }
}
int Queue::size() const {
    return mySize;
}
ostream &operator<<(ostream &out, const Queue &aList) {
    aList.display(out);
    return out;
}
