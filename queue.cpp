#include <iostream>
using namespace std;

int main() {
    int front = -1, rear = -1;
    const int size = 10; 
    int queue[size];
    int choice, ele;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Enqueue
                if (rear == size - 1) {
                    cout << "Queue overflow!" << endl;
                } else {
                    cout << "Enter the element to enqueue: ";
                    cin >> ele;
                    if (front == -1) front = 0; // Initialize front on first enqueue
                    queue[++rear] = ele;
                    cout << "Element successfully inserted!" << endl;
                }
                break;
            }
            
            case 2: { // Dequeue
                if (front == -1 || front > rear) {
                    cout << "Queue underflow!" << endl;
                    front = rear = -1; // Reset queue
                } else {
                    cout << "Element " << queue[front++] << " successfully deleted!" << endl;
                }
                break;
            }
            case 3: { // Display
                if (front == -1 || front > rear) {
                    cout << "Queue is empty!" << endl;
                } else {
                    cout << "Queue contents (front to rear): ";
                    for (int i = front; i <= rear; i++) {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 4: { // Exit
                cout << "Exiting program." << endl;
                return 0;
            }
            default:
                cout << "Invalid input! Please try again." << endl;
        }
    }

    return 0;
}
 