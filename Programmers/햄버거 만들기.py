def solution(ingredient):
    answer = 0
    cooking = []
    
    # 단순 구현
    for i in ingredient:
        cooking.append(i)
        
        # 빵 야채 고기 빵 이순이 될때
        if len(cooking) >= 4:
            if cooking[len(cooking) - 4] == 1 and cooking[len(cooking) - 3] == 2 and cooking[len(cooking) - 2] == 3 and cooking[len(cooking) - 1] == 1:
                answer += 1
                cooking.pop();
                cooking.pop();
                cooking.pop();
                cooking.pop();
            
    return answer