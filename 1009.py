T = int(input())
lst = []
for _ in range(T):
    a, b = map(int, input().split())
    result = 1
    for _ in range(b):
        result = (result*a) % 10
    if result == 0:
        result = 10
    lst.append(str(result))
print("\n".join(lst))