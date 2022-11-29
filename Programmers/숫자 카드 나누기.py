# level 2
#최대 공약수
def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def solution(arrayA, arrayB):
    answer = 0
    ans_candi = [] # 정답 후보
    gcd1, gcd2 = arrayA[0], arrayB[0]
    
    # 최대공약수 
    for i in range(len(arrayA)):
        gcd1, gcd2 = gcd(gcd1, arrayA[i]), gcd(gcd2, arrayB[i])
    
    for A in arrayA:
        # B는 나누어 떨어지지 않지만 A는 떨어진다면
        if A % gcd2 == 0:
            break
    else:
        ans_candi.append(gcd2)
        
    for B in arrayB:
        # A는 나누어 떨어지지 않지만 B는 떨어진다면
        if B % gcd1 == 0:
            break
    else:
        ans_candi.append(gcd1)
    # 원소가 존재한다면
    if len(ans_candi):
        answer = max(ans_candi)
        
    return answer