

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def topView(root):
    #Write your code here

    m = dict()
    root.hd = 0
    q = [root]
    while q:
        root = q[0]
        
        hd = root.hd
        
        if hd not in m:
            m[hd] = root.info
            
        if root.left:
            root.left.hd = hd - 1
            q.append(root.left)
            
        if root.right:
            root.right.hd = hd + 1
            q.append(root.right)
        
        q.pop(0)
        
    for k in sorted(m):
        print(m[k], end=' ')
