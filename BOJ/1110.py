# 1110 더하기 사이클
n = int(input())

number = n
answer = 0

while True:
    front = number // 10
    back = number % 10
    
    number = back * 10 + (front + back) % 10
    answer += 1
    
    if n == number:
        break

print(answer)