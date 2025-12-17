#1463 1로 만들기

#시간초과는 메모이제이션 사용하지 않았기 때문에 발생함!!
# dp배열을 써서 메모이제이션 사용하면, 시간초과 나지 않도록 할 수 있음
import sys
input = sys.stdin.readline

N = int(input())



def top_down(n):
    
    if n == 1:
        return 0
    elif n == 2:
        return 1
    elif n == 3:
        return 1
    
    if n%3 == 0 and n%2 == 0:
        return min(top_down(n//3), top_down(n//2), top_down(n-1))+1
    elif n%3 == 0:
        return min(top_down(n//3), top_down(n-1))+1
    elif n%2 == 0:
        return min(top_down(n//2), top_down(n-1))+1
    else:
        return top_down(n-1)+1

ans = top_down(N)
print(ans)