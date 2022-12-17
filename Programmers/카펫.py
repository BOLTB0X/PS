#level 2
def solution(brown, yellow):
    answer = []
    
    for i in range(1, yellow + 1):
        if yellow % i == 0:
            y_r = int(yellow / i)
            y_c = i
            
            if 2 * (y_r + y_c) + 4 == brown:
                answer.append(y_r + 2)
                answer.append(y_c + 2)
                break
    return answer