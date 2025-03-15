

# Complete the findMergeNode function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def findMergeNode(head1, head2):
    a = head1
    b = head2
    while a != b:
        if a.next is None:
            a = head2
        else:
            a = a.next

        if b.next is None:
            b = head1
        else:
            b = b.next
    return a.data
    

