

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def postOrder(root):
    if root:
        postOrder(root.left)
        postOrder(root.right)
        print(root.info, end=' ')

