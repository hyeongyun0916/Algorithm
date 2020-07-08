a, b = [int(x) for x in input().split()]
result = 0
cnt = 0
while result != 1:
	result = (result+a)%b
	cnt += 1
print(cnt)