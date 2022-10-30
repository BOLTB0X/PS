# 11724 연결 요소의 개수
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

node, edge = map(int, input().split())
adj = [ [] for _ in range(node + 1)]
visited = [False] * (node + 1)
answer = 0

for _ in range(edge):
     a, b = map(int, input().split())
     adj[a].append(b)
     adj[b].append(a)
     
def DFS(cur):
    visited[cur] = True
        
    for next in adj[cur]:
        if visited[next] == False:
            DFS(next)

for i in range(1, node + 1):
    if visited[i] == False:
        DFS(i)
        answer += 1
    
print(answer)