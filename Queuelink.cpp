#include <iostream>
using namespace std;


struct Node {
    int data;       
    Node* next;    
};

void enqueue(Node*& front, Node*& rear, int value) {
    Node* newNode = new Node();  
    newNode->data = value;       
    newNode->next = nullptr;     
    if (rear == nullptr) {     
        front = rear = newNode;  
    } else {
        rear->next = newNode;   
        rear = newNode;        
    }
    cout << "Element " << value << " successfully enqueued into the queue!" << endl;
}


void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {     
        cout << "Queue underflow! No elements to dequeue." << endl;
        return;
    }
    Node* temp = front;        
    cout << "Element " << front->data << " successfully dequeued from the queue!" << endl;
    front = front->next;         
    delete temp;                

    if (front == nullptr) {     
        rear = nullptr;       
    }
}


void display(Node* front) {
    if (front == nullptr) {   
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue contents (front to rear): ";
    Node* temp = front;         
    while (temp != nullptr) {
        cout << temp->data << " ";  
        temp = temp->next;       
    }
    cout << endl;
}

int main() {
    Node* front = nullptr; 
    Node* rear = nullptr;   
    int choice, value;

    while (true) {
       
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Enqueue operation
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(front, rear, value);
                break;
            }
            case 2: { // Dequeue operation
                dequeue(front, rear);
                break;
            }
            case 3: { // Display operation
                display(front);
                break;
            }
            case 4: { // Exit
                cout << "Exiting program." << endl;
                return 0;
            }
            default: // Invalid input
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
