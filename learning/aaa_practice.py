#1260: DFS와 BFS
import sys
from collections import deque
input = sys.stdin.readline

N,M,V = map(int, input().split())
graph = [[]for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
#정점 번호 작은 것부터 방문해야 하므로 정렬!
for i in range(1, N+1):
    graph[i].sort()


def dfs(v,visited):
    visited[v] = True
    print(v, end=' ')
    for next in graph[v]:
        if not visited[next]:
            dfs(next, visited)
            
def bfs(start):
    visited = [False]*(N+1)
    queue = deque([start])
    visited[start] = True
    
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for next in graph[v]:
            if not visited[next]:
                visited[next] = True
                queue.append(next)

visited = [False]*(N+1)
dfs(V,visited)
print()
bfs(V)