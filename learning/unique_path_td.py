def unique_path_td(m,n):
    memo = [[-1]*n for _ in range(m)]
    
    def dfs(row,col):
        if row == 0 or col == 0:
            memo[row][col] = 1
            return memo[row][col]
        unique_path = 0
        if memo[row][col] == -1:
            if row -1 >= 0:
                unique_path += dfs(row-1,col)
            if col - 1 >= 0:
                unique_path += dfs(row,col-1)
            
            memo[row][col] = unique_path
            
        return memo[row][col]
    
    return dfs(m-1,n-1)

print(unique_path_td(3,7))
        
        