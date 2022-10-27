# 2816 디지털 디비
n = int(input())
channel = []
idx1,idx2 = 0, 0
answer = ""

for _ in range(n):
    channel.append(input())

for i in range(n):
    if channel[i] == "KBS1":
        idx1 = i
    
    if channel[i] == "KBS2":
        idx2 = i
        
for i in range(idx1):
    answer += "1"
    
for i in range(idx1):
    answer += "4"

if idx1 > idx2:
    idx2 += 1
    
for i in range(idx2):
    answer += "1"

for i in range(idx2 - 1):
    answer += "4"
    
print(answer)