# 연습문제 level 1
def solution(k, score):
    answer = []
    rank = []
    
    for i in range(len(score)):
        if i + 1 > k:
            # k순위 보다 클때마다
            if score[i] > rank[0]:
                rank.append(score[i])
                rank.remove(rank[0])
        # rank의 길이가 k보다 작을 때
        else:
            rank.append(score[i])
        rank.sort()
        answer.append(rank[0])
            
    return answer

print(solution(3, [10, 100, 20, 150, 1, 100, 200]))