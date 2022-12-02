# level 2
import itertools

def solution(k, dungeons):
    answer = -1
    # 순열을 이용
    per = itertools.permutations(dungeons, len(dungeons))
    
    # 완전탐색
    # 한 순열 하나씩 확인
    for candi_p in per:
        cur_p = k # 초기화
        cnt = 0
        for c_p in candi_p:
            # 던전을 지날 수 있으면
            if c_p[0] <= cur_p:
                cnt += 1
                cur_p -= c_p[1]
        answer = max(answer, cnt)
    return answer