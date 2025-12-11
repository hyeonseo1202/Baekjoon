#16234 인구이동
from collections import deque
import sys

N,L,R = map(int, input().split())
graph = [list(map(int, input().split()))for _ in range(N)]

dx = [0,0,-1,1]
dy = [-1,1,0,0]

result = 0
while True:
    
    visited = [[False]*N for _ in range(N)]
    abq = deque()
    def bfs(x,y):
        q = deque()
        q.append((x,y))
        abq.append((x,y))
        visited[x][y] = True
        total_num = 1
        total_sum = graph[x][y]
        while q:
            x, y = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0<=nx<N and 0<=ny<N:
                    if visited[nx][ny]==False and  L<= abs(graph[nx][ny] - graph[x][y]) <= R:
                        visited[nx][ny] = True
                        q.append((nx,ny))
                        abq.append((nx,ny))
                        total_num+=1
                        total_sum+=graph[nx][ny]
        return total_num, total_sum
    
    # 이 for문이 한 번 완료되면, 1일 지난 것
    flag = 0
    for x in range(N):
        for y in range(N):
            if visited[x][y] == False:
                abq.clear()
                a,b = bfs(x,y)
                if a>=2:
                    flag = 1
                    while abq:
                        i,j = abq.popleft()
                        graph[i][j] = b//a
    if flag == 1:
        result +=1
    else:
        print(result)
        break