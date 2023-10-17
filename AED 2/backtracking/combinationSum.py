def combinationSum(candidates, target):
    res = []
   
    def dfs(index,subset,total):
        if total == target:
            res.append(subset.copy())
            return
        
        if total > target:
            return
        
        subset.append(candidates[index])
        total += candidates[index]
        dfs(index,subset,total)
        
        subset.pop()
        total -= candidates[index]
        dfs(index+1,subset,total)
    
    
    dfs(0,[],0)
    return res
    
    
        
        
     
        