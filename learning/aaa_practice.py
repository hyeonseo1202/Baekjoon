import sys
input = sys.stdin.readline

n = int(input())

triangle = [list(map(int, input().split())) for _ in range(n)]

# DP 사용 (triangle 자체를 누적합으로 변경)


print(max(triangle[-1]))
