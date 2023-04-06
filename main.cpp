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
    int size=1000;
   // cout<<"give the size of the array";
   // cin>>size;
    Stack NewStack(size);
    auto start = chrono::steady_clock::now();
    NewStack.push(8);
    NewStack.push(10);
    NewStack.push(5);
    NewStack.push(11);
    NewStack.push(15);
    NewStack.push(23);
    NewStack.push(6);
    NewStack.push(18);
    NewStack.push(20);
    NewStack.push(17);

    NewStack.Display();

    NewStack.Pop();
    NewStack.Pop();
    NewStack.Pop();
    NewStack.Pop();
    NewStack.Pop();

    NewStack.Display();

    NewStack.push(4);
    NewStack.push(30);
    NewStack.push(3);
    NewStack.push(1);

    NewStack.Display();





     auto end = chrono::steady_clock::now();



    auto diff = end - start;
    cout << "Execution time: " << chrono::duration <double, micro> (diff).count() << " microseconds" << endl;

    return 0;
}
