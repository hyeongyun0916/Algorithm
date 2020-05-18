e, s, m = [int(x) for x in input().split()]
cnt = 0
value = 28*cnt+s
while not ((value-e)%15 is 0) or not ((value-m)%19 is 0):
	cnt +=1
	value = 28*cnt+s

print(value)