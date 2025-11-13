def min_cost_top_down(cost):
    n = len(cost)
    memo = [0]*n
    
    def recur(i):
        if i<2:
            return cost[i]
        memo[i] = cost[i] + min(recur(i-1), recur(i-2))
        return memo[i] #반환 꼭 필요해애애 아니면, 윗 수식에서 none이 들어가게 됨<-type error
    return min(recur(n-1), recur(n-2))

# ✅ 예시 실행
print(min_cost_top_down([10, 15, 20]))  # 15
print(min_cost_top_down([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))  # 6