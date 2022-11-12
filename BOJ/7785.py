# 7785 회사에 있는 사람
from sys import stdin
input = stdin.readline

n = int(input())
dic = {}

for _ in range(n):
    name, state = input().split()
    
    if state == "enter":
        dic[name] = 1
    
    else:
        del dic[name]

dic = sorted(dic.keys(), reverse = True)
for d in dic:
    print(d)