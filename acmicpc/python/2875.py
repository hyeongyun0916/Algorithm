import sys
# sys.stdin = open('input.txt', 'r')


n, m, k = map(int, sys.stdin.readline().strip().split())

temp = n+m-k

temp //= 3
n //= 2
print(min(temp, n, m))
