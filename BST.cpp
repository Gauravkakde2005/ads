#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* Right;

    Node(int value) {
        data = value;
        left = nullptr;
        Right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value <= node->data) {
            node->left = insertNode(node->left, value);
        } else {
            node->Right = insertNode(node->Right, value);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->Right);
        }
    }
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->Right);
        }
    }

    void displayLeafNodes(Node* node) {
        if (node != nullptr) {
            if (node->left == nullptr && node->Right == nullptr) {
                cout << node->data << " ";
            }
            displayLeafNodes(node->left);
            displayLeafNodes(node->Right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            cout << "Inserted " << value << " as the root node." << endl;
        } else {
            insertNode(root, value);
            cout << "Inserted " << value << " into the tree." << endl;
        }
    }

    void displayInOrder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreOrder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayLeafNodes() {
        cout << "Leaf Nodes: ";
        displayLeafNodes(root);
        cout << endl;
    }
};

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
            cout << "Enter the element to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            tree.displayInOrder();
            tree.displayPreOrder();
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
