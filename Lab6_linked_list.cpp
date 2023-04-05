#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Define the node class for the linked list
class Node {
    public:
        int data;
        Node* next;
};

// Define the stack class
class Stack {
    private:
        Node* top;   // Pointer to the top node in the stack
    public:
        Stack() {   // Constructor to initialize an empty stack
            top = NULL;
        }
        ~Stack() {  // Destructor to free memory allocated for the stack
            Node* p = top;
            while (top) {
                top = top->next;
                delete p;
                p = top;
            }
        }
        void Push(int value) {   // Function to insert a new element into the stack
            Node* new_node = new Node;
            new_node->data = value;
            new_node->next = top;
            top = new_node;
        }
        int Pop() {   // Function to remove the top element from the stack and return its value
            if (isEmpty()) {
                cout << "Error: stack underflow" << endl;
                return -1;
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
        bool isEmpty() {   // Function to check if the stack is empty
            return top == NULL;
        }
        int stackTop() {   // Function to return the value of the top element in the stack
            if (isEmpty()) {
                cout << "Error: stack is empty" << endl;
                return -1;
            }
            return top->data;
        }
        void Display() {   // Function to print the elements in the stack
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack elements:" << endl;
            Node* p = top;
            while (p) {
                cout << p->data << " ";
                p = p->next;
            }
            cout<<endl;
        }
};

// Main function to test the Stack class
int main() {
    
    auto start_time = high_resolution_clock::now();
    
    Stack s;
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display(); 
    
     auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
     cout << "Program duration: "
         << duration.count() / 1000000.0 << " seconds, "
         << duration.count() % 1000000 << " microseconds" << endl;
    return 0;
}
