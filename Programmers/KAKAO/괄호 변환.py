# 2020 KAKAO BLIND RECRUITMENT level 2
# 분리
def separe_p(p):
    left, right = 0,0
    
    # 균형잡힌 괄호인지 체크
    for i in range(len(p)):
        if p[i] == '(':
            left += 1
        elif p[i] == ')':
            right += 1
        
        if left == right:
            u = p[:i + 1]
            v = p[i + 1:]
            break;
    return u, v

# 올바른 괄호인지 체크
def is_collect(p):
    stack = []
    for pp in p:
        if pp == '(':
            stack.append(pp)
        elif pp == ')':
            if not len(stack):
                return False
            else:
                stack.pop()
    if len(stack):
        return False
    return True

# 재귀
def recur_func(p):
    result = ""
    tmp = ""
    
    # 1
    if not len(p):
        return p
    
    # 2
    u, v = separe_p(p)
    
    # 3
    if is_collect(u):
        result = u + recur_func(v)# 3-1
    # 4
    else: 
        result += "(" # 4-1 
        result += recur_func(v) # 4-2
        result += ")" # 4-3
        
        u = u[1:-1] # 4-4
        for uu in u:
            if uu == '(':
                result += ')'
            else:
                result += '('
                
     # 4-5
    return result
        
def solution(p):
    answer = ""
    
    answer = recur_func(p)
    return answer