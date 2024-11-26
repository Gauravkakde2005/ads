#include <iostream>
using namespace std;

class max_heap
{
public:
    int *marks;
    int size;

    max_heap(int arr[], int n)
    {
        marks = arr;
        size = n;
    }

    void maxheapify(int arr[], int n, int i)
    {
        int largest = i;
        cout << "\nCurrent value of i = " << i << endl;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        cout << "Largest No. is = " << largest << endl;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);

            for (int k = 0; k < size; k++)
            {
                cout << " | " << arr[k];
            }

            maxheapify(arr, n, largest);

            cout << "\nAfter recursive call:\n";

            for (int k = 0; k < size; k++)
            {
                cout << " | " << arr[k];
            }
        }
    }

    int maxmarks()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            maxheapify(marks, size, i);
        }
        return marks[0];
    }
};

int main()
{
    int count;
    cout << "Enter the number of students: ";
    cin >> count;

    int arr[count];

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the marks of student no. " << i << " : ";
        cin >> arr[i];
    }

    max_heap h(arr, count);
    int maxmarks = h.maxmarks(); // Fixed variable name to maxmarks

    cout << "\nMaximum marks in class = " << maxmarks;

    return 0;
}
