
# Defining a basic structure for a node in the tree
class Node:
    def __init__(self, value=None, children=None):
        self.value = value
        self.children = children if children is not None else []

# Function to calculate the value of a leaf node
def calculate_value(node):
    return node.value

# The main Alpha-Beta pruning function
def alpha_beta(node, depth, alpha, beta, maximizing_player):
    if depth == 0 or not node.children:  # If node is a leaf or depth limit reached
        return calculate_value(node)

    if maximizing_player:
        value = float("-inf")
        for child in node.children:
            value = max(value, alpha_beta(child, depth - 1, alpha, beta, False))
            alpha = max(alpha, value)
            if alpha >= beta:
                break  # Beta prune
        return value
    else:
        value = float("inf")
        for child in node.children:
            value = min(value, alpha_beta(child, depth - 1, alpha, beta, True))
            beta = min(beta, value)
            if beta <= alpha:
                break  # Alpha prune
        return value

# Constructing a more complex tree with one additional depth
root = Node(
    None,
    [
        Node(None, [Node(5), Node(6), Node(7)]),
        Node(None, [Node(3), Node(9), Node(1)]),
        Node(None, [Node(2), Node(4), Node(8)]),
        Node(None, [
            Node(10, [Node(13), Node(14), Node(15)]),  # Additional depth
            Node(11, [Node(16), Node(17), Node(18)]),  # Additional depth
            Node(12, [Node(19), Node(20), Node(21)])   # Additional depth
        ]),
    ],
)  # A tree with root and three children, each child has four more children with one more depth

# Calling the alpha_beta function on the more complex tree
result = alpha_beta(
    root, depth=3, alpha=float("-inf"), beta=float("inf"), maximizing_player=True
)
print(result)