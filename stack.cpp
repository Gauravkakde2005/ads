#include <iostream>
using namespace std;

int main() {
    int choice, ele, top = -1;
    const int num = 10; 
    int stack[num];     

    do {
        
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                if (top == num - 1) {
                    cout << "Stack overflow!" << endl;
                } else {
                    cout << "Enter the element to push: ";
                    cin >> ele;
                    stack[++top] = ele; 
                    cout << "Element successfully inserted!" << endl;
                }
                break;
            }
            case 2: { 
                if (top == -1) {
                    cout << "Stack underflow!" << endl;
                } else {
                    cout << "Element " << stack[top--] << " successfully deleted!" << endl;
                
                }
                break;
            }
            case 3: { 
                if (top == -1) {
                    cout << "Stack is empty!" << endl;
                } else {
                    cout << "Stack contents (top to bottom): ";
                    for (int i = top; i >= 0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 4: { 
                cout << "Exiting program." << endl;
                return 0;
            }
            default: 
                cout << "Invalid input! Please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}
