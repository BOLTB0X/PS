# 2606 바이러스
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

node = int(input())
edge = int(input())

adj = [ [] for _ in range(node + 1)]
visited = [False] * (node + 1)
answer = 0

for _ in range(edge):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
    
def DFS(cur):
    global answer
    visited[cur] = True
    
    for next in adj[cur]:
        if visited[next] == False:
            answer += 1 # 1번 자기 자신은 제외
            DFS(next)
            
DFS(1)
print(answer)