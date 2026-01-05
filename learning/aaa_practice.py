#1753 최단경로

import sys
import heapq
input = sys.stdin.readline

INF = 10**18

V, E = map(int, input().split())
K = int(input())

graph = [[]for _ in range(V+1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

dist = [INF]*(V+1)
dist[K] = 0
pq = [(0,K)]

while pq:
    cur_dist, cur = heapq.heappop(pq)
    if cur_dist != dist[cur]:
        continue
    
    for nxt, w in graph[cur]:
        nd = cur_dist + w
        if nd < dist[nxt]:
            dist[nxt] = nd
            heapq.heappush(pq, (nd, nxt))
                
                



