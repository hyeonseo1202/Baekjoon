#7576 토마토
from collections import deque
import sys
input = sys.stdin.readline


dx = [0,0,-1,1]
dy = [-1,1,0,0]


def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    ground[y][x] = 1
    depth = 0
    while queue:
        x, y = queue.popleft()
        flag = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny < N:
                if ground[ny][nx] == 0:
                    ground[ny][nx] = 1
                    queue.append((nx, ny))
                    flag = 1
        if flag == 1:
            depth += 1
    
    return depth

def all_one(ground):
    return all(all(x==1 for x in row)for row in ground)       


M, N= map(int, input().split())

ground = [list(map(int, input().split()))for _ in range(N)]
if all_one(ground):
    print(0)
else:
    result = 0
    for i in range(M):
        for j in range(N):
            if ground[j][i] == 0:
                result = max(bfs(i,j), result)
    if all_one(ground):
        print(result)
    else:
        print(-1)