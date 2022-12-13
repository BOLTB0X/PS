# level 2
def solution(number, k):
    answer = ''
    stack = []
    
    for num in number:
        # 반복
        # 추가해야할 k가 있고 스택 top보다 큰 값을 만날때 까지
        while k > 0 and stack and stack[-1] < num:
            stack.pop()
            k -= 1
        # 중단되고 해당 값 스택에 삽입
        stack.append(num)
    
    # 차례로 끝까지 그냥 선택해야하는 경우도 존재
    # 그럼 k는 for문이 끝나도 0이 아님
    if k > 0:
        stack = stack[:-1]
    answer = ''.join(stack)
    return answer