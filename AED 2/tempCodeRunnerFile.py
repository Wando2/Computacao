class Solution:
    def climbStairs(self, n: int,k: int) -> int:
        dp = [0] * n
        dp[0] = 1
        dp[1] = 1
        
        for i in range(2,n):
            for j in range(1,k):
                if(i-j>=0):
                    dp[i] += dp[i-j]
        return dp[n-1]            
    
#test cases
print(Solution().climbStairs(3,3))
#expected result: 3
print(Solution().climbStairs(4,3))
#expected result: 7
print(Solution().climbStairs(5,3))
#expected result: 13