import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [int(input()) for _ in range(n)]
A.sort()

# m==0이면 답은 항상 0
if m == 0:
    print(0)
    sys.exit(0)

INF = 10**19
ans = INF
left = 0

for right in range(n):
    # left<n 을 먼저 검사해서 A[left] 인덱스 에러 방지 (단락 평가)
    while left < n and A[right] - A[left] >= m:
        diff = A[right] - A[left]
        if diff < ans:
            ans = diff
        left += 1

print(ans)
