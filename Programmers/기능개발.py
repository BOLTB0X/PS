#level 2
def solution(progresses, speeds):
    answer = []
    
    while progresses:
        # 배포 되는 기능 체크
        cnt = 0
        # 반복문 도중 progresses가 비어질 수도 있으므로
        while progresses and progresses[0] >= 100:
            progresses.pop(0)
            speeds.pop(0)
            cnt +=1 
        
        # 배포가 되었다면
        if cnt:
            answer.append(cnt)
        
        for i in range(len(speeds)):
            progresses[i] += speeds[i]
        
    return answer