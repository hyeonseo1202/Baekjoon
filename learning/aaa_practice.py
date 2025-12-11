#2644 촌수계산
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

n = int(input().strip())
a,b = map(int, input().split())
m = int(input().strip())

graph = [[]for _ in range(n + 1)]

for _ in range(m):
    x,y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [False]*(n+1)
answer = -1

def dfs(cur,depth):
    global answer
    if cur == b:
        answer = depth
        return

    visited[cur] = True
    
    for nxt in graph[cur]:
        if not visited[nxt]:
            dfs(nxt, depth+1)

dfs(a,0)
print(answer)
        