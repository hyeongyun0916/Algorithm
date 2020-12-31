import sys
# sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())
for i in range(n):
    s = sys.stdin.readline().strip()
    isPossible = 0
    for c in s:
        if c == '(':
            isPossible += 1
        else:
            isPossible -= 1
            if isPossible < 0:
                break
    if isPossible == 0:
        print('YES')
    else:
        print('NO')