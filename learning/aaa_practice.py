#2178 미로탐색
from collections import deque
import sys
input = sys.stdin.readline

N,M = map(int, input().split())
graph = [[]for _ in range(N+1)]
for i in range(N):
    for j in range(M):
        temp = int(input())
        if temp == 1:
            graph[i].append(j)
            graph[j].append(i)
def bfs(start, result):
    visited = [False]*N
    visited[start] = True
    queue = deque()
    queue.append((start,0))
    
    while queue:
        v,n = queue.popleft()
        for next in graph(v):
            if not visited[next]:
                queue.append((next,n+1))
                visited[next] = True
    
    print()