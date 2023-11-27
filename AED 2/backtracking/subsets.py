def Subsets(nums):
    res = []
    subset = []
    
    def dfs(index):
        if index >= len(nums):
            res.append(subset[:])
            return

        subset.append(nums[index])
        dfs(index + 1)
        
        subset.pop()
        dfs(index + 1)
    dfs(0)
    return res


test = Subsets([1,2,3])
print(test)


def SubsetsAlt(nums):
    res = []
    subset = []
    
    def dfs(index):
        res.append(subset[:])
        
        for i in range(index,len(nums)):
            subset.append(nums[i])
            dfs(i+1)
            subset.pop()
    dfs(0)
    return res

test2 = SubsetsAlt([1,2,3])
print(test2)