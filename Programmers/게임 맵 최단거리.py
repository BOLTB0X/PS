#게임 맵 최단거리 level 2
from collections import deque

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def solution(maps):
    answer = 0
    r = len(maps) 
    c = len(maps[0])
    
    que = deque()
    que.append([0,0])
    
    while que:
        cy, cx = que.popleft()
        
        for dir in range(4):
            ny = cy + dy[dir]
            nx = cx + dx[dir]
            
            if 0 <= ny < r and 0 <= nx < c:
                if maps[ny][nx] == 1:
                    maps[ny][nx] = maps[cy][cx] + 1
                    que.append([ny, nx])
    
    answer = maps[-1][-1] if maps[-1][-1] != 1 else -1
    return answer