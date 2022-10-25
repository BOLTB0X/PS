#1652 누울 자리를 찾아라
n = int(input())
board = []
answer = [0, 0]

for _ in range(n):
    board.append(list(map(str, input())))

for i in range(n):
    row_cnt, col_cnt = 0, 0
    for j in range(n):
        if board[i][j] == '.':
            row_cnt += 1
        
        elif board[i][j] == 'X':
            if row_cnt >= 2:
                answer[0] += 1
            row_cnt = 0
                
        if board[j][i] == '.':
            col_cnt += 1
        
        elif board[j][i] == 'X':
            if col_cnt >= 2:
                answer[1] += 1
            col_cnt = 0
                
    if row_cnt >= 2:
        answer[0] += 1
            
    if col_cnt >= 2:
        answer[1] += 1
        
print(*answer)