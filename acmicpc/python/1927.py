import heapq

import sys
# sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())

h = []

for _ in range(n):
	temp = int(sys.stdin.readline())
	if temp == 0:
		if len(h) == 0:
			print(0)
		else:
			print(heapq.heappop(h))
	else:
		heapq.heappush(h, temp)