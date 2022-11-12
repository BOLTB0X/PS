# 11279 최대 힙
from sys import stdin
import heapq

input = stdin.readline

n = int(input())
heap = []
for _ in range(n):
    a = int(input())
    if a == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heapq.heappop(heap)[1])
    else:
        heapq.heappush(heap, (-a, a))