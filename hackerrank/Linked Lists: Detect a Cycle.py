"""
Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as: 
 
    class Node(object):
        def __init__(self, data = None, next_node = None):
            self.data = data
            self.next = next_node
"""


def has_cycle(head):
    c = head
    marks = []
    while c:
        if hash(c) in marks:
            return True
        else:
            marks.append(hash(c))
            c = c.next
    return False