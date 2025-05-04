#include<iostream>
using namespace std;

// Node structure for stack elements
struct stackNode {
  int data;             // Stores the value
  stackNode * next;     // Pointer to next node

  stackNode(int d) {
    data = d;
    next = NULL;
  }
};

// Stack implemented using linked list
struct stack {
  stackNode * top;      // Points to the top of the stack
  int size;             // Tracks size of the stack

  // Constructor
  stack() {
    top = NULL;
    size = 0;
  }

  // Push operation: adds an element to the top of the stack
  void stackPush(int x) {
    stackNode * element = new stackNode(x);
    element -> next = top;
    top = element;
    cout << "Element pushed" << "\n";
    size++;
  }

  // Pop operation: removes and returns the top element
  int stackPop() {
    if (top == NULL) {
      return -1; // Stack underflow
    }
    int topData = top -> data;
    stackNode * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }

  // Returns current size of the stack
  int stackSize() {
    return size;
  }

  // Checks if stack is empty
  bool stackIsEmpty() {
    return top == NULL;
  }

  // Returns the top element without removing it
  int stackPeek() {
    if (top == NULL) return -1; // Stack is empty
    return top -> data;
  }

  // Prints all elements in the stack from top to bottom
  void printStack() {
    stackNode * current = top;
    while (current != NULL) {
      cout << current -> data << " ";
      current = current -> next;
    }
  }
};

int main() {
  stack s;
  s.stackPush(10); // Push element 10
  cout << "Element popped: " << s.stackPop() << "\n"; // Pop element
  cout << "Stack size: " << s.stackSize() << "\n"; // Print size
  cout <<"Stack empty or not? "<< s.stackIsEmpty() << "\n"; // Check if empty
  cout << "stack's top element: " << s.stackPeek() << "\n"; // Peek top
  return 0;
}
