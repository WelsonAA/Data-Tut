//
// Created by George Welson on 07-Nov-22.
//
#include <iostream>
#include <stack>
using namespace std;
int Question1() {
    string input;
    cout<<"Enter a String: ";
    getline (cin,input);
    bool flag=true;
    stack<char> groups;
    for(int i=0;i<input.size();i=i+1){
        if( (input.at(i)>='0' && input.at(i)<='9') || input.at(i)=='+' || input.at(i)=='-' || input.at(i)=='/'|| input.at(i)=='*' || input.at(i)==' ' ){
            continue;
        }
        if( input.at(i)=='{' || input.at(i)=='(' ){
            groups.push(input.at(i));
        }
        else if(((groups.top() == '{' && input.at(i) == '}') || (groups.top() == '(' && input.at(i) == ')'))&&(groups.empty()==false))
            groups.pop();
        else{
            flag=false;
            break;
        }
    }
    if(groups.empty()==false){
        cout<<"Does not match"<<"\n";
    }else{
        if(flag==true)
            cout<<"Match"<<"\n";
        else
            cout<<"Does not match"<<"\n";
    }
    return 0;
}
