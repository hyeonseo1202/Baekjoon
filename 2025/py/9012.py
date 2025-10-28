import sys
input = sys.stdin.readline

T = int(input())
brackets = [input().strip() for _ in range(T)]  # T개의 괄호 문자열 입력받기

for s in brackets:
    stack = []
    is_vps = True
    for ch in s:
        if ch == '(':
            stack.append(ch)
        else:  # ch == ')'
            if stack:
                stack.pop()
            else:
                is_vps = False
                break
    if stack:
        is_vps = False
    print("YES" if is_vps else "NO")
