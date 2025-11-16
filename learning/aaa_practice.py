#i면, i 또는 i+1

import sys
input = sys.stdin.readline

n = int(input())
triangle = [list(map(int, input().split()))for _ in range(n)]
memo = [[]for _ in range(n)]

for i in range(n):
    m = len(triangle[i])
    for j in range(m):
        if i == 0: 
            memo[i][j] = triangle[i][j]
        elif memo[i][j]:
            pass
        else:
            memo[i][j] = triangle[i][j] + max(memo[i-1][j],memo[i-1][j+1])
            




    