//
// Created by George Welson on 08-Nov-22.
//
/*
#include "SStack.h"
template<typename StackElement>
Stack<StackElement>::Stack():myTop(-1) {

}
template<typename StackElement>
bool Stack<StackElement>::empty() const {
    if(myTop<0)
        return true;
    else
        return false;
}
template<typename StackElement>
void Stack<StackElement>::push(const StackElement &value) {
    if(myTop<STACK_CAPACITY-1){
        ++myTop;
        myArray[myTop]=value;
    }else
        cout<<"This Stack is full"<<endl;
}
template<typename StackElement>
StackElement Stack<StackElement>::top() const {
    if(this->empty()==true){
        cout<<"This Stack is empty"<<endl;
        return NULL;
    }else
        return myArray[myTop];
}
void Stack<StackElement>::pop() {
    if(this->empty()==true)
        cout<<"This Stack is empty"<<endl;
    else
        --myTop;
}
void Stack<StackElement>::display(std::ostream &out) const {
    if(this->empty()==true)
        cout<<"This Stack is empty"<<endl;
    else
        for(int i=0;i<=myTop;i++)
            cout<<myArray[i]<<endl;
}
bool Stack<StackElement>::operator==(const Stack<StackElement> &rightSide) const {
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
ostream & operator<< (ostream & out, const Stack<StackElement> & aStack){
    aStack.display(out);
    return out;
}*/