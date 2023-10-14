def Subsets(nums):
    res = []
    subset = []
    
    def dfs(index):
        if index >= len(nums):
            res.append(subset.copy())
            return

        subset.append(nums[index])
        dfs(index + 1)
        
        subset.pop()
        dfs(index + 1)
    dfs(0)
    return res


test = Subsets([1,2,3])
print(test)