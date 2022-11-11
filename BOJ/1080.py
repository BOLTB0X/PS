# 1080 행렬
from sys import stdin

n, m = map(int, stdin.readline().split())
A = [list(map(int, stdin.readline().rstrip())) for _ in range(n)]
B = [list(map(int, stdin.readline().rstrip())) for _ in range(n)]

def trans_matrix(row, col):
    for i in range(row, row + 3):
        for j in range(col, col + 3):
                A[i][j] = 1 - A[i][j]
                
answer = 0
for i in range(n - 2):
    for j in range(m - 2):
        if A[i][j] != B[i][j]:
            trans_matrix(i, j)
            answer += 1
        
        if A == B:
            break
    
    if A == B:
        break

if A != B:
    print(-1)
else:
    print(answer)