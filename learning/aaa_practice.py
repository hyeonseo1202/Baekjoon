import sys
input = sys.stdin.readline

R, C = map(int, input().split())
graph = [list(input().strip()) for _ in range(R)]


dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def dfs(x, y):
    stack = set()
    
    stack.add((x, y, graph[y][x]))
    maxdepth = 0

    while stack:
        x, y, visited = stack.pop()

        maxdepth = max(maxdepth, len(visited))
        if maxdepth == 26:
            return 26

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < C and 0 <= ny < R:
                if graph[ny][nx] not in visited:
                    stack.add((nx, ny, visited + graph[ny][nx]))

    return maxdepth

print(dfs(0, 0))
