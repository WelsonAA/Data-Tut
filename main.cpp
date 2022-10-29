#include <iostream>
#include "LList.h"
using namespace std;
int main() {
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
    cout<<bool(copy==myList)<<endl;
}
