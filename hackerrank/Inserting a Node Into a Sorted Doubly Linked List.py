

# Complete the sortedInsert function below.

#
# For your reference:
#
# DoublyLinkedListNode:
#     int data
#     DoublyLinkedListNode next
#     DoublyLinkedListNode prev
#
#
def sortedInsert(head, data):
    curr = head
    prev = None
    new_node = DoublyLinkedListNode(data)

    while curr and curr.data < data:
        prev = curr
        curr = curr.next

    if not prev:    # insert to head
        new_node.next = head
        head.prev = new_node
        return new_node

    if not curr:    # insert to tail
        prev.next = new_node
        new_node.prev = prev
        return head

    new_node.next = curr
    curr.prev = new_node
    prev.next = new_node
    new_node.prev = prev
    
    return head 

