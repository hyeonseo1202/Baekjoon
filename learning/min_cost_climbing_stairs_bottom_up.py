def min_cost_bottom_up(cost):
    n = len(cost)
    if n<2:
        return min(cost)
    memo = [0]*n
    memo[0] = cost[0]
    memo[1] = cost[1]
    
    for i in range(2,n):
        memo[i] = cost[i] + min(memo[i-1], memo[i-2])
    
    return min(memo[n-1], memo[n-2])

# ✅ 예시 실행
print(min_cost_bottom_up([10, 15, 20]))  # 15
print(min_cost_bottom_up([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))  # 6