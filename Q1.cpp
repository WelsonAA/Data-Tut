//
// Created by George Welson on 07-Nov-22.
//



/*******Assignment 1********/



#include <iostream>
#include <stack>

using namespace std;

int Quesion1() {
    string str;
    cout<<"Enter a String: ";
    getline (cin,str);
    bool flag=true;
    stack<char> st;
    for(int i=0;i<str.size();i++){
        if( (str.at(i)>='0' && str.at(i)<='9') || str.at(i)=='+' || str.at(i)=='-' || str.at(i)=='/'|| str.at(i)=='*' || str.at(i)==' ' ){
            continue;
        }
        if( str.at(i)=='{' || str.at(i)=='(' ){
            st.push(str.at(i));
        }
        else if(!st.empty() &&((st.top() == '{' && str.at(i) == '}') || (st.top() == '(' && str.at(i) == ')')))
            st.pop();
        else{
            flag=false;
            break;
        }
    }
    if(!st.empty()){
        cout<<"Does not match"<<"\n";
    }else{
        if(flag)
            cout<<"Match"<<"\n";
        else
            cout<<"Does not match"<<"\n";
    }
    return 0;
}
