# 연습문제 level 1
def solution(number, limit, power):
    answer = 0
    divisors = []
    
    for num in range(1, number + 1):
        cnt = 0 # 갯수 초기화
        # 약수 체크
        # 시간 초과 방지
        for i in range(1, int(num**(1/2)) + 1):
            if (num % i == 0):
                cnt += 1
                # 시간 초과 방지
                if ( (i**2) != num) : 
                    cnt += 1
        divisors.append(cnt);
        
    for d in divisors:
        if d > limit: # 넘는다면 
            answer += power
        else:
            answer += d
            
    return answer