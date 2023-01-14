#include "SList.h"
#include "LList.h"
using namespace std;
#include <iostream>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

const int threshold = 20;

void insertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int* arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left - 1;
    int j = right + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quicksort(int* arr, int left, int right) {
    if (right - left <= threshold) {
        insertionSort(arr, left, right);
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quicksort(arr, left, pivotIndex);
    quicksort(arr, pivotIndex + 1, right);
}

int main() {
    int arr[10000];
    SList sL1;
    // fill the array with elements
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);

    for (int i = 0; i < 10000; i++) {
        //arr[i] = dist(gen);
        sL1.insert(dist(gen),i);
    }
    sL1.heapSort();
    cout<<sL1;
    //quicksort(arr, 0, 9999);
    for(int i=0;i<10000;i++){
        //cout<<arr[i]<<'\t';

    }
    return 0;
}
/*
int main() {

    SList l1;
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
    SList myList;
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
    SList copy(myList);
    cout<<"original list:\n"<<myList;
    cout<<"copied list:\n"<<copy;
    cout<<myList.empty()<<endl;
    cout<<myList.getMySize()<<endl;
    //copy.insert(70,0);
    cout<<bool(copy==myList)<<endl;*/
    //Question1();
//}
