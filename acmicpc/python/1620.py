import sys
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())
arr = [sys.stdin.readline().strip() for i in range(n)]
d = dict()
for i in range(n):
	d[arr[i]] = i+1
for i in range(m):
	q = sys.stdin.readline().strip()
	if q.isnumeric():
		print(arr[int(q)-1])
	else:
		print(d[q])