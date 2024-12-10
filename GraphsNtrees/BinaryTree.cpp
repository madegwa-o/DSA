#include <iostream>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to create a node
    TreeNode(int val) {
        value = val;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:
    TreeNode* root;
    
    // Constructor to initialize the tree
    BinaryTree() {
        root = nullptr;
    }
    
    // Function to insert a node in the tree
    TreeNode* insert(TreeNode* node, int value) {
        // If the tree is empty, return a new node
        if (node == nullptr) {
            return new TreeNode(value);
        }
        
        // Otherwise, recur down the tree
        if (value < node->value) {
            node->left = insert(node->left, value);  // Insert in the left subtree
        } else {
            node->right = insert(node->right, value);  // Insert in the right subtree
        }
        
        return node;
    }
    
    // Function to do an inorder traversal (left, root, right)
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);  // Traverse left subtree
            cout << node->value << " ";  // Print root value
            inorder(node->right);  // Traverse right subtree
        }
    }
    
    // Wrapper function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }
    
    // Wrapper function to start inorder traversal
    void inorder() {
        inorder(root);
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;
    
    // Insert elements into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    
    // Print inorder traversal of the tree
    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;
    
    return 0;
}
