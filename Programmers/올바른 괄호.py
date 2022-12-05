# level 1
def solution(s):
    stack = []
    for ss in s:
        # 괄호가 열림일때만 
        if ss == '(':
            stack.append(ss)
        else:
            if len(stack) == 0:
                return False
            else:
                stack.pop()
    # 스택에 괄호가 있음 X
    return True if not len(stack) else False