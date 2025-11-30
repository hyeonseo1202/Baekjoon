#7576 토마토
from collections import deque
import sys
input = sys.stdin.readline

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

M, N = map(int, input().split())
ground = [list(map(int, input().split())) for _ in range(N)]

queue = deque()

# 처음에 익어 있는 토마토들을 전부 큐에 넣고 시작
for y in range(N):
    for x in range(M):
        if ground[y][x] == 1:
            queue.append((x, y))

# BFS
while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < M and 0 <= ny < N:
            if ground[ny][nx] == 0:              # 아직 안 익은 토마토만
                ground[ny][nx] = ground[y][x] + 1  # 날짜(거리) 기록
                queue.append((nx, ny))

answer = 0
for row in ground:
    for v in row:
        if v == 0:          # 끝까지 안 익은 토마토가 있다면
            print(-1)
            sys.exit(0)
        answer = max(answer, v)

# 처음부터 모두 익어 있었다면 최대값이 1이므로 0일 걸린 것
print(answer - 1)
