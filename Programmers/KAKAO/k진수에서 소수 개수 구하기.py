# 2022 KAKAO BLIND RECRUITMENT level 2
import math

# 진법 변환
def trans_Number(n, k):
    ret = ""
    
    while n > 0:
        ret += str(n%k)
        n //= k
    
    return reversed(ret)

# 소수 판별
def is_Prime(number):
    if number == 0 or number == 1:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    ret = trans_Number(n, k) # 변환
    prime_candi = ""
    
    for r in ret:
        # P0 0P0 ,0P 에서 중복되는 소수를 발견하더라도 따로 세야함
        if r == "0":
            if len(prime_candi) and is_Prime(int(prime_candi)):
                answer += 1
            prime_candi = ""
        else:
            prime_candi += r
    
    # 만약 소수 후보가 존재할 경우 체크
    if len(prime_candi) and is_Prime(int(prime_candi)):
        answer += 1
    return answer