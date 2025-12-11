#1707 이분그래프 DFS


# 이분그래프란?
# - 정점을 두 그룹(집합)으로 나눌 수 있고, 
# - 모든 간선은 항상 서로 다른 그룹끼리만 연결되는 그래프
# 1707 이분그래프 DFS
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

K = int(input().strip())
answers = []

for _ in range(K):
    V, E = map(int, input().split())
    graph = [[] for _ in range(V + 1)]

    for _ in range(E):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    color = [0] * (V + 1)   # 0: 미방문, 1 / -1: 두 색

    def dfs(cur, c):
        color[cur] = c
        for nxt in graph[cur]:
            if color[nxt] == 0:              # 아직 방문 X
                if not dfs(nxt, -c):         # 아래에서 False 나오면 그대로 전파
                    return False
            elif color[nxt] == c:            # 인접 정점이 같은 색이면 이분 그래프 아님
                return False
        return True

    is_bipartite = True

    for v in range(1, V + 1):
        if color[v] == 0:
            if not dfs(v, 1):
                is_bipartite = False
                break

    answers.append("YES" if is_bipartite else "NO")

print("\n".join(answers))
