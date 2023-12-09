def knapsack_greedy(capacity, weights, values):
    # Calculate value/weight ratio for each item
    ratios = [v/w for v, w in zip(values, weights)]
    
    # Sort items by decreasing value/weight ratio
    sorted_items = sorted(range(len(ratios)), key=ratios.__getitem__, reverse=True)
    
    total_value = 0
    for i in sorted_items:
        if weights[i] <= capacity:
            # If item can fit in the knapsack, add it
            total_value += values[i]
            capacity -= weights[i]
        else:
            # If item can't fit, break
            break
    
    return total_value