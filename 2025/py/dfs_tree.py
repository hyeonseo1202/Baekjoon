class Node:
    def __init__(self, value = 0, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

class BinaryTree:
    def __init__(self):
        self.root = None
        
bt = BinaryTree()
bt.root = Node(value = 1)
bt.root.left = Node(value = 2)
bt.root.left.left = Node(value = 3)

def dfs(cur_node):
    if cur_node == None:
        return
    
    print(cur_node.value)
    dfs(cur_node.left)
    dfs(cur_node.right)
    
dfs(bt.root)