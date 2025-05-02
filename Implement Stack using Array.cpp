#include<bits/stdc++.h>
using namespace std;

// Custom Stack class
class Stack {
  int size;     // Total capacity of the stack
  int *arr;     // Pointer to dynamic array to store stack elements
  int top;      // Index of the top element

public:
  // Constructor: Initializes the stack
  Stack() {
    top = -1;           // Stack is initially empty
    size = 1000;        // Fixed size stack
    arr = new int[size]; // Allocate memory for stack elements
  }

  // Function to add (push) an element to the top of the stack
  void push(int x) {
    top++;              // Move top pointer to next position
    arr[top] = x;       // Insert element at the top
  }

  // Function to remove (pop) the top element from the stack
  int pop() {
    int x = arr[top];   // Get the top element
    top--;              // Decrease the top pointer
    return x;           // Return the popped element
  }

  // Function to return the top element without removing it
  int Top() {
    return arr[top];
  }

  // Function to get the current size of the stack
  int Size() {
    return top + 1;
  }
};

int main() {
  Stack s;  // Create a Stack object

  // Push elements into the stack
  s.push(6);
  s.push(3);
  s.push(7);

  // Display the top element before deletion
  cout << "Top of stack is before deleting any element: " << s.Top() << endl;

  // Display the size of the stack
  cout << "Size of stack before deleting any element: " << s.Size() << endl;

  // Pop the top element and display it
  cout << "The element deleted is: " << s.pop() << endl;

  // Display the size after popping one element
  cout << "Size of stack after deleting an element: " << s.Size() << endl;

  // Display the new top of the stack
  cout << "Top of stack after deleting an element: " << s.Top() << endl;

  return 0;
}
