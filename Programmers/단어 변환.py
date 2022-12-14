#level 2
import sys
sys.setrecursionlimit(51)
cnt = 51

def is_change(word1, word2):
    w = 0
    for i in range(len(word1)):
        if word1[i] != word2[i]:
            w += 1
    
    return True if w == 1 else False

def DFS(cur, target, words, visited, level):
    global cnt
    
    # 도달 했다면
    if cur == target:
        cnt = min(cnt, level) # 최솟값 반환
        return
    
    for i in range(len(words)):
        # 변환 가능하고 미방문
        if is_change(cur, words[i]) and not visited[i]:
            visited[i] = True
            DFS(words[i], target, words, visited, level + 1)
            visited[i] = False
    
def solution(begin, target, words):
    answer = 0
    visited = [False] * len(words)
    
    # dfs
    DFS(begin, target, words, visited, 0)
    
    # 도달 했다면
    if cnt != 51:
        answer = cnt
    return answer