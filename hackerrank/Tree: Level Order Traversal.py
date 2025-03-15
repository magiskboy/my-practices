

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""

def levelOrder(root):
    from queue import Queue
    q = Queue()
    
    q.put(root)
    while not q.empty():
        item = q.get()
        print(item.info, end=' ')
        if item.left:
            q.put(item.left)
        if item.right:
            q.put(item.right)
    

