#level 0
def solution(sides):
    # 가장 긴 변 찾기
    long_len = sides.pop(sides.index(max(sides)))
    
    return 1 if long_len < sum(sides) else 2