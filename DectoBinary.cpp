#include <iostream>
#include <stack>
using namespace std;

void decimalToBinary(int number) {
    stack<int> binaryStack;

    // Edge case: If the number is 0, its binary representation is "0"
    if (number == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    // Push remainders to stack
    while (number > 0) {
        binaryStack.push(number % 2); // Get the remainder (0 or 1)
        number /= 2;                 // Divide the number by 2
    }

    // Pop and display the binary number
    cout << "Binary: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();  // Print top element
        binaryStack.pop();          // Remove top element
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    decimalToBinary(number);

    return 0;
}
