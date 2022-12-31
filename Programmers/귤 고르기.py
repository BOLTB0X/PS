# level 2
from collections import Counter 

def solution(k, tangerine):
    answer = 0
    # Counter를 이용하여 딕셔너리 형태로 변환
    # 최소 종류로 귤을 선택해야하므로 내림차순으로 정렬
    count_dict = sorted(Counter(tangerine).items(),reverse = True, key = lambda x : x[1])
    
    # 발견한다면
    for key, value in count_dict:
        if k <= 0: 
            break;
        k -= value # 선택된 해당 종류의 귤 갯수만큼 차감
        answer += 1 # 카운트
        
    # 비슷하지만 다른 풀이
    answer = 0
    fruit_occ = [0 for _ in range(max(tangerine))]
    
    # 종류 귤 갯수 카운팅
    for t in tangerine:
        fruit_occ[t - 1] += 1
    
    fruit_occ.sort(reverse = True) # 내림 차순
    
    # answer를 idx로 생각하여
    # idx가 증가될때가 귤 종류를 선택한거로 가정하여 진행
    while k > 0:
        k -= fruit_occ[answer]
        answer += 1
    return answer