using namespace std;
#include<iostream>

struct Node
{
    int marks;
    Node* left;
    Node* right;

    Node(int value)
    {
        marks = value;
        left = nullptr;
        right = nullptr;

    }
};

Node* insert(Node* root , int marks)
{
    if(root == nullptr)
    {
        return new Node(marks);
    }
    if(marks < root->marks)
    {
        root->left = insert(root->left,marks);
    }
    else{
        root->right= insert(root->right,marks);
    }
    return root;
}
//logic to convert it into the tree traversal technique
void inOrder(Node* root)
{
    if(root==nullptr)
    {
       return;
    }
inOrder(root->left);
cout<<root->marks<<" ";
inOrder(root->right);

}

int minmarks(Node* root)
{
    if(root==nullptr)
{
    cout<<"marks is not present"<<endl;
    return -1;

}
while(root->left != nullptr)
{
     root=root->left;
}
return root->marks;
}

int maxmarks(Node* root) {
    // Handle empty tree
    if (root == nullptr) {
        cout << "Tree is empty. Marks are not present." << endl;
        return -1; // Indicate an error value
    }

    // Traverse to the rightmost node
    while (root->right != nullptr) {
        root = root->right;
    }

    // Return the marks of the rightmost node
    return root->marks;
}

int main() {
    Node* root = nullptr;  // Start with an empty BST
    int choice, marks;

    do {
        cout << "\nBinary Search Tree Operations for Student Marks:\n";
        cout << "1 - Insert Marks\n";
        cout << "2 - Display Marks in Ascending Order (In-order Traversal)\n";
        cout << "3 - Display Minimum Marks\n";
        cout << "4 - Display Maximum Marks\n";
        cout << "5 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter marks to insert: ";
                cin >> marks;
                root = insert(root, marks);
                break;

            case 2: 
                cout << "Marks in Ascending Order: ";
                inOrder(root);
                cout << endl;
                break;

            case 3: 
                cout << "Minimum Marks: " << minmarks(root) << endl;
                break;

            case 4: 
                cout << "Maximum Marks: " << maxmarks(root) << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default: 
                cout << "Invalid choice, please try again.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}
