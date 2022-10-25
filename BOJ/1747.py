# 1747 소수&팰린드롬
import math

def is_Pal(number):
    str_n = str(number)
    l = len(str_n)
    
    for i in range(0, l):
        if str_n[i] != str_n[l - 1 - i]:
            return False
    return True

def is_prime(number):
    if number == 0 or number == 1:
        return False
    
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    
    return True
        
n = int(input())

for i in range(n, 1500001):
    if is_Pal(i) and is_prime(i):
        print(i);
        break;