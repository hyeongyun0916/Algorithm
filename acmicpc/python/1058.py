import sys, math
# sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())
arr = [sys.stdin.readline().strip() for i in range(n)]

def is2Friend(a, b):
    for i in range(n):
        if arr[a][i] == arr[b][i] == 'Y':
            return True
    return False


maxVlaue = 0

for i in range(n):
    value = 0
    for j in range(n):
        if arr[i][j] == 'Y':
            value += 1
        elif i != j and is2Friend(i, j):
            value += 1
    maxVlaue = max(maxVlaue, value)

print(maxVlaue)