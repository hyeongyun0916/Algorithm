import sys, math
# sys.stdin = open('input.txt', 'r')

n, a, b = map(int, sys.stdin.readline().strip().split())
answer = 0
while a != b:
    a = math.ceil(a/2)
    b = math.ceil(b/2)
    answer += 1
print(answer)