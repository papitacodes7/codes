#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// Class to implement a Stack using a single queue
class Stack {
    queue<int> q; // Internal queue used to simulate stack behavior

public:
    // Pushes an element onto the stack
    void Push(int x) {
        int s = q.size(); // Store current size of the queue

        q.push(x); // Insert new element at the end of the queue

        // Rotate the queue to bring the new element to the front
        // This step ensures the most recently pushed element behaves as the stack's "top"
        for (int i = 0; i < s; i++) {
            q.push(q.front()); // Move front element to the back
            q.pop();           // Remove the original front
        }
    }

    // Removes and returns the top element of the stack
    int Pop() {
        int n = q.front(); // Get the element at the front (which acts as the top)
        q.pop();           // Remove it from the queue
        return n;          // Return it
    }

    // Returns the top element without removing it
    int Top() {
        return q.front(); // Front of the queue is treated as the top of the stack
    }

    // Returns the number of elements in the stack
    int Size() {
        return q.size(); // Simply return the size of the internal queue
    }
};

int main() {
    Stack s;

    // Push elements onto the stack
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);

    // Output the current top of the stack
    cout << "Top of the stack: " << s.Top() << endl;

    // Output size before popping
    cout << "Size of the stack before removing element: " << s.Size() << endl;

    // Pop the top element and show what was removed
    cout << "The deleted element is: " << s.Pop() << endl;

    // Show new top after pop
    cout << "Top of the stack after removing element: " << s.Top() << endl;

    // Show new size after pop
    cout << "Size of the stack after removing element: " << s.Size();

    return 0;
}

/*#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;  // Single queue used to simulate stack behavior

public:
    // Constructor initializes the queue (implicitly empty)
    MyStack() {
    }

    // Push operation for stack
    void push(int x) {
        // Step 1: Push the new element to the back of the queue
        // element daalo q me
        q.push(x);
        
        // Step 2: Rotate the queue to bring the new element to the front
        // This ensures LIFO order is maintained
        int n = q.size();
        for (int i = 1; i < n; i++) {
            // Move the front element to the back
            q.push(q.front());
            q.pop();
        }
    }

    // Pop operation for stack
    int pop() {
        // Step 1: Retrieve the front element (top of the stack)
        int val = q.front();
        
        // Step 2: Remove it from the queue
        q.pop();
        
        // Step 3: Return the popped value
        return val;
    }

    // Top operation to get the top element of the stack
    int top() {
        // Simply return the front of the queue (top of the stack)
        return q.front();
    }

    // Check if the stack is empty
    bool empty() {
        // Queue is empty => Stack is also empty
        return q.empty();
    }
};*/
