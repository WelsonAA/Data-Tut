//
//  Stack.hpp
//  StaticStack
//
/*-- Stack.h ---------------------------------------------------------------

  This header file defines a Stack data type.
  Basic operations:
    constructor:  Constructs an empty stack
    empty:        Checks if a stack is empty
    push:         Modifies a stack by adding a value at the top
    top:          Retrieves the top stack value; leaves stack unchanged
    pop:          Modifies stack by removing the value at the top
    display:      Displays all the stack elements

  Class Invariant:
    1. The stack elements (if any) are stored in positions
       0, 1, . . ., myTop of myArray.
    2. -1 <= myTop < STACK_CAPACITY
--------------------------------------------------------------------------*/
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
using namespace std;

const int STACK_CAPACITY = 128;
//typedef int StackElement;
//typedef StackElement T;
template<typename StackElement>
class Stack
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    Stack();
    /*------------------------------------------------------------------------
      Construct a Stack object.

      Precondition:  None.
      Postcondition: An empty Stack object has been constructed (myTop is
          initialized to -1 and myArray is an array with STACK_CAPACITY
          elements of type StackElement).
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
      Check if stack is empty.
      Precondition: None
      Postcondition: Returns true if stack is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void push(const StackElement& value);
    /*------------------------------------------------------------------------
      Add a value to a stack.

      Precondition:  value is to be added to this stack
      Postcondition: value is added at top of stack provided there is space;
           otherwise, a stack-full message is displayed and execution is
           terminated.
     -----------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*------------------------------------------------------------------------
      Display values stored in the stack.

      Precondition:  ostream out is open.
      Postcondition: Stack's contents, from top down, have been output to out.
     -----------------------------------------------------------------------*/

    StackElement top() const;
    /*------------------------------------------------------------------------
      Retrieve value at top of stack (if any).

      Precondition:  Stack is nonempty
      Postcondition: Value at top of stack is returned, unless the stack is
          empty; in that case, an error message is displayed and a "garbage
          value" is returned.
     -----------------------------------------------------------------------*/

    void pop();
    /*------------------------------------------------------------------------
      Remove value at top of stack (if any).

      Precondition:  Stack is nonempty.
      Postcondition: Value at top of stack has been removed, unless the stack
          is empty; in that case, an error message is displayed and
          execution allowed to proceed.
     -----------------------------------------------------------------------*/
    bool operator==(const Stack<StackElement> & rightSide ) const;
private:
    /***** Data Members *****/
    StackElement myArray[STACK_CAPACITY];
    int myTop;// **Why not stack element instead of int?**/ it is like an indication for
    //how many elements are there in the stack
}; // end of class declaration

//------ Prototype of output operator
template<typename StackElement>
ostream & operator<< (ostream & out, const Stack<StackElement> & aStack);

#endif /* Stack_hpp */
//
// Created by George Welson on 08-Nov-22.
//



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
template<typename StackElement>
void Stack<StackElement>::pop() {
    if(this->empty()==true)
        cout<<"This Stack is empty"<<endl;
    else
        --myTop;
}
template<typename StackElement>
void Stack<StackElement>::display(std::ostream &out) const {
    if(this->empty()==true)
        out<<"This Stack is empty"<<endl;
    else
        for(int i=0;i<=myTop;i++)
            out<<myArray[i]<<" ";
        out<<endl;
}
template<typename StackElement>
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
template<typename StackElement>
ostream & operator<< (ostream & out, const Stack<StackElement> & aStack){
    aStack.display(out);
    return out;
}