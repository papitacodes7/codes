#include <bits/stdc++.h>

using namespace std;

class MyQueue {
  public:
    stack < int > input, output;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    cout << "The element pushed is " << x << endl;
    input.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();

    int x = output.top();
    output.pop();
    return x;
  }

  /** Get the front element. */
  int top() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }

  int size() {
    return (output.size() + input.size()); 
  }

};
int main() {
  MyQueue q;
  q.push(3);
  q.push(4);
  cout << "The element poped is " << q.pop() << endl;
  q.push(5);
  cout << "The top of the queue is " << q.top() << endl;
  cout << "The size of the queue is " << q.size() << endl;

}
Output:

The element pushed is 3

The element pushed is 4

The element poped is 3

The element pushed is 5

The top of the queue is 4

The size of the queue is 2

Time Complexity: O(1 )

Space Complexity: O(2N)


/*class MyQueue {
    private:
    stack <int> input, output;  // Declare two stacks, input and output

public:
    // Constructor for MyQueue class. Initializes the input and output stacks.
    MyQueue() {
    }
    
    // Function to push an element into the queue.
    void push(int x) {
        input.push(x);  // Add the element x to the input stack
    }
    
    // Function to pop an element from the front of the queue.
    int pop() {
        // If the output stack is empty, transfer all elements from input stack to output stack.
        if(output.empty()){
            // Move all elements from the input stack to the output stack, reversing their order.
            while(!input.empty()){
                output.push(input.top());  // Push the top element of input stack to output stack
                input.pop();  // Remove the top element from input stack
            }
        }
        // At this point, output stack has the oldest elements on top.
        int front = output.top();  // Get the top element of output stack (front of the queue)
        output.pop();  // Remove the front element from the output stack (it’s now popped)
        return front;  // Return the popped element
    }
    
    // Function to peek at the front element of the queue without removing it.
    int peek() {
        // If the output stack is empty, transfer all elements from input stack to output stack.
        if(output.empty()){
            // Move all elements from the input stack to the output stack, reversing their order.
            while(!input.empty()){
                output.push(input.top());  // Push the top element of input stack to output stack
                input.pop();  // Remove the top element from input stack
            }
        }
        // The top element of the output stack is the front of the queue, so we return it.
        return output.top();  // Return the element at the front of the queue
    }
    
    // Function to check if the queue is empty.
    bool empty() {
        // A queue is empty if both the input and output stacks are empty.
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();     // Create a new MyQueue object
 * obj->push(x);                    // Push element x into the queue
 * int param_2 = obj->pop();         // Pop the front element from the queue
 * int param_3 = obj->peek();        // Peek at the front element of the queue
 * bool param_4 = obj->empty();      // Check if the queue is empty
 */
*/
