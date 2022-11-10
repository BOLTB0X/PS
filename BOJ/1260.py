# 1260 DFS와 BFS
from collections import deque

def DFS(cur):
    visited[cur] = True
    print(cur, end = ' ')
    
    for next in adj[cur]:
        if not visited[next]:
            DFS(next)
            
def BFS(start):
    que = deque([start])
    visited[start] = True
    
    while que:
        cur = que.popleft()
        print(cur, end = ' ')
        
        for next in adj[cur]:
            if not visited[next]:
                que.append(next)
                visited[next] = True

n, m, k = map(int,input().split())
adj = [[] for _ in range(n + 1)] 
visited = [False] * (n + 1)

for _ in range(m):
    a, b = map(int,input().split())
    
    adj[a].append(b)
    adj[b].append(a)
    
for a in adj:
    a.sort()

DFS(k)
print()
visited = [False] * (n + 1)
BFS(k)