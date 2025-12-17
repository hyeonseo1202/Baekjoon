#1463 1로 만들기

import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

N = int(input())

dp = [-1]*(N+1)

def bottom_up(N):
    if N == 1:
        return 0
    dp[1] = 0
    for i in range(2, N+1):
        res = dp[i-1]+1
        if i %2 == 0:
            res = min(res, dp[i//2]+1)
        if i%3 == 0:
            res = min(res, dp[i//3]+1)
        dp[i] = res
    
    return dp[N]
    

print(bottom_up(N))