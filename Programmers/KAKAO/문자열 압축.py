# 2020 KAKAO BLIND RECURITMENT level 2
def solution(s):
    answer = len(s) # 최솟값을 찾아야 하므로
    size = len(s)
    
    # 압축이 주 목적
    # 반만 검사
    for i in range(1, size + 1):
        # 몇개를 자를지 결정
        compress = ""
        cnt = 1
        cmp = s[:i]
        
        for j in range(i, size + i, i):
            if cmp == s[j:i + j]:
                cnt += 1
            else:
                if cnt > 1:
                    compress += str(cnt)
                    cnt = 1
                
                compress += cmp
                cmp = s[j:i + j]
        
        # 비교
        answer = min(answer, len(compress))
    
    return answer