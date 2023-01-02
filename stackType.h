//
// Created by George Welson on 11-Nov-22.
//

#ifndef DATA_TUT_STACKTYPE_H
#define DATA_TUT_STACKTYPE_H
//
//  stackType.hpp
//  StaticStack
//
/*-- stackType.h ---------------------------------------------------------------

  This header file defines a stackType data type.
  Basic operations:
    constructor:  Constructs an empty stackType
    empty:        Checks if a stackType is empty
    push:         Modifies a stackType by adding a value at the top
    top:          Retrieves the top stackType value; leaves stackType unchanged
    pop:          Modifies stackType by removing the value at the top
    display:      Displays all the stackType elements

  Class Invariant:
    1. The stackType elements (if any) are stored in positions
       0, 1, . . ., myTop of myArray.
    2. -1 <= myTop < STACK_CAPACITY
--------------------------------------------------------------------------*/
//



#include <iostream>
using namespace std;

const int STACK_CAPACITY = 128;
//typedef int StackElement;
//typedef StackElement T;
template<typename StackElement>
class stackType
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    stackType();
    /*------------------------------------------------------------------------
      Construct a stackType object.

      Precondition:  None.
      Postcondition: An empty stackType object has been constructed (myTop is
          initialized to -1 and myArray is an array with STACK_CAPACITY
          elements of type StackElement).
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
      Check if stackType is empty.
      Precondition: None
      Postcondition: Returns true if stackType is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void push(const StackElement& value);
    /*------------------------------------------------------------------------
      Add a value to a stackType.

      Precondition:  value is to be added to this stackType
      Postcondition: value is added at top of stackType provided there is space;
           otherwise, a stackType-full message is displayed and execution is
           terminated.
     -----------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*------------------------------------------------------------------------
      Display values stored in the stackType.

      Precondition:  ostream out is open.
      Postcondition: stackType's contents, from top down, have been output to out.
     -----------------------------------------------------------------------*/

    StackElement top() const;
    /*------------------------------------------------------------------------
      Retrieve value at top of stackType (if any).

      Precondition:  stackType is nonempty
      Postcondition: Value at top of stackType is returned, unless the stackType is
          empty; in that case, an error message is displayed and a "garbage
          value" is returned.
     -----------------------------------------------------------------------*/

    void pop();
    /*------------------------------------------------------------------------
      Remove value at top of stackType (if any).

      Precondition:  stackType is nonempty.
      Postcondition: Value at top of stackType has been removed, unless the stackType
          is empty; in that case, an error message is displayed and
          execution allowed to proceed.
     -----------------------------------------------------------------------*/
    bool operator==(const stackType<StackElement> & rightSide ) const;
private:
    /***** Data Members *****/
    StackElement myArray[STACK_CAPACITY];
    int myTop;// **Why not stackType element instead of int?**/ it is like an indication for
    //how many elements are there in the stackType
}; // end of class declaration

//------ Prototype of output operator
template<typename StackElement>
ostream & operator<< (ostream & out, const stackType<StackElement> & aStack);

#endif //DATA_TUT_STACKTYPE_H
//
// Created by George Welson on 08-Nov-22.
//



template<typename StackElement>
stackType<StackElement>::stackType():myTop(-1) {

}
template<typename StackElement>
bool stackType<StackElement>::empty() const {
    if(myTop<0)
        return true;
    else
        return false;
}
template<typename StackElement>
void stackType<StackElement>::push(const StackElement &value) {
    if(myTop<STACK_CAPACITY-1){
        ++myTop;
        myArray[myTop]=value;
    }else
        cout<<"This stackType is full"<<endl;
}
template<typename StackElement>
StackElement stackType<StackElement>::top() const {
    if(this->empty()==true){
        cout<<"This stackType is empty"<<endl;
        return NULL;
    }else
        return myArray[myTop];
}
template<typename StackElement>
void stackType<StackElement>::pop() {
    if(this->empty()==true)
        cout<<"This stackType is empty"<<endl;
    else
        --myTop;
}
template<typename StackElement>
void stackType<StackElement>::display(std::ostream &out) const {
    if(this->empty()==true)
        out<<"This stackType is empty"<<endl;
    else
        for(int i=0;i<=myTop;i++)
            out<<myArray[i]<<" ";
    out<<endl;
}
template<typename StackElement>
bool stackType<StackElement>::operator==(const stackType<StackElement> &rightSide) const {
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
ostream & operator<< (ostream & out, const stackType<StackElement> & aStack){
    aStack.display(out);
    return out;
}

