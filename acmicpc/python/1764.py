import sys
# sys.stdin = open('input.txt', 'r')


n, m = map(int, sys.stdin.readline().strip().split())

a = set([sys.stdin.readline() for i in range(n)])
b = set([sys.stdin.readline() for i in range(m)])

c = a&b
print(len(c))
for item in sorted(list(c)):
	print(item,end='')