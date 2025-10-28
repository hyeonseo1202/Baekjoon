import sys

input = sys.stdin.readline

n = int(input())
stack = []
out = []

for _ in range(n):
    cmd = input().strip()
    if cmd.startswith('push'):
        # 'push X'
        _, x = cmd.split()
        stack.append(int(x))
    elif cmd == 'pop':
        out.append(str(stack.pop()) if stack else '-1')
    elif cmd == 'size':
        out.append(str(len(stack)))
    elif cmd == 'empty':
        out.append('0' if stack else '1')
    elif cmd == 'top':
        out.append(str(stack[-1]) if stack else '-1')

sys.stdout.write('\n'.join(out))
