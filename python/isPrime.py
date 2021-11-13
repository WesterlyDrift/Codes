import math

def isprime(x):
    if x<2:
        return "F"
    for i in range(2,int(math.sqrt(x))+1):
        if x%i == 0:
            return "F"
    
    return "T"

x = int(input())
print(isprime(x))
