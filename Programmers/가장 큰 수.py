# level 2
def solution(numbers):
    answer = ''
    str_num = []
    
    for num in numbers:
        str_num.append(str(num))
    
    str_num.sort(key = lambda n : n * 3, reverse = True)
    
    for s in str_num:
        answer += s
    
    if answer[0] == '0':
        answer = '0'
    return answer