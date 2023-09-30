#k = 2

def minPath(n1,n2,cost):
    if min(cost[n1],cost[n2]) == cost[n1]:
        return n1
    else: return n2

def minCostClimbingStairs(cost):
   n = len(cost) - 1 #because we start from 0 // n represents the index of last element
   from_step = [0] * len(cost) # for every element, we will store the index of the element that led to him
   

   for i in range(2, len(cost)):
       cost[i] += min(cost[i - 1], cost[i - 2])
       from_step[i] = minPath(i-1,i-2,cost)    

   n = minPath(n,n-1,cost) # the index of last element that led to the best route
   path = []
   
   while n > 0:
       path.append(n) # we apeend the indice of last, and then change n to the value that led to this element. 
       n = from_step[n]
   
   return path[::-1] #reversing because we began from end

   


p1 = [1, 2, 3, 4, 5]
resultadop1 = minCostClimbingStairs(p1)
print(resultadop1)  

