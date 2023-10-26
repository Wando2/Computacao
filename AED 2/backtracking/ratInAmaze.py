class Solution:
    def findPath(self, m, n):
        res = []
        
        def isvalid(x,y):
            if m[x][y] != 0 and m[x][y] != -1:
                return False
                
            else:
                return True    
        
        def findPathAux(subset,x,y):
            if x == n-1 and y == n-1:
                res.append(subset[:])
                return
            if x >= n or y >= n:
                return
            
            if isvalid(x+1,y):
                subset.append('D')
                m[x][y] = -1
                findPathAux(subset,x+1,y)
                #backtrack
                subset.pop()
                m[x][y] = 1
                
            if isvalid(x,y+1):
                subset.append('R')
                m[x][y] = -1
                findPathAux(subset,x,y+1)
                #backtrack
                subset.pop()
                m[x][y] = 1
                
            if isvalid(x-1,y):
                subset.append('U')
                m[x][y] = -1
                findPathAux(subset,x-1,y)
                #backtrack
                subset.pop()
                m[x][y] = 1
                
            if isvalid(x,y-1):
                subset.append('L')
                m[x][y] = -1
                findPathAux(subset,x,y-1)
                #backtrack
                subset.pop()
                m[x][y] = 1                
        findPathAux([],0,0)
        return res
            
            