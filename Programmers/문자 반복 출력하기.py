#level 0
def solution(my_string, n):
    answer = ''
    
    for my in my_string:
        answer += my * n
    return answer