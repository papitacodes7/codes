#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = this;   // makes single node circular
    }
};

class Solution {
public:
    Node* deleteNode(Node* head, int key) {

        // Case 1: empty list
        if (head == NULL)
            return NULL;

        Node* curr = head;
        Node* prev = NULL;

        // Case 2: deleting head
        if (curr->data == key) {

            // only one node
            if (head->next == head) {
                delete head;
                return NULL;
            }

            // more than one node
            while (curr->next != head)
                curr = curr->next;

            curr->next = head->next;
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        // Case 3: deleting non-head node
        while (curr->next != head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
        }

        return head;
    }
};

// Insert at end
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node* curr = head;
    while (curr->next != head)
        curr = curr->next;

    curr->next = newNode;
    newNode->next = head;

    return head;
}

// Print circular list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);

    cout << endl;
}

int main() {

    Node* head = NULL;
    Solution obj;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    cout << "Original list: ";
    printList(head);

    head = obj.deleteNode(head, 10);
    cout << "After deleting 10: ";
    printList(head);

    head = obj.deleteNode(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    head = obj.deleteNode(head, 30);
    cout << "After deleting 30: ";
    printList(head);

    return 0;
}

// basically now the thing is agar single head hi given he and usse hi delete krna he toh krdenge.. head == null..
// now sirf ek node he means head == key and head->next == head toh delte head.. 
// now bohot se hein par the thing is head ko delte krna he.. so curr lejyga head->next == head tk.. and curr->next == head->next krdenge.. and newHead return krwa denge..
// now if head nhi delte krna koi or krna he.. toh like.. just jaha key mil jaaye uske bich ka node skip krdena he and loop ko toh change krne ki zarurat nhi he..

//Agar circular linked list me sirf ek hi node ho aur wahi delete karna ho, toh seedha us node ko delete karke NULL return kar dete hain, kyunki delete ke baad list empty ho jaati hai. Agar multiple nodes hain aur head ko delete karna hai, toh pehle last node tak traverse karte hain (jiska next head ko point karta hai), phir us last node ke next ko head->next se jod dete hain, taaki circle bana rahe; uske baad purana head delete karke head->next ko naya head return kar dete hain. Aur agar head ko delete nahi karna balki koi beech ka node delete karna ho, toh list me traverse karke jahan key milta hai wahan us node ko skip kar dete hain, matlab prev->next ko curr->next se jod dete hain aur us node ki memory delete kar dete hain. Is poore process ka main rule ye hai ki circular linked list me delete ka matlab circle todna nahi hota, balki pointers ko sahi tarah rewire karke node ko unreachable banana hota hai.