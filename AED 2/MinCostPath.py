
def minCostPath(m,n,grid):
    from_step = [[0 for n in range(n)] for m in range(m)]
    from_step[0][0] = 0
    
    for i in range(0,m):
        for j in range(0,n):
            if i == 0:
                if j > 0:
                    grid[i][j] += grid[i][j-1]
                    from_step[i][j] = str(i) + ',' + str(j-1)
            elif j == 0:
                if i > 0:
                    grid[i][j] += grid[i-1][j]
                    from_step[i][j] = str(i-1) + ',' + str(j-1)
            else:
                grid[i][j] += min(grid[i-1][j],grid[i][j-1])
                if grid[i-1][j] < grid[i][j-1]:
                    from_step[i][j] = str(i-1) + ',' + str(j)
                else:
                    from_step[i][j] = str(i) + ',' + str(j-1)
    
    n = str(m-1) + ',' + str(n-1)
    path = []
    
    while n != '0,0':
        path.append(n)
        n = from_step[int(n[0])][int(n[2])] 
    path.append('0,0')    
        
    return path[::-1]   

grid = [[1,3,1],[1,5,1],[4,2,1]]
print(minCostPath(3,3,grid))
#expected output: ['0,0', '0,1', '0,2', '1,2', '2,2']