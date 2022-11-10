//
// Created by George Welson on 08-Nov-22.
//
#include "SStack.h"
Stack::Stack():myTop(-1) {}
bool Stack::empty() const {
    if(myTop<0)
        return true;
    else
        return false;
}
void Stack::push(const StackElement &value) {
    if(myTop<STACK_CAPACITY-1){
        ++myTop;
        myArray[myTop]=value;
    }else
        cout<<"This Stack is full"<<endl;
}
StackElement Stack::top() const {
    if(this->empty()==true){
        cout<<"This Stack is empty"<<endl;
        return NULL;
    }else
        return myArray[myTop];
}
void Stack::pop() {
    if(this->empty()==true)
        cout<<"This Stack is empty"<<endl;
    else
        --myTop;
}
void Stack::display(std::ostream &out) const {
    if(this->empty()==true)
        cout<<"This Stack is empty"<<endl;
    else
        for(int i=0;i<=myTop;i++)
            cout<<myArray[i]<<endl;
}
bool Stack::operator==(const Stack &rightSide) const {
    if(this->top()!=rightSide.top())
        return false;
    else {
        for (int i = 0; i <= this->myTop; i++) {
            if (this->myArray[i] != rightSide.myArray[i]) {
                return false;
            }
        }
        return true;
    }
}
ostream & operator<< (ostream & out, const Stack & aStack){
    aStack.display(out);
    return out;
}