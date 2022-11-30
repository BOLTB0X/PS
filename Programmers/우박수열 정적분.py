#level 2
# 콜라츠 추측
def get_woobak_seq(k):
    number = k
    woobak = [k] # 처음 자기자신도 포함하므로
    
    # 1이 될때까지
    while number != 1:
        if number % 2 == 1:
            number = number * 3 + 1

        else:
            number //= 2
        woobak.append(number)

    return woobak

def solution(k, ranges):
    answer = []
    ret_list = get_woobak_seq(k) # 우박수열
    
    for x1, x2 in ranges:
        # x1, x2는 각 0부터 정수, 음수이므로
        x3 = len(ret_list) + x2 - 1
        if x1 > x3:
            answer.append(-1)
        else:
            tot = 0
            for i in range(x1, x3):
                tot += (ret_list[i] + ret_list[i + 1]) / 2 #사다리꼴 넓이
            answer.append(tot)
    
    return answer