def trocomin(n):
    # Assuming V is a list of Brazilian coin values
    V = [1, 0.5, 0.25, 0.1, 0.05, 0.01]  # Example values for Brazilian coins

    tot = 0
    t = len(V) - 1

    for i in range(t, 0, -1):
        x = int(n / V[i])
        tot += x
        n -= x * V[i]

    return tot


# Example usage:
amount_to_convert = 10.75  # Example amount in Brazilian currency
result = trocomin(amount_to_convert)
print(f"Minimum number of coins needed: {result}")
