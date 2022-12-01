# level 1
def solution(a, b, n):
    answer = 0
    
    while n >= a:
        rest_coke = n % a # 묶음이 안될 때 남는 콜라
        n = n // a * b # 얻어 가는 콜라이자 다음 루프때 쓰일 총 콜라
        answer += n
        n += rest_coke # 만약 남을 걸 대비
        
    return answer