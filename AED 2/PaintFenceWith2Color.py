
def paintFence(n):
    dp = [[0 for j in range(2)] for i in range(n+1)] #create a 2d array of size n and j options
     
     #this problem have two base cases, when the fences end with 0 (green) and 1 (red)
     #so we have to calculate the number of ways in both cases,and sum them up.
    
    dp[1][0] = 1 # when we have 1 fence ending with 0 (green), we have 1 option.
    dp[1][1] = 1 # the same, but now ending with 1 (red)
    dp[2][0] = 2 # when we have 2 fences ending with 0 (green), we have 2 options 00, 10.
    dp[2][1] = 2 # the same, but now ending with 1 (red) 01, 11.
    
    for i in range(3,n+1):
        for j in range(2):
                dp[i][j] = dp[i-1][1-j] + dp[i-2][1-j]
    
    return dp[n][0] + dp[n][1]



print(paintFence(3))          