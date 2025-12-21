#1987 알파벳

import sys
input = sys.stdin.readline
from collections import deque

R, C = map(int, input().split())
graph = [list(input().strip()) for _ in range(R)]

