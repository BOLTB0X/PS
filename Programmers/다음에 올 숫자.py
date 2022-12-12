#level 0
def solution(common):
    answer = 0
    if common[len(common) - 1] == 2 * common[len(common) - 2] - common[len(common) -3]:
        answer = 2 * common[len(common) - 1] - common[len(common) - 2]
    else:
        answer = common[len(common) - 1] * (common[len(common) - 2] // common[len(common) - 3])
    return answer