
#include<iostream>
using namespace std;

class CircularQueue
{
private:
  int front , rear , size;
  int *queue;
  
  public:
  CircularQueue(int capacity)
  {
    size=capacity;
    queue = new int[size];
    front = rear = -1;
  }

  ~CircularQueue()
  {
    delete[] queue;
  }

  void enqueue(int value)
  {
    if ((rear + 1) % size==front)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(front == -1)
    {
        front = rear = 0;

    }
    else{
        rear = (rear + 1) % size;
    }
    queue[rear] = value;
    cout<< value <<"add to the queue" <<endl;
  }

  void dequeue() {
        if (front == -1) { // Check if queue is empty
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << queue[front] << " removed from the queue." << endl;
        if (front == rear) { // If only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % size; // Move front circularly
        }
    }
  void display() {
    if (front == -1) { // Check if the queue is empty
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i != rear; i = (i + 1) % size) { 
        cout << queue[i] << " "; // Print each element
    }
    cout << queue[rear] << endl; // Print the last element
}


};
int main()
{
    int capacity , choice , value;

    cout<<"enter the capacity of the circular queue:";
    cin>>capacity;
    CircularQueue cq(capacity);
     do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

