def minDistancia(palavra1, palavra2):
    dp = [[0 for _ in range(len(palavra2) + 1)] for _ in range(len(palavra1) + 1)]
    for i in range(len(palavra1) + 1):
        dp[i][0] = i
        for j in range(1, len(palavra2) + 1):
            if i == 0:
                dp[0][j] = j
            elif palavra1[i - 1] == palavra2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
    return dp[-1][-1]


print(minDistancia("erro", "acerto"))
print(minDistancia("casa", "cafe"))
