#2206 
from collections import deque
import sys
input = sys.stdin.readline

N,M = map(int, input().split())
graph = [list(map(int, input().strip()))for _ in range(N)]
visited = [[[0]*2 for _ in range(M)]for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x,y,flag):
    q = deque()
    q.append((x,y,flag))
    visited[x][y][flag] = 1
    
    while  q:
        x,y,flag = q.popleft()
        
        if x == N-1 and y == M-1:
            return visited[x][y][flag]
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx <N and 0<=ny<M:
                if graph[nx][ny] == 0:
                    if visited[nx][ny][flag] == 0:
                        visited[nx][ny][flag] = visited[x][y][flag] + 1
                        q.append((nx,ny,flag))
                elif graph[nx][ny] == 1 and flag == 0 and visited[nx][ny][flag] == 0:
                        visited[nx][ny][1] = visited[x][y][0] + 1
                        q.append((nx,ny,1))
    
    return -1

print(bfs(0,0,0))