#include <iostream>
#include <stack>
using namespace std;


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


Node* constructExpressionTree(const string& postfix) {
    stack<Node*> stk;


    for (size_t i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];


        if (isalnum(ch)) {
            stk.push(new Node(ch));
        }
        
        else {
            Node* newNode = new Node(ch);

 
            newNode->right = stk.top(); stk.pop();
            newNode->left = stk.top(); stk.pop();

           
            stk.push(newNode);
        }
    }


    return stk.top();
}


void displayTree(Node* root, int level = 0) {
    if (root != nullptr) {
     
        displayTree(root->right, level + 1);

    
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        cout << root->data << endl;

        displayTree(root->left, level + 1);
    }
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;


    Node* root = constructExpressionTree(postfix);

    cout << "\nExpression Tree:\n";
    displayTree(root);

    return 0;
}
