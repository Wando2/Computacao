def paid_staircase(n, p):
    dp = [0] * (n + 1)
    from_step = [0] * (n + 1)
    dp[0] = 0
    dp[1] = p[1]
    
    for i in range(2, n + 1):
        dp[i] = min(dp[i - 1], dp[i - 2]) + p[i]
        if dp[i - 1] < dp[i - 2]:
            from_step[i] = i - 1
        else:
            from_step[i] = i - 2
    
    path = []
    curr = n
    while curr > 0:
        path.append(curr)
        curr = from_step[curr]
    
    path.append(0)
    
    return path[::-1]

# Test case 1: Basic test case
n1 = 5
p1 = [0, 1, 2, 3, 4, 5]
result1 = paid_staircase(n1, p1)
# The cheapest path should be [0, 1, 3, 5]
print(result1)  # Output: [0, 1, 3, 5]

# Test case 2: Edge case with only one step
n2 = 1
p2 = [0, 1]
result2 = paid_staircase(n2, p2)
# The cheapest path should be [0, 1]
print(result2)  # Output: [0, 1]

# Test case 3: Another set of values
n3 = 6
p3 = [0, 2, 3, 4, 5, 6, 7]
result3 = paid_staircase(n3, p3)
# The cheapest path should be [0, 2, 4, 6]
print(result3)  # Output: [0, 2, 4, 6]