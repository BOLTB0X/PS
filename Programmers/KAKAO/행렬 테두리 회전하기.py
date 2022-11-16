# 2021 Dev-Matching: 웹 백엔드 개발자 level 2
def solution(rows, columns, queries):
    answer = []
    board = [[0 for _ in range(columns + 1)] for _  in range(rows + 1)]
    number = 1
    
    # 격자판 생성
    for i in range(1, rows + 1):
        for j in range(1, columns + 1):
            board[i][j] = number
            number += 1
    
    for x1,y1,x2,y2 in queries:
        cur = board[x1][y1]
        tmp_min = cur
        
        for i in range(x1, x2):
            tmp = board[i + 1][y1]
            board[i][y1] = tmp
            
            # 변경
            tmp_min = min(tmp_min, tmp)
            
        for i in range(y1, y2):
            tmp = board[x2][i + 1]
            board[x2][i] = tmp
            
            # 변경
            tmp_min = min(tmp_min, tmp)
            
        for i in range(x2, x1, - 1):
            tmp = board[i - 1][y2]
            board[i][y2] = tmp
            
            # 변경
            tmp_min = min(tmp_min, tmp)
            
        for i in range(y2, y1, - 1):
            tmp = board[x1][i - 1]
            board[x1][i] = tmp
            
            # 변경
            tmp_min = min(tmp_min, tmp)
        board[x1][y1 + 1] = cur
        answer.append(tmp_min)
    return answer