#include <iostream>
using namespace std;


struct Node {
    int data;      
    Node* next;     
};


void push(Node*& top, int value) {
    Node* newNode = new Node(); 
    newNode->data = value;       
    newNode->next = top;         
    top = newNode;            
    cout << "Element " << value << " successfully pushed onto the stack!" << endl;
}


void pop(Node*& top) {
    if (top == nullptr) {  
        cout << "Stack underflow! No elements to pop." << endl;
        return;
    }
    Node* temp = top;      
    cout << "Element " << top->data << " successfully popped from the stack!" << endl;
    top = top->next;       
    delete temp;          
}


void display(Node* top) {
    if (top == nullptr) {  
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack contents (top to bottom): ";
    Node* temp = top;      
    while (temp != nullptr) {
        cout << temp->data << " ";  
        temp = temp->next;         
    }
    cout << endl;
}

int main() {
    Node* top = nullptr; 
    int choice, value;

    while (true) {
      
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                cout << "Enter the value to push: ";
                cin >> value;
                push(top, value);
                break;
            }
            case 2: { 
                pop(top);
                break;
            }
            case 3: { 
                display(top);
                break;
            }
            case 4: { 
                cout << "Exiting program." << endl;
                return 0;
            }
            default: 
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
