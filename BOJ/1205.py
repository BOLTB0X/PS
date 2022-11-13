# 1205 등수 구하기
from sys import stdin
input = lambda : stdin.readline().rstrip()

n, taeso, p = map(int, input().split())
answer = 0
if n:
    score = list(map(int,input().split()))
    score.append(taeso)
    
    score.sort(reverse = True)
    answer = score.index(taeso) + 1
    
    if answer > p:
        answer = -1
    
    else:
        if n == p and taeso == score[-1]:
            answer = -1
else:
    answer = 1

print(answer)