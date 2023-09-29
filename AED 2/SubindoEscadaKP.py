class Solution:
    def climbStairs(self, n: int,k: int) -> int:
        dp = [0] * k
        dp[0] = 1
        
        for i in range(1,(n+1)):
            for j in range(1,k):
                if(i-j>=0):
                    dp[i % k] += dp[(i-j) % k]
        return dp[n % k]            
    
#test cases
print(Solution().climbStairs(3,3))

print(Solution().climbStairs(4,3))

print(Solution().climbStairs(5,3))






