n = int(input())
fx = [1]*n

for i in range(2, n+1):
	for j in range(i, n+1, i):
		fx[j-1] += i
	
print(sum(fx))