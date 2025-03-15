

#Node is defined as
#self.left (the left child of the node)
#self.right (the right child of the node)
#self.info (the value of the node)

    def insert(self, val):
        root = self.root
        new_node = Node(val)
        if not root:
            self.root = new_node
        else:
            while 1:
                if root.info > val:
                    if root.left:
                        root = root.left
                    else:
                        root.left = new_node
                        break
                else:
                    if root.right:
                        root = root.right
                    else:
                        root.right = new_node
                        break
        return root
                    

