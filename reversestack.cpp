
#include<iostream>
using namespace std;

struct Stack{
    char stack[100];
    int top;
    Stack() {top = -1;}

    void push(char ch){
         stack[++top] = ch;
    }

    char pop(){
         return stack[top--];
    }

    bool isEmpty(){
         return top == -1;
    }
};


string printRiversedStrinng(string str){

    Stack s;
    string reversedStr = "";
  
    for (int i = 0; i < str.length(); i++) {
        char c = str[i]; 
        s.push(c);
    }

    while(!s.isEmpty()){
        reversedStr += s.pop();
    }
    return reversedStr;
}

bool isPalinfrome(string received_str, string str) {
    if(received_str == str){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str, recieved_str;
    cout << "Enter string :";
    cin >> str;

    recieved_str = printRiversedStrinng(str);
    cout << "Original string:" << str << endl;
    cout << "Reversed string:" << recieved_str << endl;

    if(isPalinfrome(recieved_str, str)){
        cout << "The string is palidrome." << endl;
    }
    else{
        cout << "The string is not a palidrom." << endl;
    }

    return 0;
}