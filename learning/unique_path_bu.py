def unique_path_bu(m,n):
    memo = [[-1]*n for _ in range(m)]
    for i in range(m):
        memo[i][0] = 1
    for i in range(n):
        memo[0][i] = 1
    
    for i in range(1,m):
        for j in range(1,n):
            unique_path = 0
            if i-1 >=0:                
                unique_path += memo[i-1][j]
            if j-1 >= 0:
                unique_path += memo[i][j-1]
            memo[i][j] = unique_path
    
    return memo[m-1][n-1]

print(unique_path_bu(3,7))