# divide and conquer

import sys
# sys.stdin = open('input.txt', 'r')

one = zero = minus = 0

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().strip().split())) for i in range(n)]


def divide(x, y, l):
	global one, zero, minus
	if l == 1:
		if arr[x][y] == 1:
			one += 1
		elif arr[x][y] == 0:
			zero += 1
		else:
			minus += 1
		return arr[x][y]

	l = int(l/3)
	a = divide(x, y, l)
	b = divide(x+l, y, l)
	c = divide(x+2*l, y, l)
	d = divide(x, y+l, l)
	e = divide(x+l, y+l, l)
	f = divide(x+2*l, y+l, l)
	g = divide(x, y+2*l, l)
	h = divide(x+l, y+2*l, l)
	i = divide(x+2*l, y+2*l, l)

	if a==b==c==d==e==f==g==h==i:
		if a == 1:
			one -= 8
		elif a == 0:
			zero -= 8
		elif a == -1:
			minus -= 8
		return a
	
	return 2

divide(0,0,n)
print(minus, zero, one, end='\n')