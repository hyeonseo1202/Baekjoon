n = int(input())
numbers = list(map(int, input().split()))


numbers.sort()
start, end = 0, n-1
best = 10**18
ans_l, ans_r = numbers[0],numbers[-1]

while start < end:
    s = numbers[start]+numbers[end]
    
    if abs(s) < best:
        best = abs(s)
        ans_l,ans_r = numbers[start],numbers[end]
        if best == 0:
            break
        
    if s < 0 :
        start += 1
    else:
        end -= 1
        
print(ans_l,ans_r)