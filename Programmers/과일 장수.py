# level 1
def solution(k, m, score):
    answer = 0
    
    score.sort() # 오름차순 정렬
    for i in range(len(score), m - 1, -m):
        # 사과 한 상자의 가격은 p * m 
        answer += (score[i - m] * m)
        
    return answer