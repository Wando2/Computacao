def avalia_arvore(node, mode, alpha, beta):
    """
    Implement the Minimax algorithm with alpha-beta pruning in Python.

    Args:
    node (TreeNode): The current node in the tree.
    mode (str): 'MAX' for maximizing player, 'MIN' for minimizing player.
    alpha (int/float): The alpha value for pruning.
    beta (int/float): The beta value for pruning.

    Returns:
    int/float: The minimax value of the node.
    """

    # Assuming Calcula_valor and get_children functions are defined elsewhere

    # Base case: if the node is a leaf
    if node.is_leaf():
        return calcula_valor(node)

    # Recursive case: traverse the children of the node
    if mode == "MAX":
        value = float("-inf")
        for child in node.get_children():
            value = max(value, avalia_arvore(child, "MIN", alpha, beta))
            if value >= beta:
                return beta  # Pruning
            alpha = max(alpha, value)
    else:  # mode == 'MIN'
        value = float("inf")
        for child in node.get_children():
            value = min(value, avalia_arvore(child, "MAX", alpha, beta))
            if value <= alpha:
                return alpha  # Pruning
            beta = min(beta, value)

    return value


# This function would be called with something like:
# avalia_arvore(root_node, 'MAX', float('-inf'), float('inf'))
