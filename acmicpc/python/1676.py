n = int(input())

two = 0
five = 0

for i in range(2, n+1):
	while i%2 == 0:
		two += 1
		i /= 2
	while i%5 == 0:
		five += 1
		i /= 5

print(min(two, five))