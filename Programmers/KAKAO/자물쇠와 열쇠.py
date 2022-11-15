# level 3
# 2020 KAKAO BLIND RECURITMENT
def rotate(board, d):
    n = len(board)
    result = [[0] * n for _ in range(n)]
    
    # 90
    if d % 4 == 1:
        for r in range(n):
            for c in range(n): 
                result[c][n - r - 1] = board[r][c]
    elif d % 4 == 2:
        for r in range(n):
            for c in range(n):
                result[n - r - 1][n - c - 1] = board[r][c]
    elif d % 4 == 3:
        for r in range(n):
            for c in range(n):
                result[n - c - 1][r] = board[r][c]
    else:
        for r in range(n):
            for c in range(n):
                result[r][c] = board[r][c]

    return result

def check(board):
    size = len(board) // 3
    
    for i in range(size, size * 2):
        for j in range(size, size * 2):
            if board[i][j] != 1:
                return False
    return True

def solution(key, lock):
    key_size = len(key)
    lock_size = len(lock)
    board = [[0] * (lock_size * 3) for _ in range(lock_size * 3)]
    
    # lock 사이즈 업
    for i in range(lock_size):
        for j in range(lock_size):
            board[i + lock_size][j + lock_size] = lock[i][j]
    
    for i in range(1, 2 * lock_size):
        for j in range(1, 2 * lock_size):
            for dir in range(4):
                r_key = rotate(key, dir)
                
                # 회전한 키를 대본다
                for k in range(key_size):
                    for l in range(key_size):
                        board[i + k][j + l] += r_key[k][l]
                
                if check(board):
                    return True
                
                # 회전한 원상복귀
                for k in range(key_size):
                    for l in range(key_size):
                        board[i + k][j + l] -= r_key[k][l]
    
    return False