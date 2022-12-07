# level 0
from itertools import permutations

def solution(babbling):
    answer = 0
    word = ["aya", "ye", "woo", "ma"]
    candi = []
    
    for i in range(1, 5):
        # 단어 순열로 조합
        for p in permutations(word, i):
            candi.append(''.join(p))
            
    for b in babbling:
        if b in candi:
            answer += 1
    return answer