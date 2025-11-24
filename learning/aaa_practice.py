#2606 바이러스
from collections import deque
import sys
input = sys.stdin.readline

computer = int(input().strip())
edge = int(input().strip())
graph = [[]for _ in range(computer + 1)]
for _ in range(edge):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(start):
    visited = [False]*(computer + 1)
    queue = deque([start])
    visited[start] = True
    
    while queue:
        v = queue.popleft()
        for next in graph[v]:
            if not visited[next]:
                queue.append(next)
                visited[next] = True
    
    result = 0      
    for i in range(2,computer+1):
        if visited[i]:
            result +=1
    
    print(result)

bfs(1)
