#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};



class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}  // Constructor to initialize the stack

    // Function to push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << data << " onto the stack.\n";
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop from an empty stack.\n";
            return -1;  // Return a special value indicating failure
        }
        Node* temp = top;
        int poppedData = top->data;
        top = top->next;
        delete temp;  // Free memory of the popped node
        cout << "Popped " << poppedData << " from the stack.\n";
        return poppedData;
    }

    // Function to peek the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1;  // Return a special value indicating failure
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        cout << "Stack destroyed.\n";
    }
};

int main() {
    Stack books;

    books.push(10);
    books.push(20);
    books.push(30);

    cout << "Top element is: " << books.peek() << "\n";

    books.pop();
    books.pop();

    cout << "Top element after popping is: " << books.peek() << "\n";

    books.pop();
    books.pop();  // Trying to pop from an empty stack

    return 0;
}
