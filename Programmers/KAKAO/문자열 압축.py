# 2020 KAKAO BLIND RECURITMENT level 2
def solution(s):
    size = len(s)
    answer = size
        
    # 몇개씩 압축할지 결정
    for i in range(1, size // 2 + 1):
        compress = ""
        cmp = s[:i]
        cnt = 1
        
        # 비교할 자른 문자열의 길이,간격으로
        # for문의 범위 끝을 간격만큼 넓혀둠
        for j in range(i, size + i, i):
            if cmp == s[j:j + i]:
                cnt += 1
            else:
                if cnt == 1:
                    compress += cmp
                else:
                    compress += (str(cnt) + cmp)
                
                # 압축이 끝났으니 변경
                cmp = s[j:j+i]
                cnt = 1
        
        answer = min(answer, len(compress))
            
    return answer