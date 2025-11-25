#2178 미로탐색
#행렬형태라면, 풀이는 이렇게!!! 죄표로!!!
from collections import deque
import sys
input = sys.stdin.readline

N,M = map(int, input().split())

maze = [list(map(int, input().strip()))for _ in range(N)]

dist = [[0]*M for _ in range(N)]

#상하좌우
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs(x,y):
    q = deque()
    q.append((x,y))
    dist[x][y] = 1
    
    while q:
        x,y = q.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            
            if nx == N-1 and ny == M-1:
                print(dist[x][y]+1)
                return

            if 0 <= nx < N and 0 <= ny < M:
                if maze[nx][ny] == 1 and dist[nx][ny] == 0:
                    dist[nx][ny] = dist[x][y]+1
                    q.append((nx,ny))
                    
    
bfs(0,0)