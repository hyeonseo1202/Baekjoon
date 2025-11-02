def unique_path(m,n):
    result = 0
    def dfs(cur_m,cur_n):
        if cur_m >= m or cur_n>=n:
            return 0
        if cur_m == m-1 and cur_n == n-1:
            return 1
        return dfs(cur_m + 1,cur_n)+dfs(cur_m,cur_n + 1)
        
    return dfs(0,0)

print(unique_path(3,7)) #28
print(unique_path(3,2)) #3
