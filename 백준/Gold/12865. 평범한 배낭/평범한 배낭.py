#12865 평범한 배낭

import sys
input =  sys.stdin.readline
N, K = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(N)]
    
dp = [0] * (K+1)

for w, v in items:
    for cap in range(K, w - 1, -1): # 뒤에서 앞으로!
        dp[cap] = max(dp[cap], dp[cap - w] + v)

print(dp[K])