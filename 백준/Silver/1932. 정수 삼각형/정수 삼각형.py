import sys
input = sys.stdin.readline

n = int(input())

triangle = [list(map(int, input().split())) for _ in range(n)]

# DP 사용 (triangle 자체를 누적합으로 변경)
for i in range(1, n):
    for j in range(i + 1):
        if j == 0:  # 맨 왼쪽
            triangle[i][j] += triangle[i-1][0]
        elif j == i:  # 맨 오른쪽
            triangle[i][j] += triangle[i-1][j-1]
        else:
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])

print(max(triangle[-1]))
