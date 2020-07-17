maxN = 1000000

fx = [1]*maxN

for i in range(2, maxN+1):
	for j in range(i, maxN+1, i):
		fx[j-1] += i
	
t = int(input())
origin = []
for i in range(t):
	n = int(input())
	origin.append(n)
	# print(sum(fx[:n]))

keys = sorted(origin)
keyValue = dict()
keyValue[keys[0]] = sum(fx[:keys[0]])
for i in range(1,len(keys)):
	keyValue[keys[i]] = sum(fx[keys[i-1]:keys[i]])+keyValue[keys[i-1]]

for i in origin:
	print(keyValue[i])