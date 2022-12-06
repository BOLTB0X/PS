# 2022 KAKAO TECH INTERNSHIP level 2
from collections import deque

def solution(queue1, queue2):
    answer = 0
    
    que1, que2 = deque(queue1), deque(queue2)
    tot1, tot2 = sum(que1), sum(que2)
    
    for _ in range(len(que1) * 3):
        if tot1 > tot2:
            tot1 -= que1[0]
            tot2 += que1[0]
            que2.append(que1.popleft())
            
        elif tot1 < tot2:
            tot2 -= que2[0]
            tot1 += que2[0]
            que1.append(que2.popleft())
            
        else:
            return answer;
        answer += 1
            
    return -1