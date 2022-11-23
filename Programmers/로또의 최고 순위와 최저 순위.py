# 2021 Dev-Matching level 1
def solution(lottos, win_nums):
    answer = []
    
    check1 = 0
    check2 = 0
    for i in range(len(lottos)):
        if lottos[i] in win_nums:
            check1 += 1
            check2 += 1
        elif lottos[i] == 0:
            check1 += 1
    
    answer.append(7 - (check1 if check1 >= 2 else 1))
    answer.append(7 - (check2 if check2 >= 2 else 1))
    return answer