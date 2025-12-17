#1463 1로 만들기

#시간초과는 메모이제이션 사용하지 않았기 때문에 발생함!!
# dp배열을 써서 메모이제이션 사용하면, 시간초과 나지 않도록 할 수 있음
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

N = int(input())

dp = [-1]*(N+1)

def top_down(n):
    
    if n == 1:
        return 0
    
    if dp[n] != -1:
        return dp[n]
    
    res = top_down(n-1)+1
    
    if n%2 == 0:
        res = min(res, top_down(n//2)+1)
    
    if n%3 == 0:
        res = min(res, top_down(n//3)+1)
    
    dp[n] = res
    return res

print(top_down(N))