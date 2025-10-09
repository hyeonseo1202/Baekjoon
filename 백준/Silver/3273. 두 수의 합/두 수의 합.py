n = int(input())
numbers = list(map(int, input().split()))
x = int(input())

numbers.sort()
start, end = 0, n-1
count = 0

while start < end:
    s = numbers[start]+numbers[end]
    if s == x:
        count += 1
        start += 1
        end -= 1 
    elif s < x:
        start += 1 
    else:
        end -= 1
print(count)