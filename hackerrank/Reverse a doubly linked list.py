

# Complete the reverse function below.

#
# For your reference:
#
# DoublyLinkedListNode:
#     int data
#     DoublyLinkedListNode next
#     DoublyLinkedListNode prev
#
#
def reverse(head):
    c = head
    while c:
        tmp = c.next
        c.next = c.prev
        if tmp is None:
            return c
        else:
            c = tmp
    return 

