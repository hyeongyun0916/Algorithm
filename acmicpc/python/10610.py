import sys

s = sys.stdin.readline().strip()

if sum(map(int, list(s))) % 3 == 0 and '0' in list(s):
    print(''.join(sorted(s, reverse=True)))
else:
    print(-1)
