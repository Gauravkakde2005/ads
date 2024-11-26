#include <iostream>
#include <stack>
using namespace std;

// Node structure for the Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to construct the Expression Tree from a prefix expression
Node* constructExpressionTree(const string& prefix) {
    stack<Node*> stk;

    // Traverse the prefix expression from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If the character is an operand, create a node and push it to the stack
        if (isalnum(ch)) {
            stk.push(new Node(ch));
        }
        // If the character is an operator, create a new node and set its children
           else {
            Node* newNode = new Node(ch);

            // Pop two nodes from the stack as children
            newNode->left = stk.top(); stk.pop();
            newNode->right = stk.top(); stk.pop();

            // Push the new node back to the stack
            stk.push(newNode);
        }
    }

    // The last node in the stack is the root of the Expression Tree
    return stk.top();
}

// Function to display the Expression Tree structure
void displayTree(Node* root, int level = 0) {
    if (root != nullptr) {
        // Display right child first (for visual alignment)
        displayTree(root->right, level + 1);

        // Print current node with indentation
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        cout << root->data << endl;

        // Display left child
        displayTree(root->left, level + 1);
    }
}

int main() {
    string prefix;
    cout << "Enter a prefix expression: ";
    cin >> prefix;

    // Construct the Expression Tree
    Node* root = constructExpressionTree(prefix);

    // Display the Expression Tree
    cout << "\nExpression Tree:\n";
    displayTree(root);

    return 0;
}
