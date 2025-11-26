#2667 단지 번호 붙이기
from collections import deque
import sys
input = sys.stdin.readline

N = int(input().strip())
squaremap = [list(map(int, input().strip()))for _ in range(N)]


dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs(x,y):
    queue = deque()
    queue.append((x,y))
    squaremap[x][y] = 0
    num = 1
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < N:
                if squaremap[nx][ny] == 1:
                    queue.append((nx,ny))
                    num+=1
                    squaremap[nx][ny] = 0
    return num
result1 = 0
result2 = []
for i in range(N):
    for j in range(N):
        if squaremap[i][j] == 1:
            result1+=1
            num = bfs(i,j)
            result2.append(num) 
print(result1)
for cnt in sorted(result2):
    print(cnt)
