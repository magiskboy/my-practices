""" Node is defined as
class node:
  def __init__(self, data):
      self.data = data
      self.left = None
      self.right = None
"""
v = []
def check_binary_search_tree_(root):
    if root:
        left, right = root.left, root.right

        if left and left.data >= root.data:
            return False
        if (not check_binary_search_tree_(left)):
            return False
        v.append(root.data)
        if right and right.data <= root.data:
            return False
        if (not check_binary_search_tree_(right)):
            return False
        
        for i in range(len(v)-1):
            if v[i] >= v[i+1]:
                return False
        
        return True
    return True