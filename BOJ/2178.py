# 2178 미로탐색
from sys import stdin
from collections import deque
input = lambda : stdin.readline().rstrip()

n, m = map(int, input().split())
board = [list(map(int, input())) for _ in range(n)]
dist = [[0] * m for _ in range(n)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def BFS(y, x):
    que = deque()
    dist[y][x] = 1
    que.append([y, x])

    while que:
        cy,cx = que.popleft()
        
        for dir in range(4):
            ny = cy + dy[dir]
            nx = cx + dx[dir]

            if ny < 0 or nx < 0 or ny >= n or nx >= m:
                continue
            if board[ny][nx] == 0 or dist[ny][nx] != 0:
                continue
            
            dist[ny][nx] = dist[cy][cx] + 1
            que.append([ny, nx])

BFS(0, 0)

print(dist[n-1][m-1])