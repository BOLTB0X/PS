# level 2
from collections import Counter 

def solution(k, tangerine):
    answer = 0
    # Counter를 이용하여 딕셔너리 형태로 변환
    # 최소 종류로 귤을 선택해야하므로 내림차순으로 정렬
    count_dict = sorted(Counter(tangerine).items(),reverse = True, key = lambda x : x[1])
    
    for key, value in count_dict:
        if k <= 0:
            break;
        k -= value # 선택된 해당 종류의 귤 갯수만큼 차감
        answer += 1 # 카운트
    return answer