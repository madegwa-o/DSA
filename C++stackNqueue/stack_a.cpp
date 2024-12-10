#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Dynamic array to store stack elements
    int top;        // Index of the top element
    int capacity;   // Maximum size of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];  // Allocate memory for the stack
        top = -1;                 // Initialize top to -1 (empty stack)
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;  // Increment top and store the value
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
            return -1;  // Return a special value indicating failure
        }
        return arr[top--];  // Return the top value and decrement top
    }

    // Function to peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1;  // Return a special value indicating failure
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
        cout << "Stack destroyed.\n";
    }
};

int main() {
    Stack stack(5);  // Create a stack with a capacity of 5

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << "\n";

    stack.pop();
    cout << "Top element after popping is: " << stack.peek() << "\n";

    stack.pop();
    stack.pop();
    stack.pop();  // Attempt to pop from an empty stack

    return 0;
}
