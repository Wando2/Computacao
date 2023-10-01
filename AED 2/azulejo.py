def pintarAzulejo(n):
    n1,n2 = 2,1
    for i in range(2,n):
        n1,n2 = n1+n2,n1
    return n1


#test case
print(pintarAzulejo(3))
#expected output: 3