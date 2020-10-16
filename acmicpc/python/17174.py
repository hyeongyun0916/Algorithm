import math
n, m = [int(x) for x in input().split()]

answer = n
while n:
	n = math.floor(n / m)
	answer += n
	# print(n)
print(answer)
