def knapsack_greedy(capacity, weights, values):
    # Calculate value/weight ratio for each item
    ratios = [v / w for v, w in zip(values, weights)]

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


def knapsack_backtracking(capacity, weights, values, n):
    # Base Case
    if n == 0 or capacity == 0:
        return 0

    # If weight of the nth item is more than Knapsack capacity,
    # then this item cannot be included in the optimal solution
    if weights[n - 1] > capacity:
        return knapsack_backtracking(capacity, weights, values, n - 1)

    # Return the maximum of two cases:
    # (1) nth item included
    # (2) not included
    else:
        return max(
            values[n - 1]
            + knapsack_backtracking(capacity - weights[n - 1], weights, values, n - 1),
            knapsack_backtracking(capacity, weights, values, n - 1),
        )


weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
n = len(values)


weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
n = len(values)

