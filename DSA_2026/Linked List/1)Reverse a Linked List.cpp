class Node:
    def __init__(self, newData):
        self.data = newData
        self.next = None

def reverseList(head):

    curr = head
    prev = None

    # traverse all the nodes of Linked List
    while curr is not None:

        # store next
        nextNode = curr.next

        # reverse current node's next pointer
        curr.next = prev

        # move pointers one position ahead
        prev = curr
        curr = nextNode

    return prev


def printList(node):
    while node is not None:
        print(f"{node.data}", end="")
        if node.next is not None:
            print(" -> ", end="")
        node = node.next
    print()


if __name__ == "__main__":

    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)
    head = reverseList(head)
    printList(head)



    class Node:
    def __init__(self, newData):
        self.data = newData
        self.next = None

def reverseList(head):
    if head is None or head.next is None:
        return head

    # reverse the rest of linked list and put the
    # first element at the end
    rest = reverseList(head.next)

    # make the current head as last node of
    # remaining linked list
    head.next.next = head

    # update next of current head to NULL
    head.next = None

    return rest


def printList(node):
    while node is not None:
        print(f"{node.data}", end="")
        if node.next is not None:
            print(" -> ", end="")
        node = node.next
    print()


if __name__ == "__main__":

    # Create a hard-coded linked list:
    # 1 -> 2 -> 3 -> 4 -> 5
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)

    head = reverseList(head)
    printList(head)


    