def solution(k, score):
    answer = []
    rank = [] # 명예전당 리스트
    
    for i in range(len(score)):
        # 순위 비교
        if i + 1 > k:
            # 진입 가능하면
            if rank[0] < score[i]:
                rank.append(score[i])
                rank.remove(rank[0])
        # 랭크 길이가 k가 되기 전에는+
        else:
            rank.append(score[i])
        rank.sort()
        answer.append(rank[0])
    return answer