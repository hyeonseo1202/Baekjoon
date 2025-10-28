import sys
input = sys.stdin.readline

n = int(input())
sequence = [int(input().strip()) for _ in range(n)]

sortedtemp = []
ans = []

m = 1
while m <= n:
    sortedtemp.push(m)
    m+=1
    ans.append('+\n')
    while sequence[m] == stack[-1]:
        sortedtemp.pop()
        ans.append('-\n')
if sortedtemp:
    print(NO)
else: print(ans)
    
