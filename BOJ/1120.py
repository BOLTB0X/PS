# 1120 문자열
A, B = input().split()
answer = 51

for i in range(len(B) - len(A) + 1):
    cnt = 0
    for j in range(len(A)):
        if A[j] != B[j + i]:
           cnt += 1
        
    if answer > cnt:
         answer = cnt

print(answer)