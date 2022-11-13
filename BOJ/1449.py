# 1449 수리공 항승
from sys import stdin 
input = lambda : stdin.readline()

n, l = map(int, input().split())
pipe = list(map(int, input().split()))

pipe.sort() # 오름차순 정렬
cmp = pipe[0] # 기준
answer = 1

for cur in pipe[1:]:
    # 현재 테이프로 붙일 수 있는 경우
    if l <= cur - cmp:
        answer += 1
        cmp = cur

print(answer)