

"""class Node:
    def __init__(self, freq,data):
        self.freq= freq
        self.data=data
        self.left = None
        self.right = None
"""        

# Enter your code here. Read input from STDIN. Print output to STDOUT
def decodeHuff(root, s):
    rv = ""
    cnode = root
    for bit in s:
        cnode = cnode.left if bit == "0" else cnode.right
        if not cnode.left and not cnode.right:
            rv += cnode.data
            cnode = root
    print(rv)

