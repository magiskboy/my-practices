

# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
class Node:
      def __init__(self,info): 
          self.info = info  
          self.left = None  
          self.right = None 
           

       // this is a node of the tree , which contains info as data, left , right
'''
def height(root):
    if root.left and root.right:
        return 1 + max(height(root.left), height(root.right))
    else:
        if root.left:
            return 1 + height(root.left)
        elif root.right:
            return 1 + height(root.right)
        else:
            return 0

