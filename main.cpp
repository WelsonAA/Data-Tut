#include <iostream>
#include "LList.h"
using namespace std;
int main() {

    List l1;
    l1.insert(15,0);
    l1.insert(28,0);
    l1.insert(49,1);
    l1.insert(0,2);
    l1.insert(420,1);
    cout<<l1;
    l1.selectionSort();
    cout<<l1;
//    string arr[]={"zxy","zay","add","abc","klm"};
//    sort(arr,arr+5);
//    Question1();
   /* queueType q1;
    q1.enqueue(5);
    q1.enqueue(15);
    q1.enqueue(500);
    q1.enqueue(20);
    q1.enqueue(75);
    q1.enqueue(125);
    q1.enqueue(420);
    cout<<"Q1: "<<q1;
    q1.movNthFront(3);
    cout<<"Q1 after moving 3rd element to front: "<<q1;
    q1.dequeue();
    cout<<"Q1 after dequeuing 1st element: "<<q1;
    q1.movNthFront(4);
    cout<<"Q1 after moving 4th element to front: "<<q1;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<"Q1 after dequeuing 1st element 3 times: "<<q1;
    q1.enqueue(670);
    q1.enqueue(540);
    cout<<"Q1 after enqueuing 2 new elements: "<<q1;
    q1.dequeue();
    cout<<"Q1 after dequeuing 1st element: "<<q1;
    q1.movNthFront(2);
    cout<<"Q1 after moving 2nd element to front: "<<q1;*/
}


    /*
    stackType<int> s1;
    s1.push(52);
    s1.push(27);
    s1.push(252);
    s1.pop();
    cout << "s1 after pop: " << s1;
    stackType<int> s2;
    s2.push(52);
    s2.push(27);
    s2.push(252);
    cout << "s1 before pop: " << s2;
    cout << "Comparing s1 and s2 before popping s2: " << (s1 == s2) << endl;
    s2.pop();
    cout << "s2 aftr pop: " << s2;
    cout << "Comparing s1 and s2 after popping s2: " << (s1 == s2) << endl;
}*/











    /*
    */












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
//}
