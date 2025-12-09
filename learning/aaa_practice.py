#11724 연결요소의 개수
from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[]for _ in range(N+1)]
visited = [False]*(N+1)

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(start):
    q = deque([start])
    visited[start] = True
    
    while q:
        cur = q.popleft()
        for next in graph[cur]:
            if not visited[next]:
                visited[next] = True
                q.append(next)

count = 0
for i in range(1, N+1):
    if not visited[i]:
        bfs(i)
        count+=1

print(count)
    



