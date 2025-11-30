from collections import deque

N, K = map(int, input().split())

MAX = 100000
visited = [0] * (MAX + 1)

queue = deque([N])

while queue:
    x = queue.popleft()

    if x == K:
        print(visited[x])
        break

    for nx in (x - 1, x + 1, x * 2):
        if 0 <= nx <= MAX and visited[nx] == 0:
            visited[nx] = visited[x] + 1
            queue.append(nx)
