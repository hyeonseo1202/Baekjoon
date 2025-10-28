from collections import deque

def shortest_path_binary_matrix(grid):
    n = len(grid)
    
    if grid[0][0] != 0 or grid[n-1][n-1] != 0:
        return -1
    
    dx = [0, 0, 1, -1, 1, 1, -1, -1]
    dy = [1, -1, 0, 0, 1, -1, -1, 1]
    visited = [[False]*n for _ in range(n)]
    
    
    q = deque()
    q.append((0,0,1))
    visited[0][0] = 1
    while q:
        cur_x, cur_y, cur_d = q.popleft()
        if cur_x == n-1 and cur_y == n-1:
                return cur_d
        for i in range(8):
            x = cur_x + dx[i]
            y = cur_y + dy[i]
            if x >= 0 and y >= 0 and x < n and y < n:
                if not visited[x][y] and grid[x][y] == 0:
                    
                    visited[x][y] = True
                    q.append((x,y, cur_d+1))
    return -1
            

# testcase1
grid1 = [
    [0,0,0],
    [1,1,0],
    [1,1,0]
]

grid2 = [
    [1,0,0],
    [1,1,0],
    [1,1,0]
]

print("case 1:", shortest_path_binary_matrix(grid1))
print("case 2:", shortest_path_binary_matrix(grid2))