

# Complete the mergeLists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def mergeLists(head1, head2):
    head, tail = None, None
    curr1, curr2 = head1, head2
    while curr1 and curr2:
        if curr1.data < curr2.data:
            choice = curr1
            curr1 = curr1.next
        else:
            choice = curr2
            curr2 = curr2.next
        
        if not head:
            tail = SinglyLinkedListNode(choice.data)
            head = tail
        else:
            tail.next = SinglyLinkedListNode(choice.data)
            tail = tail.next

    while curr1:
        tail.next = SinglyLinkedListNode(curr1.data)
        tail = tail.next
        curr1 = curr1.next
    while curr2:
        tail.next = SinglyLinkedListNode(curr2.data)
        tail = tail.next
        curr2 = curr2.next

    return head        

