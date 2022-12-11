#level 0
def solution(my_string, letter):
    answer = my_string.replace(my_string[my_string.find(letter)],'')
    return answer