
def trocoMoedas(arr,troco):
    dp = [0] * (troco+1)
    dp[0] = 1
    
    for i in range(1,troco+1):
        
        if i >= 1:
            dp[i] += dp[i - 1]
        
        if i >= 2:
            dp[i] += dp[i-2]
            
        if i >= 5:
            dp[i] += dp[i-5]
        
        if i >= 6:
            dp[i] += dp[i-6]
                    
         
        if i >= 10:
            dp[i] += dp[i-10]
            
   
    return dp[troco]


print(trocoMoedas([1,2,5,6,10],7))
#expected result 
print(trocoMoedas([1,3,5,10],3))