
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) { 
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); 
        }
        char choice;
        cout << "Enter your choice to insert " << value << " from left (l) or right (r) of " << node->data << ": ";
        cin >> choice;
        if (choice == 'l' && choice == 'L') {
            node->left = insertNode(node->left, value); 
        } else {
            node->right = insertNode(node->right, value); 
        }
        return node;
    }
    
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);         // Traverse left subtree
            cout << node->data << " ";   // Visit root
            inorder(node->right);        // Traverse right subtree
        }
    }

    
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";   // Visit root
            preorder(node->left);        // Traverse left subtree
            preorder(node->right);       // Traverse right subtree
        }
    }

    
    void displayLeafNodes(Node* node) {
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                cout << node->data << " "; 
            }
            displayLeafNodes(node->left);  
            displayLeafNodes(node->right); 
        }
    }

public:
    BinaryTree() { root = nullptr; } 

    
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value); // Create root if tree is empty
            cout << "Inserted " << value << " as root node." << endl;
        } else {
            insertNode(root, value);
            cout << "Inserted " << value << " into the tree." << endl;
        }
    }

    // Public method for inorder traversal
    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // Public method for preorder traversal
    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    // Public method to display leaf nodes
    void displayLeafNodes() {
        cout << "Leaf Nodes: ";
        displayLeafNodes(root);
        cout << endl;
    }
};

// Main function for menu-driven program
int main() {
    BinaryTree tree;
    int choice, value;

    do {
        cout << "\nBinary Tree Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display Inorder and Preorder Traversals" << endl;
        cout << "3. Display Leaf Nodes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            tree.displayInorder();
            tree.displayPreorder();
            break;

        case 3:
            tree.displayLeafNodes();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
