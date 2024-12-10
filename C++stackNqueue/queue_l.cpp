#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to clean up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Enqueue: Add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue: Remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        Node* temp = front;
        int removedValue = temp->data;
        front = front->next;
        delete temp;

        // If the queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Dequeued: " << removedValue << endl;
        return removedValue;
    }

    // Peek: Get the value of the front element without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Display the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test the queue
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Trying to dequeue from an empty queue

    return 0;
}
