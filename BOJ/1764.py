# 1764 듣보잡
from sys import stdin
#input = stdin.readline
n, m = map(int, input().split())
a_set = set()
b_set = set()

for _ in range(n):
    a_set.add(input())

for _ in range(m):
    b_set.add(input())

answer = sorted(list(a_set & b_set))

print(len(answer))
for a in answer:
    print(a)