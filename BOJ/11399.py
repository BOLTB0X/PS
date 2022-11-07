# 11399 ATM
n = int(input())
l = list(map(int, input().split()))

l.sort()
dp = [0] * n

dp[0] = l[0]
answer = l[0]
for i in range(1, n):
    dp[i] = dp[i - 1] + l[i]
    answer += dp[i]

print(answer)