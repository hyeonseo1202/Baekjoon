from collections import deque
import sys
input = sys.stdin.readline

t_case = int(input())

dx = [0,0,-1,1]
dy = [-1,1,0,0]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    ground[y][x] = 0
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny < N:
                if ground[ny][nx] == 1:
                    ground[ny][nx] = 0
                    queue.append((nx, ny))


for _ in range(t_case):
    M, N, K = map(int, input().split())

    ground = [[0] * M for _ in range(N)]

    for _ in range(K):
        x, y = map(int, input().split())
        ground[y][x] = 1  # ← 좌표는 ground[y][x]

    cnt = 0

    for y in range(N):
        for x in range(M):
            if ground[y][x] == 1:
                bfs(x, y)
                cnt += 1
    
    print(cnt)
