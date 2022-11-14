# 11659 구간 합 구하기 4
from sys import stdin
input = lambda : stdin.readline()

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
prefix_sum = [0]

tot = 0
for n in numbers:
    tot += n
    prefix_sum.append(tot)

for _ in range(m):
    a, b = map(int, input().split())
    print(prefix_sum[b] - prefix_sum[a - 1])