#9466 팀 프로젝트
#dfs 사용

import sys
from collections import deque
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

T = int(input())
result = deque()
for _ in range(T):
    n = int(input())
    graph = [0] + list(map(int, input().split()))
    
    visited = [False] * (n+1)
    finished = [False] * (n+1)
    cycle_cnt = 0
    
    def dfs(x):
        global cycle_cnt
        visited[x] = True
        nxt = graph[x]
        
        if not visited[nxt]:
            dfs(nxt)
        else:
            if not finished[nxt]:
                cycle_cnt += 1
                cur = nxt
                while cur != x:
                    cycle_cnt +=1
                    cur = graph[cur]
        finished[x] = True
        
    for i in range(1, n+1):
        if not visited[i]:
            dfs(i)
    result.append(n - cycle_cnt)
        
while result:
    n = result.popleft()
    print(n)
    