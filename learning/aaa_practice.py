#17412 연구소3
from collections import deque
from itertools import combinations
import sys
imput = sys.stdin.readline

N,M = map(int, input().split())
lab = [list(map(int, input().split()))for _ in range(N)]

dx = [0,0,-1,1]
dy = [-1,1,0,0]

#기본 바이러스들 집합
viruses = []
for y in range(N):
        for x in range(N):
            if lab[y][x] == 2:
                viruses.append((x,y))
 
#활성 바이러스들 받아서 한 번에 시작            
def spread(board, active_viruses):
    fin_depth = 0
    q = deque()
    for x, y in active_viruses:
        q.append((x, y, 0))
        
    while q:
        x, y, depth = q.popleft()
        for k in range(4):
            nx,ny = x + dx[k], y+dy[k]
            if 0 <= nx < N and 0 <= ny < N:
                # 빈칸(0)일 때만 시간이 의미 있음
                if board[ny][nx] == 0:
                    board[ny][nx] = -1
                    fin_depth = max(fin_depth, depth + 1)
                    q.append((nx, ny, depth + 1))

                # 비활성 바이러스(2)는 "통과"만 (fin_depth 갱신 X)
                elif board[ny][nx] == 2:
                    board[ny][nx] = -1
                    q.append((nx, ny, depth + 1))
    for y in range(N):
        for x in range(N):
            if board[y][x] == 0:
                return float('inf')  # 실패
    return fin_depth



ans = float('inf')

for walls in combinations(viruses, M):
    board = [row[:] for row in lab]
    active_viruses = []
    for x, y in walls:
        board[y][x] = -1
        active_viruses.append((x,y))
    
    ans = min(ans, spread(board, active_viruses))
    
if ans == float('inf'):
    print(-1)
else:
    print(ans)