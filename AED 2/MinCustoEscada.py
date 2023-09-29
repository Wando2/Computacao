class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost) - 1

        for i in range(2, len(cost)):
            cost[i] += min(cost[i - 1], cost[i - 2])

        return min(cost[n], cost[n - 1])


