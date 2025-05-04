#include<bits/stdc++.h> 
using namespace std;

// Definition of a QueueNode class
class QueueNode
{
 public: 
    int val;  // Value of the node
    QueueNode *next;  // Pointer to the next node
    QueueNode(int data)
    {
       val = data;
       next = nullptr;
    }
};  

// Pointers for Front and Rare of the queue
QueueNode *Front = nullptr, *Rare = nullptr;

// Definition of the Queue class
class Queue
{
public:
    int size = 0;  // Tracks the size of the queue
    bool Empty();  // Checks if the queue is empty
    void Enqueue(int value);  // Adds an element to the queue
    void Dequeue();  // Removes an element from the queue
    int Peek();  // Returns the front element of the queue
};

// Checks if the queue is empty
bool Queue::Empty()
{
    return Front == nullptr;  // If Front is nullptr, queue is empty
}

// Returns the front element of the queue
int Queue::Peek()
{
    if (Empty())  
    {  
        cout << "Queue is Empty" << endl;  // If empty, print message
        return -1;  // Return -1 if queue is empty
    } 
    else 
        return Front->val;  // Return the value of the front node
}   

// Adds an element to the queue
void Queue::Enqueue(int value)
{
    QueueNode *Temp;
    Temp = new QueueNode(value);  // Create a new node with the given value
    
    // Check if heap memory is available
    if (Temp == nullptr)  
        cout << "Queue is Full" << endl;
    else
    {
        if (Front == nullptr)  // If the queue is empty
        {
            Front = Temp;  // Set both Front and Rare to the new node
            Rare = Temp;
        } 
        else
        {
            Rare->next = Temp;  // Set the next pointer of the current Rare to the new node
            Rare = Temp;  // Update Rare to the new node
        }
        cout << value << " Inserted into Queue " << endl;  // Print inserted value
        size++;  // Increment the size of the queue
    } 
}      

// Removes an element from the front of the queue
void Queue::Dequeue() 
{
    if (Front == nullptr) 
        cout << "Queue is Empty" << endl;  // If the queue is empty
    else
    { 
        cout << Front->val << " Removed From Queue" << endl;  // Print the value being removed
        QueueNode *Temp = Front;  // Temporary pointer to hold the front node
        Front = Front->next;  // Move the Front pointer to the next node
        delete Temp;  // Free the memory of the old front node
        size--;  // Decrement the size of the queue
    }  
}   

int main()
{
    Queue Q;
    Q.Enqueue(10);  // Add 10 to the queue
    Q.Enqueue(20);  // Add 20 to the queue
    Q.Enqueue(30);  // Add 30 to the queue
    Q.Enqueue(40);  // Add 40 to the queue
    Q.Enqueue(50);  // Add 50 to the queue
    Q.Dequeue();  // Remove an element from the front
    cout << "The size of the Queue is " << Q.size << endl;  // Print the size of the queue
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;  // Print the front element
    return 0;
}


// Push an element to the Queue
// void Queue::push(int x) {
//     // Create a new node with the value x
//     Node* temp = new Node(x);
    
//     // If the queue is empty, set both front and rear to the new node
//     if (front == NULL) {
//         front = rear = temp;
//     } else {
//         // Otherwise, add the node at the end and update the rear pointer
//         rear->next = temp;
//         rear = temp;
//     }
// }

// // Pop the front element from the Queue
// int Queue::pop() {
//     // If the queue is empty, return -1
//     if (front == NULL) {
//         return -1;
//     }
    
//     // Store the front element to return
//     int result = front->data;
    
//     // Move the front pointer to the next element in the queue
//     Node* temp = front;
//     front = front->next;
    
//     // Delete the old front node to free memory
//     delete temp;
    
//     // If the queue is empty after popping, reset rear to NULL
//     if (front == NULL) rear = NULL;
    
//     // Return the value of the popped element
//     return result;
// }
