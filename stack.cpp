#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void Push(int value) {
        if (isFull()) {
            cout << "Stack Overflow " << value << endl;
        }
        else {
            top++;
            arr[top] = value;
        }
    }

    void Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            top--;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack(5);

    myStack.Push(10);
    auto start = chrono::steady_clock::now();
    myStack.Push(20);
    myStack.Push(500);
     auto end = chrono::steady_clock::now();
    myStack.Display(); // Stack elements: 30 20 10

    myStack.Pop();
    myStack.Display(); // Stack elements: 20 10

    cout << "Stack top: " << myStack.StackTop() << endl; // Stack top: 20

    myStack.Push(40);
    myStack.Push(50);
    myStack.Push(60); // Stack overflow, cannot push 60

    myStack.Display(); // Stack elements: 50 40 20 10
    auto diff = end - start;
    cout << "Execution time: " << chrono::duration <double, micro> (diff).count() << " microseconds" << endl;

    return 0;
}

