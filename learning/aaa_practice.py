#18352 특정 거리의 도시 찾기
from collections import deque
import sys
input = sys.stdin.readline

N, M, K, X = map(int, input().split())
graph = [[]for _ in range(N+1)]
for _ in range(M):
    a,b = map(int, input().split())
    graph[a].append(b)

visited = [False]*(N+1)
result = deque()

def bfs():
    q = deque()
    q.append((X, 0))
    visited[X] = True
    while q:          
        
        cur, dist = q.popleft()
        
        if dist == K:
            result.append(cur)
        for key in graph[cur]:
            if visited[key] == False:
                visited[key] = True
                q.append((key, dist+1))

bfs()

if result:
    result = sorted(result)
    for city in result:
        print(city)
else:
    print(-1)

    
