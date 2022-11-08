# 1931 회의실 배정
n = int(input())
schedules = [list(map(int, input().split())) for _ in range(n)]

schedules.sort(key = lambda x :(x[1], x[0]))
#print(*schedules)
sample = schedules[0][1]
answer = 1

for i in range(1, n):
    if schedules[i][0] >= sample:
        #print(*schedules[i])
        answer += 1
        sample = schedules[i][1]

print(answer)