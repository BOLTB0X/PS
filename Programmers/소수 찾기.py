from itertools import permutations
import math

# 소수 판별
def is_prime(p):
    if p == 0 or p == 1:
        return False
    
    for i in range(2, int(math.sqrt(p)) + 1):
        if p % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    candi = [] # 후보군
    
    # 1부터 길이까지 나올 수 있는 순열
    for i in range(1, len(numbers) + 1):
        per_str = set(permutations(numbers, i))
        # set형과 튜플로 나오니 순서대로 정수를 만들어줌
        for per in per_str:
            tmp = ""
            for pe in per:
                tmp += pe
            candi.append(int(tmp))
    
    for ca in set(candi):            
        if is_prime(ca): # 판별
            answer += 1
    return answer