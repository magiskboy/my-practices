

# Complete the has_cycle function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def has_cycle(head):
    visited = set() 
    curr = head
    
    while curr:
        if id(curr) in visited:
            return True 
        visited.add(id(curr))
        curr = curr.next

    return False 
    
