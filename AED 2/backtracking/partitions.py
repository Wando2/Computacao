import math

def FindFourSquares(n):
    res = []
    
    def backtracking(index,subset,total):
        if total == n:
            if len(subset) == 4:
                res.append(subset[:])
            return
        
        if total > n or len(subset) == 4:
            return
        
        for i in range(index,math.ceil(math.sqrt(n))+1):
            subset.append(i)
            total += i*i
            backtracking(i,subset,total)
            subset.pop()
            total -= i*i
    
    backtracking(0,[],0)
    return res
            
            
print(FindFourSquares(16))         