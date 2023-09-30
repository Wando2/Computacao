def UniquePath(m,n):
    arr = [[0 for n in range(n)] for m in range(m)]
    arr[0][0] = 1
    
    for k in range(0,m):
        for l in range(0,n):
            if k == 0 or l == 0:
                arr[k][l] = 1
            else:
                arr[k][l] = arr[k-1][l] + arr[k][l-1]
   
    return arr[m-1][n-1] 
    
#create a array multidiemensional with 0's of size 3,3


test = UniquePath(3,3)
print(test)
# expected output: 6
    