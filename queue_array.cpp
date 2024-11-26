#include <iostream>
using namespace std;

int queue[10]; 
int front = -1;
int rear = -1;

void enqueue(){
    int value;
    if(rear == 9){
        cout << "Queue is overflow.." << endl;
    }
    else{
        cout << "Enter queue element :";
        cin >> value;
        if(front ==-1){
            front = 0;
        }
        rear++;
        queue[rear] = value;
        cout << "Enqueued :" << value << endl;
    }
}

void dequeue(){
    int val;
    if(front == -1 || front > rear){
        cout << "Queue is empty." << endl;
    }
    else{
        val = queue[front];
        if(front == rear ){
            front = rear = 0;
        }
        else{
            front = front + 1;
        }
    }
    cout << val << " dequeued from queue." << endl;
}

void display(){
    if(front == -1 || front > rear){
        cout << "Queue is empty." << endl;
    }
    else{
        cout << "Queue elements are : ";
        for(int i = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void peek(){
    if(front == -1 || front > rear){
        cout << "Queue is empty." << endl;
    }
    else{
        cout << "Front element: " << queue[front] << endl;
    }
}

int main(){

    int choice;
    bool running = true; //flag to control the loop
    do
    {
        cout << "1 - ENQUEUE ELEMENT\n";
        cout << "2 - DEQUEUE ELEMENT\n";
        cout << "3 - DISPLAY ELEMENTS\n";
        cout << "4 - DISPLAY FRONT ELEMENT\n";
        cout << "5 - EXIT\n";
        cout << "Provide your choice :";
        cin >> choice;

        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: running = false;
                    break;
            default : cout << "Invalid choice.\n";
                    break;
        }
    }while(running);

    return 0;
}
