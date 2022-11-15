def solution(id_list, report, k):
    answer = [0] * len(id_list)
    dic = {id : 0 for id in id_list}
    
    # set을 통해 중복 신고 X
    for r in set(report):
        a,b = r.split()
        
        dic[b] += 1
    
    for r in set(report):
        a,b = r.split()
        
        if dic[b] >= k :
            answer[id_list.index(a)] += 1
            
    return answer