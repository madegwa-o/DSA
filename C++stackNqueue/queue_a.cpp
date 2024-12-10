#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Pointer to the array
    int capacity;  // Maximum capacity of the queue
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int count;     // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        arr = new int[size];
    }

    // Destructor to clean up memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue: Add an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << "." << endl;
            return;
        }

        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        count++;

        cout << "Enqueued: " << value << endl;
    }

    // Dequeue: Remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }

        int removedValue = arr[front];
        front = (front + 1) % capacity; // Circular increment
        count--;

        cout << "Dequeued: " << removedValue << endl;
        return removedValue;
    }

    // Peek: Get the value of the front element without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Check if the queue is full
    bool isFull() const {
        return count == capacity;
    }

    // Display the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Main function to test the queue
int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

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
