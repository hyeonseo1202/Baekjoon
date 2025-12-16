#12865 평범한 배낭

import sys
input =  sys.stdin.readline
N, K = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(N)]
    
result = 0

#모든 경우 다 탐색하는 것!!! - backtracking
def dfs(i, cur_w, cur_v):
    global result
    
    if cur_w > K:
        return
    
    if i == N:
        result = max(result, cur_v)
        return
    
    w, v = items[i]
    # i번째 아이템 담는 경우
    dfs(i+1, cur_w+w, cur_v+v)
    
    #i번째 아이템 담지 않는 경우
    dfs(i+1, cur_w, cur_v)

dfs(0,0,0)
print(result)