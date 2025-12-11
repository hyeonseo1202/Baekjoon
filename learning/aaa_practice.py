#1707 이분그래프 DFS


# 이분그래프란?
# - 정점을 두 그룹(집합)으로 나눌 수 있고, 
# - 모든 간선은 항상 서로 다른 그룹끼리만 연결되는 그래프
import sys
input = sys.stdin.readline

K = int(input().strip())
for _ in range(K):
    V, E = map(int, input().split())
    graph = [] *(V+1)
    
    for _ in range(E):
        a,b = map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
        
    color = [0] * (V+1)
    flag = True
    
    def dfs(cur, c):
        global flag
        if flag == False:
            return
        
        color[cur] = c
        for next in graph[cur]:
            if color[next] == 0:
                dfs(next, -c)
            elif color[next] == c:
                flag = False
                return
        
    for v in range(1, V+1):
        if color[v] == 0:
            dfs(v,1)
            if flag == False:
                break
    
    print("YES" if flag else "NO")
