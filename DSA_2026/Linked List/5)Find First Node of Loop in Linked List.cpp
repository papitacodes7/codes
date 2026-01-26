#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

int cycleStart(Node* head) {
  
    // Initialize two pointers, slow and fast
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
      
      	// Move slow pointer by one step
        slow = slow->next;          
      
      	// Move fast pointer by two steps
        fast = fast->next->next;    

        // Detect loop
        if (slow == fast) {
          
            // Move slow to head, keep fast at meeting point
            slow = head;
            
            // Move both one step at a time until they meet
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            // Return the meeting node, which
          	// is the start of the loop
            return slow->data;
        }
    }
    
    // No loop found
    return -1;
}

int main() {
  
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    

    head->next->next->next->next->next = head->next->next;

    int loopNode = cycleStart(head);

    if (loopNode != -1)
        cout << loopNode;
    else
        cout << -1;

    return 0;
}

//Hum Floyd’s Cycle Detection (slow–fast pointers) ka use karte hain. slow pointer har step me 1 node aage badhta hai aur fast pointer 2 nodes. Agar linked list me loop hoga, toh dono pointers kisi point par mil jaayenge, jo confirm karta hai ki cycle exist karti hai. Loop detect hone ke baad, slow pointer ko wapas head par le jaate hain aur fast ko wahi meeting point par chhod dete hain. Ab jab dono pointers ko ek-ek step chalaya jaata hai, toh jis node par woh dobara milte hain, wahi cycle ka starting node hota hai. Agar traversal ke dauraan fast ya fast->next NULL ho jaaye, toh iska matlab list me koi loop nahi hai, aur hum -1 return kar dete hain.