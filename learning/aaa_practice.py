#1012 유기농 배추
from collections import deque
import sys
input = sys.stdin.readline


t_case = int(input())
result = [0 * t_case]
for k in range(t_case):
    N,M,K = map(int, input().split())
    ground = [[0 * (M+1)]for _ in range(N+1)]
    for _ in range(K):
        a, b = map(int, input().split())
        ground[a][b] = 1
    
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    
    def dfs(x,y):
        queue = deque()
        queue.append(x,y)
        ground[x][y] = 0
        while queue:
            x, y= queue.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < N and 0<= ny < M and ground[nx][ny] == 1:
                    queue.append[nx][ny]
                    ground[nx][ny] = 0
    
    for i in range(1,N):
            for j in range(1,M):
                if ground[i][j] == 1:
                    dfs(i,j)
                    result[k] +=1
                    
    for index in range(t_case):
        print(result[index])
        print()