# 7576 토마토
from sys import stdin
from collections import deque 
input = lambda : stdin.readline().rstrip()

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(m)]
dq = deque()
answer = -1

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def BFS():
    global answer
    while dq:
        y, x = dq.popleft()
        
        for dir in range(4):
            ny = y + dy[dir]
            nx = x + dx[dir]
            
            if ny < 0 or nx < 0 or ny >= m or nx >= n:
                continue
            
            if board[ny][nx] == -1 or board[ny][nx] > 0:
                continue
            
            board[ny][nx] = board[y][x] + 1
            dq.append([ny, nx])
        
for i in range(m):
    for j in range(n):
        if board[i][j] == 1:
            dq.append([i,j])

BFS()

for boa in board:
    for b in boa:
        if b == 0:
            print(-1)
            exit()
    answer = max(answer, max(boa))
    
print(answer - 1)