#16236 아기상어
import sys
import heapq
from collections import deque
input = sys.stdin.readline

N = int(input().strip())
ocean = [list(map(int, input().split())) for _ in range(N)]
babyshark = 2


dx = [0,0,-1,1]
dy = [-1,1,0,0]

# 첫 아기상어 위치 저장
for i in range(N):
    for j in range(N):
        if ocean[i][j] == 9:
            shark_x = i
            shark_y = j
            
#거리 계산해주는 bfs, 못가면 -1 반환
def bfs(fx,fy):
    q = deque()
    q.append((shark_x,shark_y, 0))
    visited = [[0]* N for _ in range(N)]
    
    while q:
        x, y, dist = q.popleft()
        if x == fx and y == fy:
            return dist
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<N  and 0<=ny<N:
                if ocean[nx][ny] <= babyshark and visited[nx][ny] == 0:
                    visited[nx][ny] = 1
                    q.append((nx,ny, dist+1))
    return -1
    
    

#상어탐험 시작을 위한 첫 pq에 값 넣기
pq = []
for i in range(N):
        for j in range(N):
            if 0 < ocean[i][j] <= babyshark:
                distance = bfs(i,j)
                if distance != -1:
                    heapq.heappush(pq, (distance, i, j))

#찐 상어탐험 시작
independent = 0
eat = 0
while pq:
    dist,x,y = heapq.heappop(pq)
    pq = []
    independent+=dist
    eat+=1
    ocean[x][y] = 0
    shark_x = x
    shark_y = y
    
    if eat == babyshark:
        babyshark+=1
        eat = 0
    
    for i in range(N):
        for j in range(N):
            if ocean[i][j] < babyshark:
                distance = bfs(i,j)
                if distance != -1:
                    heapq.heappush(pq, (distance, i, j))

                
print(independent)