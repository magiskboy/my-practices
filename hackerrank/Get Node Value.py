

# Complete the getNode function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def getNode(head, pos):
    s = 1
    curr = head
    while curr.next:
        s += 1
        curr = curr.next

    s = s - pos - 1
    curr = head
    while s:
        curr = curr.next
        s -= 1

    return curr.data

