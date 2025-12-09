# 16236 아기상어 - BFS 정석 풀이
import sys
from collections import deque
input = sys.stdin.readline

N = int(input().strip())
ocean = [list(map(int, input().split())) for _ in range(N)]

# 초기 상어 위치 찾기
for i in range(N):
    for j in range(N):
        if ocean[i][j] == 9:
            shark_x, shark_y = i, j
            ocean[i][j] = 0  # 시작 위치는 이제 빈칸으로 처리
            break

size = 2      # 상어 크기
eat = 0       # 현재 크기에서 먹은 물고기 수
time = 0      # 답: 걸린 총 시간(거리)

def find_fish(sx, sy, size):
    visited = [[-1] * N for _ in range(N)]
    q = deque()
    q.append((sx, sy))
    visited[sx][sy] = 0

    fishes = []  # (dist, x, y)

    # 위, 왼, 오른, 아래 순서로 탐색하면
    # 나중에 정렬할 때 살짝 유리하지만, 어차피 dist,x,y 기준으로 sort할 거라 큰 차이는 없음
    dirs = [(-1,0), (0,-1), (0,1), (1,0)]

    while q:
        x, y = q.popleft()

        for dx, dy in dirs:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] == -1 and ocean[nx][ny] <= size:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append((nx, ny))

                    if 0 < ocean[nx][ny] < size:
                        fishes.append((visited[nx][ny], nx, ny))

    if not fishes:
        return None
    fishes.sort()          # 거리, x, y 순으로 정렬
    return fishes[0]       # (dist, x, y)

while True:
    result = find_fish(shark_x, shark_y, size)
    if result is None:
        break

    dist, fx, fy = result
    time += dist

    # 상어 이동 + 먹기
    shark_x, shark_y = fx, fy
    ocean[fx][fy] = 0
    eat += 1

    if eat == size:
        size += 1
        eat = 0

print(time)
