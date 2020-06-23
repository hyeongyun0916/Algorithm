import sys
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())

arr = list(map(int, sys.stdin.readline().strip().split()))

sumArr = [0]
sumValue = 0
for a in arr:
    sumValue += a
    sumArr.append(sumValue)

for _ in range(m):
    a, b = map(int, sys.stdin.readline().strip().split())
    print(sumArr[b]-sumArr[a-1])