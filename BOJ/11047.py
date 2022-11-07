# 11047 동전 0
n, k = map(int,input().split())
coins = [int(input()) for _ in range(n)]
answer = 0

for i in range(n - 1, -1, -1):
    coin = coins[i]
    
    if coin > k:
        continue
    
    answer += k // coin
    k  %= coin

print(answer)