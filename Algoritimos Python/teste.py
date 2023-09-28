""" print("hello world") # Imprime na tela a mensagem "hello world"
count = 0
while (count < 3):
    count = count +1
    print("count")

for i in range(0,3):
    print("i") """

print("List Iteration")
l = ["geeks", "for", "geeks"]
for i in l:
    print(i)
 
print("\nDictionary Iteration")
d = dict()
d['xyz'] = 123
d['abc'] = 345
for i in d:
    print("%s  %d" % (i, d[i]))
    
for i in range(1, 5):
    for j in range(i):
        print(i, end=' ') 
        
for letter in 'vasco':
    if letter != 'a':
        print(letter)
    
    
n = 4
lst = list(map(int,input("enter numbers").strip().split()))[:n]
print(lst)       