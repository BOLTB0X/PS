# level 1
def string_slide(s):
    x1, x2 = 0, 0
    
    for idx, ch in enumerate(s):
        if ch == s[0]:
            x1 += 1
        else:
            x2 += 1

        if x1 == x2:
            return s[idx + 1 :]

    return ""

def solution(s):
    # 내 풀이
    answer = 0
    flag = 0
    
    while s:
        # x1이 x x2가 x가 아닌
        x1 , x2 = 1, 0
        # 문자열이 하나 남는다면
        if len(s) == 1 or len(s) == 0 or flag == 1:
            answer += 1
            break;
            
        for i in range(1, len(s)):
            if s[i] == s[0]:
                x1 += 1
            else:
                x2 += 1
            # 두 카운트가 같다면
            if x1 == x2:
                s = s[i + 1:]
                answer += 1;
                break;
                
            elif i == len(s) - 1 and x1 != x2:
                flag = 1
                break
    
    # 다른 사람 풀이 참고
    answer = 0
    
    while s:
        ret = string_slide(s)
        answer += 1
        
        if not ret:
            break
        
    return answer