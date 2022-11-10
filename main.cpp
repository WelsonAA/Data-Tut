#include <iostream>
#include "LList.h"
//#include "Q1.h"
#include "SQueue.h"
using namespace std;
int main() {
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(15);
    q1.enqueue(500);
    q1.enqueue(20);
    q1.enqueue(75);
    q1.enqueue(125);
    q1.enqueue(420);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<q1<<endl;
    q1.movNthFront(4);
    cout<<q1;









    /*Stack s1;
    s1.push(52);
    cout<<s1.empty()<<endl;
    cout<<s1;
    s1.push(27);
    s1.push(252);
    cout<<s1.top()<<endl;
    cout<<s1;
    s1.pop();
    cout<<s1;*/



    /*
    List myList;
    cout<<myList.empty()<<endl;
    myList.insert(20,0);
    myList.insert(50,1);
    myList.insert(30,2);
    myList.insert(60,3);
    myList.insert(200,0);
    myList.insert(500,1);
    myList.insert(300,2);
    myList.insert(600,3);
    cout<<myList;
    myList.erase(1);
    myList.erase(5);
    myList.erase(3);
    List copy(myList);
    cout<<"original list:\n"<<myList;
    cout<<"copied list:\n"<<copy;
    cout<<myList.empty()<<endl;
    cout<<myList.getMySize()<<endl;
    //copy.insert(70,0);
    cout<<bool(copy==myList)<<endl;*/
    //Question1();
}
