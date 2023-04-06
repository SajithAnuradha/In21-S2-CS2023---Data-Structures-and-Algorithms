#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
/// creating stack using linkedlist
using namespace std;

// Define the node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Define the Stack class using a linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {        // push to the values in the stack
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else {
            return top->data;
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            Node* current = top;
            cout << "Stack elements: ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack NewStack;
auto start = chrono::steady_clock::now();
//for (int i=0;i<10;i++){
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
