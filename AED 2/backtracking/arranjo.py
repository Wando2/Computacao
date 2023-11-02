def arranjo(arr,k):
    res = []
    
    def backtracking(index,subset):
        if index >= k:
            res.append(subset[:])
            return
        for i in range(len(arr)):
            subset.append(arr[i])
            backtracking(index+1,subset)
            subset.pop()
            
    backtracking(0,[])
    return res

def permutacaoCircular(arr):
    res = []
    
    def backtracking(subset):
        if len(subset) == len(arr):
            res.append(subset[:])
            return
        
        for i in range(len(arr)):
            if arr[i] in subset:
                continue
            subset.append(arr[i])
            backtracking(subset)
            subset.pop()
 

                  
    backtracking([])
    return res           

def combinacao(arr):
    res = []
    
    def backtracking(index,subset,indexInicial):
        if index >= len(arr):
            res.append(subset[:])
            return
        
        for i in range(indexInicial,len(arr)):
            subset.append(arr[i])
            backtracking(index+1,subset,i+1)
            subset.pop()
            
    backtracking(0,[],0)
    return res        

arr = [1,2,3]
print(combinacao(arr))


