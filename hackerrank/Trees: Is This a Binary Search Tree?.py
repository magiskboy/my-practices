""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

def isBST(root, _min, _max):
    if not root:
        return True
    if root.data < _min or root.data > _max:
        return False
    return isBST(root.left, _min, root.data-1) and isBST(root.right, root.data+1, _max)

def checkBST(root):
    if not (root.left or root.right):
        return True
    else:
        return isBST(root, -9e9, 9e9)