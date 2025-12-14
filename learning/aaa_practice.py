# 16947 서울 지하철 2호선

import sys
from collections import deque
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

N = int(input())
graph = [[]for _ in range(N+1)]
degree = [0]*(N+1)

for i in range(1, N+1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    degree[a] += 1
    degree[b] += 1

#cycle인 원소 판별 - Leaf Pruning(위상 정리)
cycle = [True]*(N+1)
q = deque()

for i in range(1, N+1):
    if degree[i] == 1:
        q.append(i)
        cycle[i] = False

while q:
    x = q.popleft()
    for nx in graph[x]:
        degree[nx] -= 1
        if degree[nx] == 1:
            cycle[nx] = False
            q.append(nx)
         

#cycle과의 거리 찾기 - BFS
dist = [-1]*(N+1)
bq = deque()

for i in range(1, N+1):
    if cycle[i]:
        dist[i] = 0
        bq.append(i)

while bq:
    cur = bq.popleft()
    for nx in graph[cur]:
        if dist[nx] == -1:
            dist[nx] = dist[cur] +1
            bq.append(nx)

print(*dist[1:])