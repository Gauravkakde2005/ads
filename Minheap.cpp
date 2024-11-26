#include <iostream>

using namespace std;

class min_heap
{

public:
    int *marks;
    int size;

    min_heap(int arr[], int n)
    {
        marks = arr;
        size = n;
    }

    void minheapify(int arr[], int n, int i)
    {
        int smallest = i;
        cout << "\nCurrent value of i = " << i << endl;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
        {
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        cout << "\nSmallest No. is = " << smallest << endl;

        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);

            for (int k = 0; k < size; k++)
            {
                cout << " | " << arr[k];
            }

            minheapify(arr, n, smallest);

            cout << "\nAfter recursive call:\n";

            for (int k = 0; k < size; k++)
            {
                cout << " | " << arr[k];
            }
        }
    }

    int minmarks()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            minheapify(marks, size, i);
        }
        return marks[0];
    }
};

int main()
{
    int count;
    cout<<"Enter the number of students: ";
    cin>>count;

    int arr[count];

    for (int i = 0; i < count; i++)
    {
        cout<<"Enter the marks of student no. "<<i<<" :";
        cin>>arr[i];
    }
    min_heap h(arr,count);
    int minmarks = h.minmarks();

    cout<<"\nMinimum marks in class = "<<minmarks;

    return 0;
    
}